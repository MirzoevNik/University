package ourfinances;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.chart.CategoryAxis;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.SelectionMode;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;

public class CurrentData extends BorderPane
{
    private final Menu parent;
    private final CurrentData current_data;
    
    private VBox datas_pane;
    private VBox statistics_pane;
    private GridPane finances_labels_pane;
    private StackPane graphics_pane;
    private StackPane menu_pane;
    private VBox add_income_list_pane;
    private VBox add_spending_list_pane;
    
    private final MonthFinances current_month_finances;
    
    private String new_income;
    private double new_value_income;
    private String new_spending;
    private double new_value_spending;
    
    private XYChart.Series series_incomes;
    private XYChart.Series series_spending;
    
    public CurrentData(Menu parent, MonthFinances current_month)
    {
        this.parent = parent;
        this.current_month_finances = current_month;
        this.current_data = this;
        
        createDatasPane();
        createStatisticsPane();
        createMenuPane();
        
        this.setLeft(datas_pane);
        this.setCenter(statistics_pane);
        this.setBottom(menu_pane);
    }
    
    private void createDatasPane()
    {
        datas_pane = new VBox();
        
        Font font = new Font("Courier", 23);
        Font font2 = new Font("Courier", 13);
        
        Label incomes_label = new Label("Доходы");
        incomes_label.setFont(font);
        
        final TableView <Finance> incomes_table = new TableView <>();
        incomes_table.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        
        TableColumn income_col = new TableColumn("Доход");
        income_col.setMinWidth(166);
        income_col.setCellValueFactory( new PropertyValueFactory <>("name") );
        TableColumn summa_income_col = new TableColumn("Сумма");
        summa_income_col.setCellValueFactory( new PropertyValueFactory <>("value") );
        incomes_table.getColumns().addAll(income_col, summa_income_col);
        
        ObservableList<Finance> data_incomes = FXCollections.observableArrayList(current_month_finances.getIncomes());
        incomes_table.setItems(data_incomes);
        
        HBox add_del_income_pane = new HBox(); 
        Button add_income_button = new Button();
        add_income_button.setText("Добавить доход");
        add_income_button.setFont(font2);
        add_del_income_pane.getChildren().add(add_income_button);
        add_income_button.setOnAction(new EventHandler <ActionEvent>() 
        {
            @Override
            public void handle(ActionEvent event) 
            {
                current_data.statistics_pane.getChildren().remove(graphics_pane);
                current_data.statistics_pane.getChildren().remove(add_income_list_pane);
                current_data.statistics_pane.getChildren().remove(add_spending_list_pane);
                
                createAddIncomeListPane();
                
                current_data.statistics_pane.getChildren().add(add_income_list_pane);
            }
        });
        
        add_del_income_pane.setSpacing(10);
        
        Button del_income_button = new Button();
        del_income_button.setText("Удалить доход");
        del_income_button.setFont(font2);
        add_del_income_pane.getChildren().add(del_income_button);
        del_income_button.setOnAction(new EventHandler <ActionEvent>() 
        {
            @Override
            public void handle(ActionEvent event) 
            {
                if ( incomes_table.getSelectionModel().isEmpty() == false )
                {
                    data_incomes.remove(incomes_table.getSelectionModel().getSelectedIndex());
                    current_month_finances.deleteIncome(incomes_table.getSelectionModel().getSelectedIndex());
                    incomes_table.getSelectionModel().clearSelection();
                    save();
                }
            }
        });
        
        add_del_income_pane.setAlignment(Pos.CENTER);
        
        ///
        
        Label spending_label = new Label("Расходы");
        spending_label.setFont(font);
        
        final TableView <Finance> spending_table = new TableView <>();
        
        TableColumn spending_col = new TableColumn("Расход");
        spending_col.setMinWidth(166);
        spending_col.setCellValueFactory( new PropertyValueFactory <>("name") );
        TableColumn summa_spending_col = new TableColumn("Сумма");
        summa_spending_col.setCellValueFactory( new PropertyValueFactory <>("value") );
        spending_table.getColumns().addAll(spending_col, summa_spending_col);
        
        ObservableList<Finance> data_spending = FXCollections.observableArrayList(current_month_finances.getSpending());
        spending_table.setItems(data_spending);
        
        HBox add_del_spending_pane = new HBox(); 
        Button add_spending_button = new Button();
        add_spending_button.setText("Добавить расход");
        add_spending_button.setFont(font2);
        add_del_spending_pane.getChildren().add(add_spending_button);
        add_spending_button.setOnAction(new EventHandler <ActionEvent>() 
        {
            @Override
            public void handle(ActionEvent event) 
            {
                current_data.statistics_pane.getChildren().remove(graphics_pane);
                current_data.statistics_pane.getChildren().remove(add_spending_list_pane);
                current_data.statistics_pane.getChildren().remove(add_income_list_pane);
                
                createAddSpendingListPane();
                
                current_data.statistics_pane.getChildren().add(add_spending_list_pane);
            }
        });
        
        add_del_spending_pane.setSpacing(10);
        
        Button del_spending_button = new Button();
        del_spending_button.setText("Удалить расход");
        del_spending_button.setFont(font2);
        add_del_spending_pane.getChildren().add(del_spending_button);
        del_spending_button.setOnAction(new EventHandler <ActionEvent>() 
        {
            @Override
            public void handle(ActionEvent event) 
            {
                if ( spending_table.getSelectionModel().isEmpty() == false )
                {                    
                    current_month_finances.deleteSpending( spending_table.getSelectionModel().getSelectedIndex() );
                    data_spending.remove( spending_table.getSelectionModel().getSelectedIndex() );
                    spending_table.getSelectionModel().clearSelection();                
                    save();
                }
            }
        });
        
        add_del_spending_pane.setAlignment(Pos.CENTER);
        
        datas_pane.setPadding(new Insets(0, 0, 0, 50));
        datas_pane.getChildren().add(incomes_label);
        datas_pane.getChildren().add(incomes_table);
        datas_pane.getChildren().add(add_del_income_pane);
        datas_pane.setSpacing(5);
        datas_pane.getChildren().add(spending_label);
        datas_pane.getChildren().add(spending_table);
        datas_pane.getChildren().add(add_del_spending_pane);
    }
    
    private void createStatisticsPane()
    {
        statistics_pane = new VBox();
        
        createFinancesLabelsPane();
        
        Font font = new Font("Courier", 25);
        Font font2 = new Font("Courier", 50);
        Font font3 = new Font("Courier", 18);
        
        Label current_date_for_summa_label = new Label("Общая сумма за месяц");
        current_date_for_summa_label.setFont(font);
        
        Label current_date_summa_label = new Label("" + current_month_finances.getSummaFinances());
        current_date_summa_label.setFont(font2);
        
        String current_date_string = "";
        switch(current_month_finances.getMonth())
        {
            case 1: {current_date_string = "январь "; break;}
            case 2: {current_date_string = "февраль "; break;}
            case 3: {current_date_string = "март "; break;}
            case 4: {current_date_string = "апрель "; break;}
            case 5: {current_date_string = "май "; break;}
            case 6: {current_date_string = "июнь "; break;}
            case 7: {current_date_string = "июль "; break;}
            case 8: {current_date_string = "август "; break;}
            case 9: {current_date_string = "сентябрь "; break;}
            case 10: {current_date_string = "октябрь "; break;}
            case 11: {current_date_string = "ноябрь "; break;}
            case 12: {current_date_string = "декабрь "; break;}
        }
        Label current_date_label = new Label(current_date_string + current_month_finances.getYear());
        current_date_label.setFont(font3);
        
        createGraphicsPane();
        
        statistics_pane.getChildren().add(current_date_for_summa_label);
        statistics_pane.getChildren().add(current_date_summa_label);
        statistics_pane.getChildren().add(current_date_label);
        statistics_pane.getChildren().add(finances_labels_pane);
        statistics_pane.setSpacing(10);
        statistics_pane.getChildren().add(graphics_pane);
        statistics_pane.setAlignment(Pos.TOP_CENTER);
    }
    
    private void createFinancesLabelsPane()
    {
        finances_labels_pane = new GridPane();
        
        Font font = new Font("Courier", 20);
        Font font2 = new Font("Courier", 35);
        
        Label incomes_label = new Label("Суммарный доход");
        incomes_label.setFont(font);
        incomes_label.setAlignment(Pos.CENTER);
        
        Label incomes_summa_label = new Label("" + current_month_finances.getSummaIncomes());
        incomes_summa_label.setFont(font2);
        incomes_summa_label.setAlignment(Pos.CENTER);
        
        Label spending_label = new Label("Суммарный расход");
        spending_label.setFont(font);
        spending_label.setAlignment(Pos.CENTER);
        
        Label spending_summa_label = new Label("" + current_month_finances.getSummaSpending());
        spending_summa_label.setFont(font2);
        spending_summa_label.setAlignment(Pos.CENTER);
        
        finances_labels_pane.setHgap(50);
        finances_labels_pane.add(incomes_label, 0, 0);
        finances_labels_pane.add(incomes_summa_label, 0, 1);
        finances_labels_pane.add(spending_label, 1, 0);
        finances_labels_pane.add(spending_summa_label, 1, 1);
        finances_labels_pane.setHalignment(incomes_label, HPos.CENTER);
        finances_labels_pane.setHalignment(spending_label, HPos.CENTER);
        finances_labels_pane.setHalignment(incomes_summa_label, HPos.CENTER);
        finances_labels_pane.setHalignment(spending_summa_label, HPos.CENTER);
        finances_labels_pane.setAlignment(Pos.TOP_CENTER);
    }
    
    private void createGraphicsPane()
    {
        graphics_pane = new StackPane();
        
        final CategoryAxis x_months = new CategoryAxis();
        final NumberAxis y_finanances = new NumberAxis();
        x_months.setLabel("Месяц");
        final LineChart <String,Number> finances_chart = new LineChart <String,Number>(x_months, y_finanances);
       
        finances_chart.setTitle("Статистика финансов за год");
                          
        series_incomes = new XYChart.Series();
        series_incomes.setName("Доходы");
        
        series_spending = new XYChart.Series();
        series_spending.setName("Расходы");
        
        createGraphic();
                
        finances_chart.getData().addAll(series_incomes, series_spending);
        
        graphics_pane.getChildren().add(finances_chart);
        graphics_pane.setAlignment(Pos.TOP_CENTER);
    }
    
    private void createMenuPane()
    {
        menu_pane = new StackPane();
        
        Font font = new Font("Courier", 17);
        
        Button menu_button = new Button();
        menu_button.setText("Перейти в меню");
        menu_button.setFont(font);
        menu_button.setOnAction(new EventHandler <ActionEvent>() 
        {
            @Override
            public void handle(ActionEvent event) 
            {
                parent.createMenu(current_data);
            }
        });
        
        menu_pane.setPadding(new Insets(10, 0, 10, 0));
        menu_pane.getChildren().add(menu_button);
    }
    
    private void createAddIncomeListPane()
    {
        add_income_list_pane = new VBox();
        
        Font font = new Font("Courier", 17);
        Font font2 = new Font("Courier", 15);
        
        GridPane add_income_data_pane = new GridPane();
        
        add_income_data_pane.setHgap(15);
        add_income_data_pane.setVgap(10);
        
        Label label_income = new Label("Доход: ");
        label_income.setFont(font);
        
        Label label_value = new Label("Сумма: ");
        label_value.setFont(font);
        
        TextField text_income = new TextField("");
        text_income.setPromptText("Введите доход");
        text_income.setMinWidth(30);
        text_income.setMaxWidth(97);
        
        text_income.textProperty().addListener( (observable, oldValue, newValue) -> 
        {
            try 
            {
                new_income = text_income.getText().toString();
            }
            catch(NumberFormatException exc)
            {
                return;
            }
        });
        
        TextField text_value = new TextField("");
        text_value.setPromptText("Введите сумму");
        text_value.setMinWidth(30);
        text_value.setMaxWidth(97);
        
        text_value.textProperty().addListener( (observable, oldValue, newValue) -> 
        {
            try 
            {
                new_value_income = Double.parseDouble(text_value.getText());
            }
            catch(NumberFormatException exc)
            {
                return;
            }
        });
        
        add_income_data_pane.add(label_income, 0, 0);
        add_income_data_pane.add(label_value, 0, 1);
        add_income_data_pane.add(text_income, 1, 0);
        add_income_data_pane.add(text_value, 1, 1);
        add_income_data_pane.setAlignment(Pos.BOTTOM_CENTER);
        
        Button add_income_list_button = new Button();
        add_income_list_button.setText("Добавить доход");
        add_income_list_button.setFont(font2);
        add_income_list_button.setOnAction(new EventHandler <ActionEvent>() 
        {
            @Override
            public void handle(ActionEvent event) 
            {
                final Finance new_finance_income = new Finance(new_income, new_value_income);
                
                current_month_finances.addIncome(new_finance_income);
                
                save();
            }
        });
        
        add_income_list_pane.getChildren().add(add_income_data_pane);
        add_income_list_pane.setSpacing(20);
        add_income_list_pane.getChildren().add(add_income_list_button);
        add_income_list_pane.setAlignment(Pos.BOTTOM_CENTER);
    }
    
    private void createAddSpendingListPane()
    {
        add_spending_list_pane = new VBox();
        
        Font font = new Font("Courier", 17);
        Font font2 = new Font("Courier", 15);
        
        GridPane add_spending_data_pane = new GridPane();
        
        add_spending_data_pane.setHgap(15);
        add_spending_data_pane.setVgap(10);
        
        Label label_spending = new Label("Расход: ");
        label_spending.setFont(font);
        
        Label label_value = new Label("Сумма: ");
        label_value.setFont(font);
        
        TextField text_spending = new TextField("");
        text_spending.setPromptText("Введите расход");
        text_spending.setMinWidth(30);
        text_spending.setMaxWidth(97);
        
        text_spending.textProperty().addListener( (observable, oldValue, newValue) -> 
        {
            try 
            {
                new_spending = text_spending.getText().toString();
            }
            catch(NumberFormatException exc)
            {
                return;
            }
        });
        
        TextField text_value = new TextField("");
        text_value.setPromptText("Введите сумму");
        text_value.setMinWidth(30);
        text_value.setMaxWidth(97);
        
        text_value.textProperty().addListener( (observable, oldValue, newValue) -> 
        {
            try 
            {
                new_value_spending = Double.parseDouble(text_value.getText());
            }
            catch(NumberFormatException exc)
            {
                return;
            }
        });
        
        add_spending_data_pane.add(label_spending, 0, 0);
        add_spending_data_pane.add(label_value, 0, 1);
        add_spending_data_pane.add(text_spending, 1, 0);
        add_spending_data_pane.add(text_value, 1, 1);
        add_spending_data_pane.setAlignment(Pos.BOTTOM_CENTER);
        
        Button add_spending_list_button = new Button();
        add_spending_list_button.setText("Добавить расход");
        add_spending_list_button.setFont(font2);
        add_spending_list_button.setOnAction(new EventHandler <ActionEvent>() 
        {
            @Override
            public void handle(ActionEvent event) 
            {
                final Finance new_finance_spending = new Finance(new_spending, new_value_spending);
                
                current_month_finances.addSpending(new_finance_spending);
                
                save();
            }
        });
        
        add_spending_list_pane.getChildren().add(add_spending_data_pane);
        add_spending_list_pane.setSpacing(20);
        add_spending_list_pane.getChildren().add(add_spending_list_button);
        add_spending_list_pane.setAlignment(Pos.BOTTOM_CENTER);
    }
    
    private void save()
    {
        try
        {
            String file = "" + current_month_finances.getMonth() + "_" + current_month_finances.getYear() + ".ser";
            FileOutputStream fs = new FileOutputStream(file);
            ObjectOutputStream os = new ObjectOutputStream(fs);
            os.writeObject(current_month_finances);
            os.close();
        }
        catch(Exception ex)
        {
            ex.printStackTrace();
        }
        
        CurrentFinance cur_fin = new CurrentFinance();//current_data.parent.getCurrentFinance();
        /*int last_month = this.current_month_finances.getMonth() - 2;
        int last_year = this.current_month_finances.getYear();
        if (last_month < 1)
        {
            last_month += 12;
            last_year--;
        }
        //if (cur_fin.getLastYear() == 1 || cur_fin.getLastMonth() == last_month && cur_fin.getLastYear() == last_year)
        //{
            last_month++;
            if (last_month == 13)
            {
                last_month = 1;
                last_year++;
            }
            
            MonthFinances last_month_finances = new MonthFinances(last_month, last_year);
            
            if (last_month == 11 && last_year == 2015)
            {
                try
        {
            String file = "" + (last_month - 2) + "_" + last_year + ".ser";
            FileOutputStream fs = new FileOutputStream(file);
            ObjectOutputStream os = new ObjectOutputStream(fs);
            os.writeObject(current_month_finances);
            os.close();
        }
        catch(Exception ex)
        {
            ex.printStackTrace();
        }
            }
        
                       
            cur_fin.setLastMonth(last_month);
            cur_fin.setLastYear(last_year);
            cur_fin.setCurrentSumma( cur_fin.getCurrentSumma() + last_month_finances.getSummaFinances() );
            */
            try
            {
                FileOutputStream fs = new FileOutputStream("current_finance.ser");
                ObjectOutputStream os = new ObjectOutputStream(fs);
                os.writeObject(cur_fin);
                os.close();
            }
            catch(Exception ex)
            {
                ex.printStackTrace();
            }
        //}
        
        createDatasPane();
        createStatisticsPane();

        current_data.setLeft(datas_pane);
        current_data.setCenter(statistics_pane);

        current_data.parent.changeCurrentBalance();
    }
    
    private void createGraphic()
    {
        int month = current_month_finances.getMonth() + 1;
        int year = current_month_finances.getYear() - 1;
        if (month == 13)
        {
            month = 1;
            year++;
        }
                
        for (int i = 0 ; i < 12; i++)
        {
            MonthFinances month_finances_for_graphic = new MonthFinances(month, year);
        
            try
            {
                String file = "" + month + "_" + year + ".ser";
                FileInputStream fs = new FileInputStream(file);    
                ObjectInputStream os = new ObjectInputStream(fs);

                month_finances_for_graphic = (MonthFinances) os.readObject();

                os.close();
            }
            catch(Exception ex)
            {
                ex.printStackTrace();
            }
            
            String date_string_for_graphic = "";
            switch(month)
            {
                case 1: {date_string_for_graphic = "Янв"; break;}
                case 2: {date_string_for_graphic = "Фев"; break;}
                case 3: {date_string_for_graphic = "Мар"; break;}
                case 4: {date_string_for_graphic = "Апр"; break;}
                case 5: {date_string_for_graphic = "Май"; break;}
                case 6: {date_string_for_graphic = "Июн"; break;}
                case 7: {date_string_for_graphic = "Июл"; break;}
                case 8: {date_string_for_graphic = "Авг"; break;}
                case 9: {date_string_for_graphic = "Сен"; break;}
                case 10: {date_string_for_graphic = "Окт"; break;}
                case 11: {date_string_for_graphic = "Ноя"; break;}
                case 12: {date_string_for_graphic = "Дек"; break;}
            }
            
            series_incomes.getData().add(new XYChart.Data(date_string_for_graphic, month_finances_for_graphic.getSummaIncomes()));
            series_spending.getData().add(new XYChart.Data(date_string_for_graphic, month_finances_for_graphic.getSummaSpending()));
            
            month++;
            if (month == 13)
            {
                month = 1;
                year++;
            }
        }
    }
    
}
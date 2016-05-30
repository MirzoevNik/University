package ourfinances;

import java.util.ArrayList;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.chart.PieChart;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;


public class SelectDate extends BorderPane
{
    private final Menu parent;
    private final SelectDate select_date;
    
    private VBox datas_pane;
    private VBox statistics_pane;
    private GridPane graphics_pane;
    private StackPane menu_pane;
    
    private final MonthFinances select_month_finances;
    
    SelectDate(Menu parent, MonthFinances select_month)
    {
        this.parent = parent;
        this.select_month_finances = select_month;
        this.select_date = this;
        
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
        
        Label incomes_label = new Label("Доходы");
        incomes_label.setFont(font);
        
        final TableView <Finance> incomes_table = new TableView <>();
        
        TableColumn income_col = new TableColumn("Доход");
        income_col.setMinWidth(166);
        income_col.setCellValueFactory( new PropertyValueFactory <>("name") );
        TableColumn summa_income_col = new TableColumn("Сумма");
        summa_income_col.setCellValueFactory( new PropertyValueFactory <>("value") );
        incomes_table.getColumns().addAll(income_col, summa_income_col);
        
        ObservableList<Finance> data_incomes = FXCollections.observableArrayList(select_month_finances.getIncomes());
        incomes_table.setItems(data_incomes);
        
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
        
        ObservableList<Finance> data_spending = FXCollections.observableArrayList(select_month_finances.getSpending());
        spending_table.setItems(data_spending);
        
        //////////////////////////////////////
        
        //final TreeTableView <Finance> incomes_table = new TreeTableView <>();
        
        //final TreeItem<Finance> childNode1 = new TreeItem<>("Работа", "10000" );
        //final TreeItem<Finance> childNode2 = new TreeItem<>("Child Node 2");
        //final TreeItem<Finance> childNode3 = new TreeItem<>("Child Node 3");
        
        /////////////////////////////////////
        
        datas_pane.setPadding(new Insets(0, 0, 0, 50));
        datas_pane.getChildren().add(incomes_label);
        datas_pane.getChildren().add(incomes_table);
        datas_pane.setSpacing(5);
        datas_pane.getChildren().add(spending_label);
        datas_pane.getChildren().add(spending_table);
    }
    
    private void createStatisticsPane()
    {
        statistics_pane = new VBox();
        
        createGraphicsPane();
        
        Font font = new Font("Courier", 25);
        Font font2 = new Font("Courier", 50);
        Font font3 = new Font("Courier", 18);
        
        Label select_date_for_summa_label = new Label("Общая сумма за месяц");
        select_date_for_summa_label.setFont(font);
        
        Label select_date_summa_label = new Label("" + select_month_finances.getSummaFinances());
        select_date_summa_label.setFont(font2);
        
        String select_date_string = "";
        switch(select_month_finances.getMonth())
        {
            case 1: {select_date_string = "январь "; break;}
            case 2: {select_date_string = "февраль "; break;}
            case 3: {select_date_string = "март "; break;}
            case 4: {select_date_string = "апрель "; break;}
            case 5: {select_date_string = "май "; break;}
            case 6: {select_date_string = "июнь "; break;}
            case 7: {select_date_string = "июль "; break;}
            case 8: {select_date_string = "август "; break;}
            case 9: {select_date_string = "сентябрь "; break;}
            case 10: {select_date_string = "октябрь "; break;}
            case 11: {select_date_string = "ноябрь "; break;}
            case 12: {select_date_string = "декабрь "; break;} 
        }
        Label select_date_label = new Label(select_date_string + select_month_finances.getYear());
        select_date_label.setFont(font3);
        
        statistics_pane.getChildren().add(select_date_for_summa_label);
        statistics_pane.getChildren().add(select_date_summa_label);
        statistics_pane.getChildren().add(select_date_label);
        statistics_pane.getChildren().add(graphics_pane);
        statistics_pane.setAlignment(Pos.TOP_CENTER);
    }
    
    private void createGraphicsPane()
    {
        graphics_pane = new GridPane();
        
        Font font = new Font("Courier", 20);
        Font font2 = new Font("Courier", 35);
        
        Label incomes_label = new Label("Суммарный доход");
        incomes_label.setFont(font);
        incomes_label.setAlignment(Pos.CENTER);
        
        Label incomes_summa_label = new Label("" + select_month_finances.getSummaIncomes());
        incomes_summa_label.setFont(font2);
        incomes_summa_label.setAlignment(Pos.CENTER);
        
        Label spending_label = new Label("Суммарный расход");
        spending_label.setFont(font);
        spending_label.setAlignment(Pos.CENTER);
        
        Label spending_summa_label = new Label("" + select_month_finances.getSummaSpending());
        spending_summa_label.setFont(font2);
        spending_summa_label.setAlignment(Pos.CENTER);
        
        ArrayList income_data = getDataStatistic(select_month_finances.getIncomes(), select_month_finances.getSummaIncomes());
        ObservableList<PieChart.Data> incomes_chart_data = FXCollections.observableArrayList( income_data );
        PieChart incomes_chart = new PieChart(incomes_chart_data);
        incomes_chart.setLabelsVisible(false);
        
        ArrayList spending_data = getDataStatistic(select_month_finances.getSpending(), select_month_finances.getSummaSpending());
        ObservableList<PieChart.Data> spending_chart_data = FXCollections.observableArrayList( spending_data );
        PieChart spending_chart = new PieChart(spending_chart_data);
        spending_chart.setLabelsVisible(false);
        
        graphics_pane.setHgap(5);
        graphics_pane.add(incomes_label, 0, 0);
        graphics_pane.add(incomes_summa_label, 0, 1);
        graphics_pane.add(spending_label, 1, 0);
        graphics_pane.add(spending_summa_label, 1, 1);
        graphics_pane.add(incomes_chart, 0, 2);
        graphics_pane.add(spending_chart, 1, 2);
        graphics_pane.setHalignment(incomes_label, HPos.CENTER);
        graphics_pane.setHalignment(spending_label, HPos.CENTER);
        graphics_pane.setHalignment(incomes_summa_label, HPos.CENTER);
        graphics_pane.setHalignment(spending_summa_label, HPos.CENTER);
        graphics_pane.setAlignment(Pos.CENTER_LEFT);
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
                parent.createMenu(select_date);
            }
        });
        
        menu_pane.setPadding(new Insets(10, 0, 10, 0));
        menu_pane.getChildren().add(menu_button);
    }
    
    private ArrayList<PieChart.Data> getDataStatistic(ArrayList <Finance> finances, double summa)
    {
        ArrayList<PieChart.Data> data = new ArrayList<PieChart.Data>();
        if (finances.size() > 5)
        {
            int percents = 0; 
            for (int i = 0; i < 4; i++)
            {
                Finance finance = finances.get(i);
                String name = finance.getName();
                double value = finance.getValue();
                int k = 100 * (int)value / (int)summa;
                PieChart.Data newData = new PieChart.Data( name, k );
                data.add(newData);
                percents += k;
            }
            data.add(new PieChart.Data("Остальное", 100 - percents));
        }
        else
        {
            if (finances.isEmpty())
            {
                data.add(new PieChart.Data("Нет статистики", 100));
            }
            else
            {
                for (int i = 0; i < finances.size(); i++)
                {
                    Finance finance = finances.get(i);
                    String name = finance.getName();
                    double value = finance.getValue();
                    PieChart.Data newData = new PieChart.Data( name, ( 100 * (int)value / (int)summa) );
                    data.add(newData);
                }
            }
        }
        return data;
    }

}

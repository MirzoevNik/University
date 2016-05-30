package ourfinances;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.GregorianCalendar;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.SelectionMode;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class Menu extends Stage
{
    private final BorderPane main_pane;
    private HBox balance_pane;
    private VBox date_pane;
    private GridPane select_date_pane;
    private GridPane enter_date_pane;
    private VBox current_data_pane;
    
    private final Menu menu;
    
    private CurrentFinance current_finance;
    
    private MonthFinances current_month_finances;
    private Calendar calendar;
    
    private int select_month;
    private int select_year;
    
    private ListView <String> list_dates;
    private TextField text_month;
    private TextField text_year;
    
    public Menu ()
    {
        this.menu = this;
        main_pane = new BorderPane();
        
        select_month = 0;
        select_year = 0;
        
        createCurrentMonthFinances();
        //createCurrentFinance();
        this.current_finance = new CurrentFinance();
        try
            {
                FileOutputStream fs2 = new FileOutputStream("current_finance.ser");
                ObjectOutputStream os2 = new ObjectOutputStream(fs2);
                os2.writeObject(this.current_finance);
                os2.close();
            }
            catch(Exception ex)
            {
                ex.printStackTrace();
            }
        
        createBalancePane(current_month_finances.getSummaIncomes() - current_month_finances.getSummaSpending());
        main_pane.setTop(balance_pane);
        
        createDatePane();
        main_pane.setCenter(date_pane);
        
        Scene scene = new Scene(main_pane, 750, 600);
        
        this.setTitle("OurFinances");
        this.setScene(scene);
        this.setMaximized(true);
        //this.show();
    }
    
    private void createBalancePane(double balance)
    {
        balance_pane = new HBox();
        
        Font font = new Font("Courier", 35);
		
	String for_label_balance = "БАЛАНС: " + current_finance.getCurrentSumma() + balance + " рублей";
        
        Label label_balance = new Label(for_label_balance);
        label_balance.setFont(font);

        balance_pane.setPadding(new Insets(15, 0, 5, 0));
        balance_pane.getChildren().add(label_balance);
        balance_pane.setAlignment(Pos.CENTER);
    }
    
    private void createDatePane()
    {
        this.select_month = 0;
        this.select_year = 0;
        
        date_pane = new VBox();
        
        date_pane.setSpacing(70);
                
        createSelectDatePane();
        date_pane.getChildren().add(select_date_pane);
        
        createCurrentDataPane();
        date_pane.getChildren().add(current_data_pane);
        
        date_pane.setAlignment(Pos.CENTER);
    }
    
    private void createSelectDatePane()
    {
        select_date_pane = new GridPane();
        select_date_pane.setHgap(70);
        
        Font font = new Font("Courier", 23);
        
        Label label_enter = new Label("   Введите дату");
        label_enter.setFont(font);
        
        Label label_or = new Label("или");
	label_or.setFont(font);
        
        Label label_list = new Label("  выберите из списка");
	label_list.setFont(font);
        
        createEnterDatePane();
        
        Font font2 = new Font("Courier", 20);
        
        list_dates = new ListView <>();
        list_dates.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        ObservableList <String> dates = FXCollections.observableArrayList(fiveMonths());
        list_dates.setItems(dates);
        list_dates.setPrefSize(200, 118);
        list_dates.getSelectionModel().selectedItemProperty().addListener((observableValue, oldValue, newValue) ->
        {
            this.select_month = 0;
            this.select_year = 0;
            
            text_month.setText("");
            text_year.setText("");
        });
        
        Font font3 = new Font("Courier", 17);
        
        Button go_to_selected_date_button = new Button("Перейти к выбранной дате");
        go_to_selected_date_button.setFont(font3);
        go_to_selected_date_button.setOnAction(new EventHandler <ActionEvent>() 
        {
            @Override
            public void handle(ActionEvent event)
            {
                if ( (select_month == 0 || select_year == 0) && list_dates.getSelectionModel().isEmpty() == false )
                {
                    changeSelectedDate( list_dates.getSelectionModel().getSelectedIndex() );
                }
                
                if (select_month == 0 || select_year == 0)
                {
                    return;
                }
                
                main_pane.getChildren().remove(date_pane);
                
                MonthFinances select_month_finances = openSelectMonthFinances(select_month, select_year);
                
                BorderPane datas_pane = new SelectDate(menu, select_month_finances);
                main_pane.setCenter(datas_pane);
            }
        });
        
        select_date_pane.setPadding(new Insets(0, 0, 0, 100));
        select_date_pane.add(label_enter, 0, 0);
        select_date_pane.add(label_or, 1, 0);
        select_date_pane.add(label_list, 2, 0);
        select_date_pane.setVgap(15);
        select_date_pane.add(enter_date_pane, 0, 1);
        select_date_pane.add(list_dates, 2, 1);
        select_date_pane.add(go_to_selected_date_button, 2, 2);
        select_date_pane.setPadding(new Insets(0, 0, 0, 0));
        select_date_pane.setAlignment(Pos.TOP_CENTER);
        select_date_pane.setPadding(new Insets(0, 0, 70, 0));
    }
    
    private void createEnterDatePane()
    {
        enter_date_pane = new GridPane();
        enter_date_pane.setHgap(15);
        enter_date_pane.setVgap(10);
        
        Font font = new Font("Courier", 17);
        
        Label label_month = new Label("Месяц: ");
        label_month.setFont(font);
        
        Label label_year = new Label("Год: ");
        label_year.setFont(font);
        
        //ObservableList <String> months = FXCollections.observableArrayList( "", "январь", "февраль", "март", "апрель", "май", "июнь", "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь" );
        text_month = new TextField("");
        text_month.setPromptText("Введите месяц");
        text_month.setMinWidth(30);
        text_month.setMaxWidth(97);
        
        text_month.textProperty().addListener( (observable, oldValue, newValue) -> 
        {                     
            String month = text_month.getText();
            switch (month) {
                case "январь":
                case "Январь":
                case "ЯНВАРЬ":
                case "1":
                case "01":
                    month = "1";
                    break;
                case "февраль":
                case "Февраль":
                case "ФЕВРАЛЬ":
                case "2":
                case "02":
                    month = "2";
                    break;
                case "март":
                case "Март":
                case "МАРТ":
                case "3":
                case "03":
                    month = "3";
                    break;
                case "апрель":
                case "Апрель":
                case "АПРЕЛЬ":
                case "4":
                case "04":
                    month = "4";
                    break;
                case "май":
                case "Май":
                case "МАЙ":
                case "5":
                case "05":
                    month = "5";
                    break;
                case "июнь":
                case "Июнь":
                case "ИЮНЬ":
                case "6":
                case "06":
                    month = "6";
                    break;
                case "июль":
                case "Июль":
                case "ИЮЛЬ":
                case "7":
                case "07":
                    month = "7";
                    break;
                case "август":
                case "Август":
                case "АВГУСТ":
                case "8":
                case "08":
                    month = "8";
                    break;
                case "сентябрь":
                case "Сентябрь":
                case "СЕНТЯБРЬ":
                case "9":
                case "09":
                    month = "9";
                    break;
                case "октябрь":
                case "Октябрь":
                case "ОКТЯБРЬ":
                case "10":
                    month = "10";
                    break;
                case "ноябрь":
                case "Ноябрь":
                case "НОЯБРЬ":
                case "11":
                    month = "11";
                    break;
                case "декабрь":
                case "Декабрь":
                case "ДЕКАБРЬ":
                case "12":
                    month = "12";
                    break;
                default:
                    return;
                    
            }
            menu.select_month = Integer.parseInt(month);
            list_dates.getSelectionModel().clearSelection();
        });
        
        //ObservableList <String> years = FXCollections.observableArrayList( "", "2015", "2014", "2013", "2012", "2011", "2010", "2009" );
        text_year = new TextField("");
        text_year.setPromptText("Введите год");
        text_year.setMinWidth(30);
        text_year.setMaxWidth(97);
        
        text_year.textProperty().addListener( (observable, oldValue, newValue) -> 
        {
            try 
            {
                menu.select_year = Integer.parseInt(text_year.getText());
                list_dates.getSelectionModel().clearSelection();
            }
            catch(NumberFormatException exc)
            {
                return;
            }
        });
        
        enter_date_pane.add(label_month, 0, 0);
        enter_date_pane.add(label_year, 0, 1);
        enter_date_pane.add(text_month, 1, 0);
        enter_date_pane.add(text_year, 1, 1);
    }
    
    private void createCurrentDataPane()
    {
        current_data_pane = new VBox();
        
        Font font = new Font("Courier", 23);
        Font font2 = new Font("Courier", 17);
        
        String today = "Сегодня " + calendar.get(Calendar.DATE) + "." + current_month_finances.getMonth() + "." + current_month_finances.getYear();

        Label label_today = new Label(today);
        label_today.setFont(font);

        Button go_to_current_data = new Button("Посмотреть и отредактировать текущие данные");
        go_to_current_data.setFont(font2);
        go_to_current_data.setOnAction(new EventHandler <ActionEvent>() 
        {
            @Override
            public void handle(ActionEvent event) 
            {
                main_pane.getChildren().remove(date_pane);
                
                BorderPane datas_pane = new CurrentData(menu, current_month_finances);
                main_pane.setCenter(datas_pane);
            }
        });

        current_data_pane.getChildren().add(label_today);
        
        current_data_pane.setSpacing(10);

        current_data_pane.getChildren().add(go_to_current_data);
        
        current_data_pane.setAlignment(Pos.TOP_CENTER);
    }
    
    public void createMenu(BorderPane old_pane)
    {
        main_pane.getChildren().remove(old_pane);
        createDatePane();
        main_pane.setCenter(date_pane);
    }
    
    private void createCurrentMonthFinances()
    {
        calendar = new GregorianCalendar().getInstance();
        int month = calendar.get(Calendar.MONTH) + 1;
        int year = calendar.get(Calendar.YEAR);
        
        this.current_month_finances = new MonthFinances(month, year);
        
        try
        {
            String file = "" + month + "_" + year + ".ser";
            FileInputStream fs = new FileInputStream(file);    
            ObjectInputStream os = new ObjectInputStream(fs);
        
            this.current_month_finances = (MonthFinances) os.readObject();
            
            os.close();
        }
        catch(Exception ex)
        {
            ex.printStackTrace();
        }
    }
    
    private void createCurrentFinance()
    {
        this.current_finance = new CurrentFinance();
        /*
        try
        {
            FileInputStream fs = new FileInputStream("current_finance.ser");    
            ObjectInputStream os = new ObjectInputStream(fs);
        
            this.current_finance = (CurrentFinance) os.readObject();
            
            os.close();
        }
        catch(Exception ex)
        {
            ex.printStackTrace();
        }*/
    }
    
    private ArrayList <String> fiveMonths()
    {
        ArrayList <String> five_months = new ArrayList<>();
        
        int month = current_month_finances.getMonth();
        int year = current_month_finances.getYear();
        for (int i = 0; i < 5; i++)
        {
            String month_str = "";
            switch(month)
            {
                case 1: {month_str = "январь "; break;}
                case 2: {month_str = "февраль "; break;}
                case 3: {month_str = "март "; break;}
                case 4: {month_str = "апрель "; break;}
                case 5: {month_str = "май "; break;}
                case 6: {month_str = "июнь "; break;}
                case 7: {month_str = "июль "; break;}
                case 8: {month_str = "август "; break;}
                case 9: {month_str = "сентябрь "; break;}
                case 10: {month_str = "октябрь "; break;}
                case 11: {month_str = "ноябрь "; break;}
                case 12: {month_str = "декабрь "; break;} 
            }
            five_months.add("" + month_str + " " + year);
            month--;
            if (month == 0)
            {
                month = 12;
                year--;
            }
        }
        
        return five_months;
    }
    
    private MonthFinances openSelectMonthFinances(int month, int year)
    {
        MonthFinances select_month_finances = new MonthFinances(month, year);
        
        try
        {
            String file = "" + month + "_" + year + ".ser";
            FileInputStream fs = new FileInputStream(file);    
            ObjectInputStream os = new ObjectInputStream(fs);
        
            select_month_finances = (MonthFinances) os.readObject();
            
            os.close();
        }
        catch(Exception ex)
        {
            ex.printStackTrace();
        }
        
        return select_month_finances;
    }
    
    private void changeSelectedDate(int ind)
    {
        select_month = current_month_finances.getMonth();
        select_year = current_month_finances.getYear();
        select_month -= ind;
        if (select_month <= 0)
        {
            select_month += 12;
            select_year--;
        }
    }
    
    public void changeCurrentBalance()
    {
        main_pane.getChildren().remove(balance_pane);
        createBalancePane(current_finance.getCurrentSumma()/* + current_month_finances.getSummaFinances()*/);
        main_pane.setTop(balance_pane);
    }
    
    public CurrentFinance getCurrentFinance()
    {
        return this.current_finance;
    }
}
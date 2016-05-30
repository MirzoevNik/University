package homeheatingcontrolsystem.view;

import homeheatingcontrolsystem.controller.EditSchedule;
import homeheatingcontrolsystem.model.*;
import java.util.ArrayList;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
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

public class EditRoom extends BorderPane
{
    private final CurrentSystem parent; // окно-родитель
    private final EditRoom edit_pane; // текущее окно
    private final HeatingControlSystem main_system; // текущая система
    
    private VBox add_schedule_pane; // панель добавления элемента в расписание
    private GridPane add_settings_pane; // панель добавления установок
    private StackPane room_list_pane; // панель списка городов
     
    private final int index_current_room; // номер текущей комнаты 
    
    public EditRoom(CurrentSystem parent, HeatingControlSystem system, int index)
    {
        this.edit_pane = this;
        this.parent = parent;
        this.main_system = system;
        this.index_current_room = index;
        
        createAddSchedulePane();
        createAddSettingsPane();
        createRoomListPane();
        
        this.edit_pane.setLeft(this.add_schedule_pane);
        this.edit_pane.setRight(this.add_settings_pane);
        this.edit_pane.setBottom(this.room_list_pane);
    }
    
    private void createAddSchedulePane()
    {
        Font font = new Font("Times New Roman", 17);
        Font font2 = new Font("Times New Roman", 25);
        
        add_schedule_pane = new VBox();
        
        HBox adding_schedule = new HBox();
        
        Label add_schedule_lbl = new Label("Недельное расписание");
        add_schedule_lbl.setFont(font2);
               
        final TableView < EditSchedule > schedule_table = new TableView <>();
        schedule_table.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        schedule_table.setMinSize(330, 100);
        
        TableColumn day_col = new TableColumn("День недели");
        day_col.setMinWidth(130);
        day_col.setCellValueFactory( new PropertyValueFactory <>("day") );
        
        TableColumn hour_col = new TableColumn("Время");
        hour_col.setMinWidth(20);
        hour_col.setCellValueFactory( new PropertyValueFactory <>("time") );
        
        TableColumn count_people_col = new TableColumn("Количество человек");
        count_people_col.setMinWidth(140);
        count_people_col.setCellValueFactory( new PropertyValueFactory <>("count") );
        
        schedule_table.getColumns().addAll(day_col, hour_col, count_people_col);
        
        ArrayList <EditSchedule> data_schedule_view = new ArrayList<>();      
        for ( ScheduleItem item : main_system.getRooms().get(this.index_current_room).getWeeklySchedule() )
        {
            EditSchedule edit = new EditSchedule( item.getDay(), item.getHour(), item.getCountPeople() );
            data_schedule_view.add(edit);
        }
        ObservableList < EditSchedule > data_schedule = FXCollections.observableArrayList( data_schedule_view );
        schedule_table.setItems(data_schedule);
        
        VBox adding_schedule_item = new VBox();
        
        Label lbl_day = new Label("Выберите день недели:");
        lbl_day.setFont(font);
        
        ObservableList <String> days_string = FXCollections.observableArrayList( "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" );
        ComboBox days_list = new ComboBox(days_string);
        
        Label lbl_hour = new Label("Выберите время:");
        lbl_hour.setFont(font);
        
        ArrayList <String> hours_string = new ArrayList<>();
        for (int i = 0; i < 24; i++)
        {
            String hour_str = "" + i + " : 00";
            hours_string.add(hour_str);
        }
        ComboBox hours_list = new ComboBox( FXCollections.observableArrayList(hours_string) );
        
        Label lbl_count_people = new Label("Введите количество людей:");
        lbl_count_people.setFont(font);
     
        final TextField txt_count_people = new TextField();
        txt_count_people.setPromptText("Введите количество людей");
        txt_count_people.setMaxWidth(170);
        
        Button add_schedule_item_btn = new Button("Добавить элемент в расписание");
        add_schedule_item_btn.setFont(font);
        add_schedule_item_btn.setOnAction((ActionEvent event) -> 
        {
            int count;
            try 
            {
                count = Integer.parseInt( txt_count_people.getText() ) ;
            }
            catch(NumberFormatException exc)        
            {
                count = 0;
            }
            main_system.getRooms().get(index_current_room).addScheduleItem( days_list.getSelectionModel().getSelectedIndex() + 1 , hours_list.getSelectionModel().getSelectedIndex(), count);
            adding_schedule.getChildren().remove(schedule_table);
            days_list.getSelectionModel().clearSelection();
            hours_list.getSelectionModel().clearSelection();
            txt_count_people.setText("");
            ArrayList data_schedule_view1 = new ArrayList<>();
            for (ScheduleItem item : main_system.getRooms().get(index_current_room).getWeeklySchedule()) {
                EditSchedule edit = new EditSchedule( item.getDay(), item.getHour(), item.getCountPeople() );
                data_schedule_view1.add(edit);
            }
            ObservableList < EditSchedule > data_schedule1 = FXCollections.observableArrayList(data_schedule_view1);
            schedule_table.setItems(data_schedule1);
            adding_schedule.getChildren().add(schedule_table);
            parent.save();
        });
        
        Button del_schedule_item_btn = new Button("Удалить элемент из расписания");
        del_schedule_item_btn.setFont(font);
        del_schedule_item_btn.setOnAction((ActionEvent event) -> 
        {
            if ( schedule_table.getSelectionModel().isEmpty() == false ) 
            {
                main_system.getRooms().get(index_current_room).deleteScheduleItem(schedule_table.getSelectionModel().getSelectedIndex() );
                schedule_table.getItems().remove( schedule_table.getSelectionModel().getSelectedIndex() );
                schedule_table.getSelectionModel().clearSelection();
                parent.save();
            }
        });
        
        adding_schedule_item.setSpacing(15);
        adding_schedule_item.getChildren().add(lbl_day);
        adding_schedule_item.getChildren().add(days_list);
        adding_schedule_item.getChildren().add(lbl_hour);
        adding_schedule_item.getChildren().add(hours_list);
        adding_schedule_item.getChildren().add(lbl_count_people);
        adding_schedule_item.getChildren().add(txt_count_people);
        adding_schedule_item.getChildren().add(add_schedule_item_btn);
        adding_schedule_item.getChildren().add(del_schedule_item_btn);
        adding_schedule_item.setAlignment(Pos.TOP_CENTER);

        adding_schedule.setPadding(new Insets(0, 0, 0, 30));
        adding_schedule.getChildren().add(adding_schedule_item);
        adding_schedule.setSpacing(15);
        adding_schedule.getChildren().add(schedule_table);
        adding_schedule.setAlignment(Pos.CENTER);
        
        add_schedule_pane.getChildren().add(add_schedule_lbl);
        add_schedule_pane.setSpacing(15);
        add_schedule_pane.getChildren().add(adding_schedule);
        add_schedule_pane.setAlignment(Pos.CENTER_RIGHT);
    }
    
    private void createAddSettingsPane()
    {
        Font font = new Font("Times New Roman", 25);
        Font font2 = new Font("Times New Roman", 17);
        
        this.add_settings_pane = new GridPane();
        
        Label working_temp_lbl = new Label("Введите рабочую темп-ру:");
        working_temp_lbl.setFont(font);
        
        Label m_lbl = new Label("Введите M:");
        m_lbl.setFont(font);
        
        Label n_lbl = new Label("Введите N:");
        n_lbl.setFont(font);
        
        Label c_lbl = new Label("Введите C:");
        c_lbl.setFont(font);
        
        TextField working_temp_txt = new TextField();
        working_temp_txt.setPromptText("Введите раб. темп-ру");
        working_temp_txt.setMaxWidth(135);
        if (this.main_system.getRooms().get(index_current_room).getWorkingTemp() > -1)
            working_temp_txt.setText("" + (int)this.main_system.getRooms().get(index_current_room).getWorkingTemp());
        
        TextField m_txt = new TextField();
        m_txt.setPromptText("Введите M");
        m_txt.setMaxWidth(135);
        if (this.main_system.getRooms().get(index_current_room).getM() > -1)
            m_txt.setText("" + (int)this.main_system.getRooms().get(index_current_room).getM());
        
        TextField n_txt = new TextField();
        n_txt.setPromptText("Введите N");
        n_txt.setMaxWidth(135);
        if (this.main_system.getRooms().get(index_current_room).getN() > -1)
            n_txt.setText("" + (int)this.main_system.getRooms().get(index_current_room).getN());
        
        TextField c_txt = new TextField();
        c_txt.setPromptText("Введите C");
        c_txt.setMaxWidth(135);
        if (this.main_system.getRooms().get(index_current_room).getC() > -1)
            c_txt.setText("" + (int)this.main_system.getRooms().get(index_current_room).getC());
        
        Button save_data_btn = new Button("Сохранить данные");
        save_data_btn.setFont(font2);
        save_data_btn.setOnAction((ActionEvent event) -> 
        {
            try 
            {
                double w_t = Double.parseDouble( working_temp_txt.getText() ) ;
                main_system.getRooms().get(index_current_room).setWorkingTemp(w_t);
            }
            catch(NumberFormatException exc)
            {}
            
            try
            {
                double m = Double.parseDouble( m_txt.getText() ) ;
                main_system.getRooms().get(index_current_room).setM(m);
            }
            catch(NumberFormatException exc)
            {}
            
            try
            {
                double n = Double.parseDouble( n_txt.getText() ) ;
                main_system.getRooms().get(index_current_room).setN(n);
            }
            catch(NumberFormatException exc)
            {}
            
            try
            {
                double c = Double.parseDouble( c_txt.getText() ) ;
                main_system.getRooms().get(index_current_room).setC(c);
            }
            catch(NumberFormatException exc)
            {}
            
            parent.save();
        });
        
        this.add_settings_pane.setHgap(10);
        this.add_settings_pane.setVgap(10);
        this.add_settings_pane.add(working_temp_lbl, 0, 0);
        this.add_settings_pane.add(m_lbl, 0, 1);
        this.add_settings_pane.add(n_lbl, 0, 2);
        this.add_settings_pane.add(c_lbl, 0, 3);
        this.add_settings_pane.add(working_temp_txt, 1, 0);
        this.add_settings_pane.add(m_txt, 1, 1);
        this.add_settings_pane.add(n_txt, 1, 2);
        this.add_settings_pane.add(c_txt, 1, 3);
        this.add_settings_pane.add(save_data_btn, 0, 4);
        this.add_settings_pane.setPadding(new Insets(0, 30, 0, 0));
        this.add_settings_pane.setAlignment(Pos.CENTER_LEFT);
           
    }
    
    private void createRoomListPane()
    {
        this.room_list_pane = new StackPane();
        
        Font font = new Font("Times New Roman", 17);
        Button room_list_btn = new Button("Вернуться к списку комнат");
        room_list_btn.setFont(font);
        room_list_btn.setOnAction((ActionEvent event) -> 
        {
            parent.createListRooms(edit_pane);
        });
        
        this.room_list_pane.getChildren().add(room_list_btn);
        this.room_list_pane.setPadding(new Insets(10, 0, 10, 0));
        this.room_list_pane.setAlignment(Pos.BOTTOM_CENTER);
    }
    
}

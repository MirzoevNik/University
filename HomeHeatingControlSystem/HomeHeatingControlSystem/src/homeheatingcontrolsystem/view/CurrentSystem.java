package homeheatingcontrolsystem.view;

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
import javafx.scene.control.ListView;
import javafx.scene.control.SelectionMode;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font; 

public class CurrentSystem extends BorderPane
{
    private final CurrentSystem cur_system_pane; // текущее окно
    private final HomeHeatingControlSystem parent; //окно-родитель
    private final HeatingControlSystem main_system; // текущая система
    
    private VBox list_rooms_pane; // панель списка комнат
    private StackPane menu_pane; // панель меню
    
    private final boolean is_creating; // флаг создания или использования раннее созданной системы
    
    public CurrentSystem(HomeHeatingControlSystem parent, boolean creating)
    {
        cur_system_pane = this;
        main_system = new HeatingControlSystem();
        this.parent = parent;
        this.is_creating = creating;
        
        createListRoomsPane();
        createMenuPane();
        
        this.setCenter(list_rooms_pane);
        this.setBottom(menu_pane);
    }
    
    public CurrentSystem(HomeHeatingControlSystem parent)
    {
        this.parent = parent;
        cur_system_pane = this;
        main_system = this.parent.getSystem();
        this.is_creating = false;
        
        createListRoomsPane();
        createMenuPane();
        
        this.setCenter(list_rooms_pane);
        this.setBottom(menu_pane);
    }
    
    private void createListRoomsPane()
    {
        Font font = new Font("Times New Roman", 17);
        Font font2 = new Font("Times New Roman", 25);
        
        list_rooms_pane = new VBox();
        
        HBox list_rooms = new HBox();
        
        Label list_rooms_lbl = new Label("Список комнат");
        list_rooms_lbl.setFont(font2);
        
        ListView rooms_list = new ListView();
        rooms_list.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        rooms_list.setMaxSize(140, 200);
        ArrayList <String> rooms_names = new ArrayList<>();
        for (Room room : main_system.getRooms())
            rooms_names.add( room.getNameRoom() );
        rooms_list.setItems( FXCollections.observableArrayList (rooms_names) );
        
        list_rooms.getChildren().add(rooms_list);
        list_rooms.setSpacing(15);
        
        VBox adding_room = new VBox();
        adding_room.setSpacing(15);
        
        if (this.is_creating == true)
        {
            Label lbl_type_room = new Label("Выберите тип комнаты:");
            lbl_type_room.setFont(font);

            ObservableList <String> rooms_string = FXCollections.observableArrayList( "Спальня", "Гостиная", "Рабочий кабинет", "Ванная комната", "Кухня" );
            ComboBox rooms_std_list = new ComboBox(rooms_string);

            Button add_room_btn = new Button("Добавить комнату");
            add_room_btn.setFont(font);
            add_room_btn.setOnAction((ActionEvent event) -> 
            {
                String new_room_str = rooms_std_list.getSelectionModel().getSelectedItem().toString();
                
                Room new_room;
                switch (rooms_std_list.getSelectionModel().getSelectedIndex()) 
                {
                    case 0:
                        new_room = new Bedroom();
                        break;
                    case 1:
                        new_room = new LivingRoom();
                        break;
                    case 2:
                        new_room = new WorkingRoom();
                        break;
                    case 3:
                        new_room = new Bathroom();
                        break;
                    case 4:
                        new_room = new Kitchen();
                        break;
                    default:
                        new_room = new Bedroom();
                }
                
                main_system.addNewRoom(new_room);
                
                ArrayList <Room> rooms = main_system.getRooms();
                Room r = rooms.get( rooms.size() - 1 );
                rooms_list.getItems().add( r.getNameRoom() );
            });
            
            adding_room.getChildren().add(lbl_type_room);
            adding_room.getChildren().add(rooms_std_list);
            adding_room.getChildren().add(add_room_btn);
        }
        else
        {
            Label select_time_lbl = new Label("Выберите время");
            select_time_lbl.setFont(font2);
            
            GridPane select_time_grid = new GridPane();
            
            select_time_grid.setHgap(10);
            select_time_grid.setVgap(10);
            
            Label select_day_lbl = new Label("День:");
            select_day_lbl.setFont(font2);
            
            ObservableList <String> days_string = FXCollections.observableArrayList( "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" );
            ComboBox days_list = new ComboBox(days_string);
            
            Label select_hour_lbl = new Label("Час:");
            select_hour_lbl.setFont(font2);
            
            ArrayList <String> hours_string = new ArrayList<>();
            for (int i = 0; i < 24; i++)
            {
                String hour_str = "" + i;
                hours_string.add(hour_str);
            }
            ComboBox hours_list = new ComboBox( FXCollections.observableArrayList(hours_string) );
            
            Label select_min_lbl = new Label("Минута:");
            select_min_lbl.setFont(font2);
            
            ArrayList <String> mins_string = new ArrayList<>();
            for (int i = 0; i < 60; i++)
            {
                String min_str = "" + i;
                mins_string.add(min_str);
            }
            ComboBox mins_list = new ComboBox( FXCollections.observableArrayList(mins_string) );
            
            select_time_grid.add(select_day_lbl, 0, 0);
            select_time_grid.add(days_list, 1, 0);
            select_time_grid.add(select_hour_lbl, 0, 1);
            select_time_grid.add(hours_list, 1, 1);
            select_time_grid.add(select_min_lbl, 0, 2);
            select_time_grid.add(mins_list, 1, 2);
            
            Button set_time_btn = new Button("Установить время");
            set_time_btn.setFont(font);
            set_time_btn.setOnAction((ActionEvent event) -> 
            {
                parent.setTime( days_list.getSelectionModel().getSelectedIndex() + 1, hours_list.getSelectionModel().getSelectedIndex(), mins_list.getSelectionModel().getSelectedIndex(), 0 );
            });
            
            Button set_lcl_time_btn = new Button("Установить локальное время");
            set_lcl_time_btn.setFont(font);
            set_lcl_time_btn.setOnAction((ActionEvent event) -> 
            {
                MyTimer mt = parent.getTimer();
                mt.setLocalTime();
                parent.setTime(mt.getDay(), mt.getHour(), mt.getMin(), mt.getSec() );
            });
            
            adding_room.getChildren().add(select_time_lbl);
            adding_room.getChildren().add(select_time_grid);
            adding_room.getChildren().add(set_time_btn);
            adding_room.getChildren().add(set_lcl_time_btn);
        }
        
        Button add_room_schedule_btn = new Button("Изменить настройки комнаты");
        add_room_schedule_btn.setFont(font);
        add_room_schedule_btn.setOnAction((ActionEvent event) -> 
        {
            int index = rooms_list.getSelectionModel().getSelectedIndex();
            if (index > -1) 
            {
                EditRoom edit = new EditRoom(cur_system_pane, main_system, index);
                
                cur_system_pane.getChildren().remove(list_rooms_pane);
                cur_system_pane.setCenter(edit);
            }
        });
        
        adding_room.getChildren().add(add_room_schedule_btn);
        adding_room.setAlignment(Pos.TOP_CENTER);

        list_rooms.getChildren().add(adding_room);
        list_rooms.setAlignment(Pos.CENTER);
        
        list_rooms_pane.getChildren().add(list_rooms_lbl);
        list_rooms_pane.setSpacing(15);
        list_rooms_pane.getChildren().add(list_rooms);
        list_rooms_pane.setAlignment(Pos.CENTER);
    }
    
    private void createMenuPane()
    {
        this.menu_pane = new StackPane();
        Font font = new Font("Times New Roman", 17);
        
        Button menu_button = new Button();
        menu_button.setText("Перейти в меню");
        menu_button.setFont(font);
        menu_button.setOnAction((ActionEvent event) -> 
        {
            save();
            parent.setMenu(cur_system_pane);
        });
        
        this.menu_pane.setPadding(new Insets(10, 0, 10, 0));
        this.menu_pane.getChildren().add(menu_button);
    }
    
    public void createListRooms(BorderPane old_pane)
    {
        cur_system_pane.getChildren().remove(old_pane);
        createListRoomsPane();
        cur_system_pane.setCenter(this.list_rooms_pane);
    }
    
    public void save()
    {
        this.parent.setSystem(this.main_system);
    }
        
}

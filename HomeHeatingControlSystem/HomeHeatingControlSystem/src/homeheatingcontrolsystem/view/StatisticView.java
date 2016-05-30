package homeheatingcontrolsystem.view;

import homeheatingcontrolsystem.controller.Statistic;
import homeheatingcontrolsystem.model.Room;
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
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;

public class StatisticView extends BorderPane
{
    private final StatisticView this_pane; // текущее окно
    private final HomeHeatingControlSystem parent; // окно-родитель
    
    private TableView < Statistic > statistic_table; // таблица стистики
    private Label consumption_lbl; // отображение текущего расхода 
    private HBox statistic_pane; // панель статистики
    private StackPane menu_pane; // панель меню
    private VBox set_people_count_pane; // панель установки данных о количестве человек
    
    public StatisticView(HomeHeatingControlSystem parent)
    {
        this.this_pane = this;
        this.parent = parent;
        
        createStatisticPane();
        createMenuPane();
        
        this.setCenter(statistic_pane);
        this.setBottom(menu_pane);
    }
    
    private void createStatisticPane()
    {
        this.statistic_pane = new HBox();
        
        this.statistic_table = new TableView <>();
        statistic_table.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        statistic_table.setMinSize(700, 100);
        
        TableColumn room_col = new TableColumn("Комната");
        room_col.setMinWidth(130);
        room_col.setCellValueFactory( new PropertyValueFactory <>("room") );
        
        TableColumn people_col = new TableColumn("Количество человек");
        people_col.setMinWidth(60);
        people_col.setCellValueFactory( new PropertyValueFactory <>("people") );
        
        TableColumn temperature_col = new TableColumn("Температура");
        temperature_col.setMinWidth(120);
        temperature_col.setCellValueFactory( new PropertyValueFactory <>("temperature") );
        
        TableColumn flap_col = new TableColumn("Положение клапана");
        flap_col.setMinWidth(60);
        flap_col.setCellValueFactory( new PropertyValueFactory <>("flap") );
        
        statistic_table.getColumns().addAll(room_col, people_col, temperature_col, flap_col/*, consumption_col*/);
        
        createSetPeopleCountPane();
        
        setData();
        
        this.statistic_pane.getChildren().add(this.statistic_table);
        this.statistic_pane.setSpacing(15);
        this.statistic_pane.getChildren().add(this.set_people_count_pane);
        this.statistic_pane.setAlignment(Pos.CENTER);
        
    }
    
    private void createSetPeopleCountPane()
    {
        this.set_people_count_pane = new VBox();
        
        this.consumption_lbl = new Label("Общий расход топлива за час: " + this.parent.getSystem().getConsumption() );
        this.consumption_lbl.setFont(new Font("Times New Roman", 20));
        
        ArrayList <String> rooms_names = new ArrayList<>();
        for (Room room : this.parent.getSystem().getRooms())
            rooms_names.add( room.getNameRoom() );
        ComboBox rooms = new ComboBox();
        rooms.setItems( FXCollections.observableArrayList (rooms_names) );
        
        Label count_people_lbl = new Label("Введите количество людей в комнате:");
        count_people_lbl.setFont(new Font("Times New Roman", 20));
        
        TextField count_people_txt = new TextField();
        count_people_txt.setPromptText("Количество людей в комнате");
        count_people_txt.setMaxWidth(180);
        
        Button count_people_btn = new Button("Установить количество людей в комнате");
        count_people_btn.setFont(new Font("Times New Roman", 17));
        count_people_btn.setOnAction((ActionEvent event) -> 
        {
            try 
            {
                int cp = Integer.parseInt( count_people_txt.getText() ) ;
                if (cp <= 0)
                {
                    cp = 0;
                    parent.getSystem().getRooms().get( rooms.getSelectionModel().getSelectedIndex() ).setAutomaticalMode(true);
                    parent.getSystem().getRooms().get( rooms.getSelectionModel().getSelectedIndex() ).setPeopleCount(cp);
                }
                else
                {
                    parent.getSystem().getRooms().get( rooms.getSelectionModel().getSelectedIndex() ).setAutomaticalMode(false);
                    parent.getSystem().getRooms().get( rooms.getSelectionModel().getSelectedIndex() ).setPeopleCount(cp);
                }
                count_people_txt.clear();
                rooms.getSelectionModel().clearSelection();
            }
            catch(NumberFormatException exc)
            {}
        });
        
        this.set_people_count_pane.getChildren().add(this.consumption_lbl);
        this.set_people_count_pane.setSpacing(20);
        this.set_people_count_pane.getChildren().add(rooms);
        this.set_people_count_pane.getChildren().add(count_people_lbl);
        this.set_people_count_pane.getChildren().add(count_people_txt);
        this.set_people_count_pane.getChildren().add(count_people_btn);
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
            parent.setMenu(this_pane);
        });
        
        this.menu_pane.setPadding(new Insets(10, 0, 10, 0));
        this.menu_pane.getChildren().add(menu_button);
    }
    
    public void setData()
    {
        if (this.parent.getTimer().getSec() == 59)
            this.consumption_lbl.setText("Общий расход топлива за час: " + this.parent.getSystem().getConsumption());
        if (this.parent.getTimer().getMin() == 0 && this.parent.getTimer().getSec() == 30)
        {
            this.consumption_lbl.setText("Общий расход топлива за час: 0");
            this.parent.getSystem().setConsumption(0);
        }
        statistic_table.getItems().clear();
        ArrayList data_statistic_view = new ArrayList<>();      
        for ( Room room : this.parent.getSystem().getRooms() )
        {
            Statistic stat = room.getStatistic();
            data_statistic_view.add(stat);
            this.parent.getSystem().setConsumption( this.parent.getSystem().getConsumption() + stat.getConsumption() );
        }
        ObservableList < Statistic > data_statistic = FXCollections.observableArrayList( data_statistic_view );
        statistic_table.setItems(data_statistic);
    }
    
}
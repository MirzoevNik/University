package homeheatingcontrolsystem.view;

import homeheatingcontrolsystem.model.*;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Timer;
import java.util.TimerTask;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Stage;
import javafx.stage.WindowEvent;

public class HomeHeatingControlSystem extends Application 
{
    private HomeHeatingControlSystem this_system; // текущая система
    
    private StatisticView statistic_pane; // раздел статистики
    private BorderPane main_pane; // главная панель
    private VBox root; // корневая панель
    private StackPane timer_pane; // панель с таймером
    private Label lbl_timer; // отображение таймера
    
    private HeatingControlSystem main_system; // система регулирования отопления
    private Timer time; // поток для работы со временем
    private MyTimer my_timer; // текущее время
    
    @Override
    public void start(Stage main_stage) 
    {
        this.this_system = this;
        this.statistic_pane = null;
        
        this.main_pane = new BorderPane();
        
        createRootPane();
        createTimerPane();
        
        main_pane.setCenter(root);
        main_pane.setTop(this.lbl_timer);

        Scene scene = new Scene(main_pane, 1000, 700);
        
        main_stage.setTitle("Home Heating Control System");
        main_stage.setScene(scene);
        main_stage.setMaximized(true);
        main_stage.show();
        main_stage.setOnCloseRequest((WindowEvent event) -> 
        {
            time.cancel(); // остановка потока времени
        });
    }
    
    public static void main(String[] args) 
    {
        launch(args); // запуск приложения
    }
    
    private void createRootPane()
    {
        root = new VBox();
        
        Font font = new Font("Times New Roman", 20);
        
        Button btn1 = new Button();
        btn1.setText("Создать систему");
        btn1.setFont(font);
        btn1.setOnAction((ActionEvent event) -> 
        {
            main_pane.getChildren().remove(root);
            
            // создание новой системы отопления
            CurrentSystem create_system_pane = new CurrentSystem(this_system, true);
            main_pane.setCenter(create_system_pane);
        });
        
        Button btn2 = new Button();
        btn2.setText("Настроить систему");
        btn2.setFont(font);
        btn2.setOnAction((ActionEvent event) -> 
        {
            main_pane.getChildren().remove(root);
            CurrentSystem system_pane;
            try 
            {
                // десериализация существующей системы
                FileInputStream fs = new FileInputStream("system_data.ser");
                ObjectInputStream is = new ObjectInputStream(fs);
                
                main_system = (HeatingControlSystem) is.readObject();
                
                is.close();
                
                // настройка системы
                system_pane = new CurrentSystem(this_system);
            }
            catch(IOException | ClassNotFoundException ex)
            {
                system_pane = new CurrentSystem(this_system, true);
            }
            main_pane.setCenter(system_pane);
        });
        
        Button btn3 = new Button();
        btn3.setText("Запустить систему");
        btn3.setFont(font);
        btn3.setOnAction((ActionEvent event) -> 
        {
            main_pane.getChildren().remove(root);
            
            if (main_system != null) 
            {
                statistic_pane = new StatisticView(this_system);
                main_pane.setCenter(statistic_pane);
            }
            else
            {
                try
                {
                    // десериализация существующей системы
                    FileInputStream fs = new FileInputStream("system_data.ser");
                    ObjectInputStream is = new ObjectInputStream(fs);
                    
                    main_system = (HeatingControlSystem) is.readObject();
                    
                    is.close();
                    
                    // отображение текущей статистики
                    statistic_pane = new StatisticView(this_system);
                    main_pane.setCenter(statistic_pane);
                    
                }
                catch(IOException | ClassNotFoundException ex)
                {
                    CurrentSystem system_pane;
                    system_pane = new CurrentSystem(this_system, true);
                    main_pane.setCenter(system_pane);
                }
            }
        });
        
        root.getChildren().add(btn1);
        root.setSpacing(25);
        root.getChildren().add(btn2);
        root.setSpacing(25);
        root.getChildren().add(btn3);
        root.setAlignment(Pos.CENTER);
    }
    
    public void setMenu(CurrentSystem system_pane)
    {
        this.main_pane.getChildren().remove(system_pane);
        createRootPane();
        this.main_pane.setCenter(this.root);
    }
    
    public void setMenu(StatisticView statistic_pane)
    {
        this.main_pane.getChildren().remove(statistic_pane);
        createRootPane();
        this.main_pane.setCenter(this.root);
    }
    
    private void createTimerPane()
    {
        this.timer_pane = new StackPane();
        this.lbl_timer = new Label("");
        this.lbl_timer.setFont(new Font("Times New Roman", 20));

        this.my_timer = new MyTimer();
        this.my_timer.setLocalTime();
        setTime( this.my_timer.getDay(), this.my_timer.getHour(), this.my_timer.getMin(), this.my_timer.getSec() );
        this.timer_pane.getChildren().add(lbl_timer);
    }
    
    public void setTime(int day, int hour, int min, int sec )
    {
        if ( this.time != null )
            this.time.cancel();
        this.time = new Timer();
        this.my_timer.setDay(day);
        this.my_timer.setHour(hour);
        this.my_timer.setMin(min);
        this.my_timer.setSec(sec);
        this.time.scheduleAtFixedRate(new TimerTask() 
        {
            @Override
            public void run() 
            {
                Platform.runLater(() -> 
                {
                    lbl_timer.setText( "" + my_timer.getStrDay() + " " + my_timer.getStrHour() + ":" + my_timer.getStrMin() + ":" + my_timer.getStrSec() );
                    
                    if (main_system != null && statistic_pane != null) 
                    {
                        main_system.makeChanges( my_timer );
                        statistic_pane.setData();
                    }
                    
                    my_timer.setSec( my_timer.getSec() + 1 );
                    if ( my_timer.getSec() >= 60 )
                    {
                        my_timer.setSec( 0 );
                        my_timer.setMin( my_timer.getMin() + 1 );
                        if ( my_timer.getMin() >= 60 )
                        {
                            my_timer.setMin( 0 );
                            my_timer.setHour( my_timer.getHour() + 1 );
                            if ( my_timer.getHour() >= 24 )
                            {
                                my_timer.setHour( 0 );
                                my_timer.setDay( my_timer.getDay() + 1 );
                                if ( my_timer.getDay() >= 8 )
                                    my_timer.setDay( 1 );
                            }
                        }
                    }
                });
            }
        }, 0, 1000);
    }
    
    public void setSystem(HeatingControlSystem system)
    {
        this.main_system = system;
        try
        {
            // сериализация данных
            FileOutputStream fs = new FileOutputStream("system_data.ser");
            ObjectOutputStream os = new ObjectOutputStream(fs);
            os.writeObject(this.main_system);
            os.close();
        }
        catch(Exception ex)
        {}
    }
    
    public HeatingControlSystem getSystem()
    {
        return this.main_system;
    }
    
    public MyTimer getTimer()
    {
        return this.my_timer;
    }
    
}

package visualgraph;

import java.io.File;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

public class VisualGraph extends Application 
{
    private Stage stage;
    private VisualGraph this_class;
    private BorderPane main_pane;
    private VBox buttons_pane;
    
    @Override
    public void start(Stage primaryStage) 
    {
        this.stage = primaryStage;
        main_pane = new BorderPane();
        this.this_class = this;
        
        createButtonsPane();
        
        main_pane.setCenter(buttons_pane);       
        
        Scene scene = new Scene(main_pane, 300, 250);
        
        primaryStage.setTitle("Визуализация алгоритма Диница");
        primaryStage.setScene(scene);
        primaryStage.setMaximized(true);
        primaryStage.show();
    }

    public static void main(String[] args) 
    {
        launch(args);
    }
    
    private void createButtonsPane()
    {
        buttons_pane = new VBox();
        
        Font font = new Font("Times New Roman", 20);
        
        Button btn_ex1 = new Button();
        btn_ex1.setText("Пример №1 работы алгоритма Диница");
        btn_ex1.setFont(font);
        btn_ex1.setOnAction(new EventHandler<ActionEvent>() {
            
            @Override
            public void handle(ActionEvent event) 
            {
                VisualDinic dinic = new VisualDinic("dinic1.txt", this_class);
                main_pane.setCenter(dinic);
            }
        });
        
        Button btn_ex2 = new Button();
        btn_ex2.setText("Пример №2 работы алгоритма Диница");
        btn_ex2.setFont(font);
        btn_ex2.setOnAction(new EventHandler<ActionEvent>() {
            
            @Override
            public void handle(ActionEvent event) 
            {
                VisualDinic dinic = new VisualDinic("dinic2.txt", this_class);
                main_pane.setCenter(dinic);
            }
        });
        
        Button btn_txt = new Button();
        btn_txt.setText("Выбрать файл для просмотра алгоритма Диница");
        btn_txt.setFont(font);
        btn_txt.setOnAction(new EventHandler<ActionEvent>() {
            
            @Override
            public void handle(ActionEvent event) 
            {
                FileChooser file_chooser = new FileChooser();
                File file = file_chooser.showOpenDialog(stage);
                if (file != null) 
                {
                    VisualDinic dinic = new VisualDinic(file.getName(), this_class);
                    main_pane.setCenter(dinic);
                }
            }
        });
        
        buttons_pane.getChildren().add(btn_ex1);
        buttons_pane.setSpacing(10);
        buttons_pane.getChildren().add(btn_ex2);
        buttons_pane.setSpacing(10);
        buttons_pane.getChildren().add(btn_txt);
        buttons_pane.setAlignment(Pos.CENTER);
    }
    
    public void openMenuPane()
    {
        createButtonsPane();
        main_pane.setCenter(buttons_pane);       
    }
}

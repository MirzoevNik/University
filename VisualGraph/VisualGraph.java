package visualgraph;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class VisualGraph extends Application {

    private BorderPane main_pane;
    private VBox buttons_pane;

    
    @Override
    public void start(Stage primaryStage) 
    {
        
        main_pane = new BorderPane();
        
        createButtonsPane();
        
        main_pane.setCenter(buttons_pane);
        
        
        Scene scene = new Scene(main_pane, 300, 250);
        
        primaryStage.setTitle("Визуализация графа");
        primaryStage.setScene(scene);
        primaryStage.setMaximized(true);
        primaryStage.show();
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
    private void createButtonsPane()
    {
        buttons_pane = new VBox();
        
        Font font = new Font("Times New Roman", 20);
        
        Button btn_txt = new Button();
        btn_txt.setText("Считать граф из файла");
        btn_txt.setFont(font);
        btn_txt.setOnAction(new EventHandler<ActionEvent>() {
            
            @Override
            public void handle(ActionEvent event) 
            {
                
            }
        });
        
        Button btn_rand = new Button();
        btn_rand.setText("Создать произвольный граф");
        btn_rand.setFont(font);
        btn_rand.setOnAction(new EventHandler<ActionEvent>() {
            
            @Override
            public void handle(ActionEvent event) 
            {
                
            }
        });
        
        buttons_pane.getChildren().add(btn_txt);
        buttons_pane.setSpacing(10);
        buttons_pane.getChildren().add(btn_rand);
        buttons_pane.setAlignment(Pos.CENTER);
    }
    
}

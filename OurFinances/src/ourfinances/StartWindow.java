package ourfinances;

import javafx.concurrent.Task;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.ProgressBar;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.VBox;

public class StartWindow extends Stage{
    
    private StartWindow win = this;
    private Stage menu;
    
    private StackPane label_pane;
    //private StackPane progress_pane;
    private VBox progress_pane;
    
    /*private ThreadToMenu r;
    private Thread t;*/
    
    public StartWindow(Stage parent)
    {
        menu = parent;
        BorderPane border = new BorderPane(); 
        
        createLabelPane();
        border.setCenter(label_pane);
        
        createProgressPane();
        border.setBottom(progress_pane);
        
        Scene scene = new Scene(border, 600, 500);
        
        this.setTitle("OurFinances");
        this.setScene(scene);
        this.show();
        
        /*
        // создание потока для перехода в Меню
        r = new ThreadToMenu(win, parent);
        t = new Thread(r);
        t.start();*/
    }
    
    private void createLabelPane()
    {
        label_pane = new StackPane();
       
        Image image = new Image("File:OurFinances.jpg");
        ImageView image_view = new ImageView();
        image_view.setImage(image);
        
        label_pane.getChildren().add(image_view);
        label_pane.setAlignment(Pos.CENTER);
    }
   
    private void createProgressPane()
    {
        progress_pane = new VBox();
        
        ProgressBar progress_bar = new ProgressBar(0.0);
        
        Task<Void> task = new Task<Void>(){
            @Override
            public Void call()
            {
                return null;
            }
        };
        
        progress_bar.progressProperty().bind(task.progressProperty());
        
        Button bt = new Button();
        bt.setText("Меню");
        bt.setOnAction(new EventHandler<ActionEvent>() {
            
            @Override
            public void handle(ActionEvent event) {
                win.close();
                menu.show();
            }
        });
        
        progress_pane.getChildren().add(bt);
        //progress_pane.getChildren().add(progress_bar);
        //progress_pane.setSpacing(5);
        progress_pane.setAlignment(Pos.CENTER);
    }
    
}

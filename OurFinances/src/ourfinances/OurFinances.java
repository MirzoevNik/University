package ourfinances;

import javafx.application.Application;
import javafx.stage.Stage;

public class OurFinances extends Application {
    
    private Stage first_win;
    private Stage main_menu;
    
    @Override
    public void start(Stage main_menu) 
    {
        main_menu = new Menu();
        main_menu.close();
        first_win = new StartWindow(main_menu);
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        launch(args);
    }
    
}

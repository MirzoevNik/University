/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ourfinances;

import javafx.stage.Stage;

/**
 *
 * @author Nikita
 */
public class ThreadToMenu implements Runnable
{
    private StartWindow parent;
    private Stage parent2;
    
    private volatile boolean running = true;
    
    public ThreadToMenu(StartWindow parent, Stage parent2) 
    {
        this.parent = parent;
        this.parent2 = parent2;
    }
     
    @Override
    public void run()
    {
        for (int i = 0; i < 4; i++)    
        {
            if (i == 3)
            {
                System.out.println("1");
                if (running == false)
                {
                    System.out.println("4");
                    return;
                }
                System.out.println("3");
            }
            try 
            {
                Thread.sleep(500);
            } 
            catch (InterruptedException e) 
            {
                e.printStackTrace();
            }
        }
    }
    
    public void stop()
    {
        running = false;
    }
}

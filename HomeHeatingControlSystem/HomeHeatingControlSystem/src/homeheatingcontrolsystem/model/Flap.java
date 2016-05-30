package homeheatingcontrolsystem.model;

import java.io.Serializable;

public class Flap implements Serializable
{
    private int position; // положение клапана
    
    public Flap()
    {
        this.position = 0;
    }
    
    public Flap(int pos)
    {
        this.position = pos;
    }
    
    public void setUpPosition()
    {
        if (this.position == 0) 
            this.position = 2;
        else
            if (this.position == 2) 
                this.position = 5;
    }
    
    public void setDownPosition()
    {
        if (this.position == 5) 
            this.position = 2;
        else
            if (this.position == 2) 
                this.position = 0;
    }
    
    public int getPosition()
    {
        return this.position;
    }

}

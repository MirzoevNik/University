package homeheatingcontrolsystem.model;

import java.io.Serializable;

public abstract class Sensor implements Serializable
{
    private double value; // значение
    
    public Sensor()
    {
        this.value = 0;
    }
    
    public Sensor(double val)
    {
        this.value = val;
    }
    
    public void setValue(double val)
    {
        this.value = val;
    }
    
    public double getValue()
    {
        return this.value;
    }
    
}

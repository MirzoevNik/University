package ourfinances;

import java.io.Serializable;

public class Finance implements Serializable
{
    private final String name;
    private final double value;
    //private Finance parent;
    //private boolean isFixed;
    
    Finance(String n, double v)
    {
        this.name = n;
        this.value = v;
    }
    
    public String getName()
    {
        return name;
    }
    
    public double getValue()
    {
        return value;
    }
}

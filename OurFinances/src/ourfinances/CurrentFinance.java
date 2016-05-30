package ourfinances;

import java.io.Serializable;

public class CurrentFinance implements Serializable
{
    private double current_summa;
    private int last_month;
    private int last_year;
    
    public CurrentFinance()
    {
        this.last_month = 1;
        this.last_year = 1;
        this.current_summa = 0.0;    
    }
    
    public void setLastMonth(int m)
    {
        this.last_month = m;
    }
    
    public void setLastYear(int y)
    {
        this.last_year = y;
    }
    
    public void setCurrentSumma(double s)
    {
        this.current_summa = s;
    }
    
    public int getLastMonth()
    {
        return this.last_month;
    }
    
    public int getLastYear()
    {
        return this.last_year;
    }
    
    public double getCurrentSumma()
    {
        return this.current_summa;
    }
}

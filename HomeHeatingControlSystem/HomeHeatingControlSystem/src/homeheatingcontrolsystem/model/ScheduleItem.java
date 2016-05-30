package homeheatingcontrolsystem.model;

import java.io.Serializable;

public class ScheduleItem implements Serializable
{
    private int day; // день недели
    private int hour; // час
    private int count_people; // количество людей
    
    public ScheduleItem()
    {
        this.day = 1;
        this.hour = 0;
        this.count_people = 0;
    }
    
    public ScheduleItem(int d, int h, int cp)
    {
        if (d < 1)
            d = 1;
        else if(d > 7)
            d = 7; 
        this.day = d;
        if (h < 0)
            h = 0;
        else if (h > 23)
            h = 23;
        this.hour = h;
        if (cp < 0)
            cp = 0;
        this.count_people = cp;
    }
    
    public void setDay(int d)
    {
        if (d < 1)
            d = 1;
        else if(d > 7)
            d = 7; 
        this.day = d;
    }
    
    public void setHour(int h)
    {
        if (h < 0)
            h = 0;
        else if (h > 23)
            h = 23;
        this.hour = h;
    }
    
    public void setCountPeople(int c)
    {
        if (c < 0)
            c = 0;
        this.count_people = c;
    }
    
    public int getDay()
    {
        return this.day;
    }
    
    public int getHour()
    {
        return this.hour;
    }
    
    public int getCountPeople()
    {
        return this.count_people;
    }
}

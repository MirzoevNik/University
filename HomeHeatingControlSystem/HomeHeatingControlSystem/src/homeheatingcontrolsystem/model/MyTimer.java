package homeheatingcontrolsystem.model;

import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.LocalTime;

public final class MyTimer 
{
    private int day; // день недели
    private int hour; // час
    private int min; // минута
    private int sec; // секунда
    
    public MyTimer()
    {
        setLocalTime();
    }
    
    public void setLocalTime() // установить локальнгое время
    {
        LocalTime lcl_time = LocalTime.now();
        LocalDate lcl_date = LocalDate.now();
        DayOfWeek dow = lcl_date.getDayOfWeek();
        
        this.day = dow.getValue();
        this.hour = lcl_time.getHour();
        this.min = lcl_time.getMinute();
        this.sec = lcl_time.getSecond();
    }
    
    public void setDay(int d)
    {
        this.day = d;
    }
    
    public void setHour(int h)
    {
        this.hour = h;
    }
    
    public void setMin(int m)
    {
        this.min = m;
    }
    
    public void setSec(int s)
    {
        this.sec = s;
    }
    
    public int getDay()
    {
        return this.day;
    }
    
    public int getHour()
    {
        return this.hour;
    }
    
    public int getMin()
    {
        return this.min;
    }
    
    public int getSec()
    {
        return this.sec;
    }
    
    public String getStrDay()
    {
        String str_day = "";
        
        switch( this.day )
        {
            case 1: str_day = "Понедельник"; break;
            case 2: str_day  = "Вторник"; break;
            case 3: str_day  = "Среда"; break;
            case 4: str_day  = "Четверг"; break;
            case 5: str_day  = "Пятница"; break;
            case 6: str_day  = "Суббота"; break;
            case 7: str_day  = "Воскресенье"; break;
        }
        
        return str_day;
    }
    
    public String getStrHour()
    {
        String str_hour = "";
        if (this.hour < 10)
            str_hour = "0";
        str_hour += this.hour;
        return str_hour;
    }
    
    public String getStrMin()
    {
        String str_min = "";
        if (this.min < 10)
            str_min = "0";
        str_min += this.min;
        return str_min;
    }
    
    public String getStrSec()
    {
        String str_sec = "";
        if (this.sec < 10)
            str_sec = "0";
        str_sec += this.sec;
        return str_sec;
    }
}

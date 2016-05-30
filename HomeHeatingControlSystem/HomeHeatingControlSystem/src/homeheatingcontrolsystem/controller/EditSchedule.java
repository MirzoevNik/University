package homeheatingcontrolsystem.controller;

public class EditSchedule
{
    private final String day; // день недели
    private final String time; // время
    private final String count; // количество людей
    
    public EditSchedule(int d, int t, int c)
    {
        this.day = makeDay(d);
        this.time = makeTime(t);
        this.count = "" + c;
    }
    
    private String makeDay(int d)
    {
        String cur_day = "";
        
        switch(d)
        {
            case 1: cur_day = "Понедельник"; break;
            case 2: cur_day = "Вторник"; break;
            case 3: cur_day = "Среда"; break;
            case 4: cur_day = "Четверг"; break;
            case 5: cur_day = "Пятница"; break;
            case 6: cur_day = "Суббота"; break;
            case 7: cur_day = "Воскресенье"; break;
        }
        
        return cur_day;
    }
    
    private String makeTime(int t)
    {
        String cur_time = "" + t + " : 00";
        return cur_time;
    }
    
    public String getDay()
    {
        return this.day;
    }
    
    public String getTime()
    {
        return this.time;
    }
    
    public String getCount()
    {
        return this.count;
    }
    
}

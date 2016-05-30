package homeheatingcontrolsystem.model;

import homeheatingcontrolsystem.controller.Statistic;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Room implements Serializable
{
    private final String name_room; // название комнаты
    private double working_temp; // рабочая температура
    private double expectations_temp; // температура ожидания
    private double m; // разница темп.ожидания с рабочей
    private final ArrayList < ScheduleItem > weekly_schedule; // недельное расписание
    private final CurrentTempSensor sensor_temp; // датчик текущей температуры в комнате
    private final PeoplePresenceSensor sensor_ppl; // датчик присутствия людей
    private final Flap flap; // клапан
    private double n; // уровень отличия текущей температуры от требуемой
    private double c; // константа для подсчёта расхода топлива
    private final Statistic statistic; // объект класса Statistic, позволяющий ежесекундно обновлять информацию о комнате
    private boolean automatical_mode; // режим автоматического заполнения (для корректного регулирования кол-ва людей в комнате)
    
    public Room(String name)
    {
        this.c = 1;
        this.working_temp = 23; // стандартная температура 
        this.expectations_temp = 22; // стандартная температура
        this.n = 1;
        this.m = 1;
        this.name_room = name;
        this.automatical_mode = true;
      
        this.flap = new Flap();
        this.sensor_temp = new CurrentTempSensor();
        this.sensor_temp.setValue( this.expectations_temp ); // при создании комнаты ей "присваивается" тем-ра ожидания
        this.sensor_ppl = new PeoplePresenceSensor();
        this.weekly_schedule = new ArrayList<>();
        this.statistic = new Statistic(this.name_room);
    }
    
    public void setWorkingTemp(double wt)
    {
        this.working_temp = wt;
    }
    
    public void setM(double m)
    {
        if (m < 1)
            m = 1;
        if (m > 5)
            m = 5;
        this.m = m;
        this.expectations_temp = this.working_temp - this.m;
        if ( this.sensor_temp.getValue() == 0 )
        {
            this.sensor_temp.setValue(this.expectations_temp);
        }
    }
    
    public void setPeopleCount(int pc)
    {
        this.sensor_ppl.setValue( (double)pc );
    }
    
    public void setN(double n)
    {
        if (n < 1)
            n = 1;
        if (n > 5)
            n = 5;
        this.n = n;
    }
    
    public void setC(double c)
    {
        this.c = c;
    }
    
    public void setAutomaticalMode(boolean am)
    {
        this.automatical_mode = am;
    }
    
    public void setStatistic()
    {
        this.statistic.setConsumption( calculateConsumption() );
        this.statistic.setFlap( this.flap.getPosition() );
        this.statistic.setPeople( (int) this.sensor_ppl.getValue() );
        this.statistic.setTemperature( this.sensor_temp.getValue() );
    }
     
    public String getNameRoom()
    {
        return this.name_room;
    }
    
    public double getWorkingTemp()
    {
        return this.working_temp;
    }
    
    public double getM()
    {
        return this.m;
    }
    
    public double getN()
    {
        return this.n;
    }
    
    public double getC()
    {
        return this.c;
    }
    
    public int getPeopleCount()
    {
        return (int)this.sensor_ppl.getValue();
    }
    
    public double getCurrentTemp()
    {
        return this.sensor_temp.getValue();
    }
    
    public int getPositionFlap()
    {
        return this.flap.getPosition();
    }
    
    public boolean getAutomaticalMode()
    {
        return this.automatical_mode;
    }
    
    public Statistic getStatistic()
    {
        return this.statistic;
    }
    
    public ArrayList <ScheduleItem> getWeeklySchedule()
    {
        return this.weekly_schedule;
    }
    
    public void addScheduleItem(int d, int h, int cp)
    {
        ScheduleItem item = new ScheduleItem(d, h, cp);
        this.weekly_schedule.add(item);
        
        Comparator < ScheduleItem > itemComparator = (ScheduleItem a, ScheduleItem b) -> 
        {
            if (a.getDay() == b.getDay())
            {
                return (int)(a.getHour() - b.getHour());
            }
            else
            {
                return (int)(a.getDay() - b.getDay());
            }
        };
        Collections.sort(this.weekly_schedule, itemComparator);
    }
    
    public void deleteScheduleItem(int index)
    {
        this.weekly_schedule.remove(index);
    }
    
    public void changeDeviaionTemp() // регулирование тем-ры в комнате с помощью изменения положения клапана
    {
        if ( this.sensor_ppl.getValue() == 0 )
        {
            if ( this.sensor_temp.getValue() > this.expectations_temp + this.n )
            {
                this.flap.setDownPosition();
            }
            else
                if ( this.sensor_temp.getValue() < this.expectations_temp - this.n )
                {
                    this.flap.setUpPosition();
                }
        }
        else
        {
            if ( this.sensor_temp.getValue() > this.working_temp + this.n )
            {
                this.flap.setDownPosition();
            }
            else
                if ( this.sensor_temp.getValue() < this.working_temp - this.n )
                {
                    this.flap.setUpPosition();
                }
        }
    }
    
    public void changeDayTemp() // ежесекундное изменение дневной температуры
    {
        double k = 1.0/100.0;
        if ( this.flap.getPosition() == 0 )
            this.sensor_temp.setValue( this.sensor_temp.getValue() - k );
        else
            if ( this.flap.getPosition() == 5 )
                this.sensor_temp.setValue( this.sensor_temp.getValue() + k );
    }
    
    public void changeNightTemp() // ежесекундное изменение вечерней температуры
    {
        double k = 1.0/50.0;
        if ( this.flap.getPosition() == 0 )
            this.sensor_temp.setValue( this.sensor_temp.getValue() - k );
        else
            if ( this.flap.getPosition() == 5 )
                this.sensor_temp.setValue( this.sensor_temp.getValue() + k );
    }
    
    private double calculateConsumption() // подсчитать расход топлива в данную секунду в комнате
    {
        return this.flap.getPosition() * this.c;
    }
    
    public void calculatePeopleCount(MyTimer timer)
    {
        if ( this.automatical_mode ) // при включённом атоматическом режиме, то есть информация берется изс еженедельного расписания
        {
            boolean is_find = false;
            for ( ScheduleItem schedule : this.weekly_schedule )
            {
                if ( schedule.getDay() == timer.getDay() && schedule.getHour() == timer.getHour() )
                {
                    this.setPeopleCount( schedule.getCountPeople() );
                    is_find = true;
                    break;
                }
            }
            if (!is_find)
            {
                this.setPeopleCount( 0 );
            }
        }
    }
    
}
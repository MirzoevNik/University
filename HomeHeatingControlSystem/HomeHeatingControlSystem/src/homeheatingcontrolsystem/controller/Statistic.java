package homeheatingcontrolsystem.controller;

import java.io.Serializable;

public class Statistic implements Serializable
{
    private final String room; // название комнаты
    private int people; // количество людей в комнате
    private double temperature; // текущая температура
    private String flap; // положение клапана
    private double consumption; // расход топлива
    
    public Statistic(String r)
    {
        this.room = r;
        this.consumption = 0;
        this.flap = "Закрыт";
        this.people = 0;
        this.temperature = 23;
    }
    
    public void setPeople(int p)
    {
        this.people = p;
    }
    
    public void setTemperature(double t)
    {
        this.temperature = t;
    }
    
    public void setFlap(int f)
    {
        switch (f) 
        {
            case 0:
                this.flap = "Закрыт";
                break;
            case 2:
                this.flap = "Полуоткрыт";
                break;
            default:
                this.flap = "Открыт";
        }
    }
    
    public void setConsumption(double c)
    {
        this.consumption = c;
    }
    
    public String getRoom()
    {
        return this.room;
    }
    
    public int getPeople()
    {
        return this.people;
    }
    
    public double getTemperature()
    {
        return this.temperature;
    }
    
    public String getFlap()
    {
        return this.flap;
    }
    
    public double getConsumption()
    {
        return this.consumption;
    }
    
}

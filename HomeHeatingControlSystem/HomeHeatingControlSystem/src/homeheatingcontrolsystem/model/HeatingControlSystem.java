package homeheatingcontrolsystem.model;

import java.io.Serializable;
import java.util.ArrayList;

public class HeatingControlSystem implements Serializable
{
    private double consumption; // расход топлива в данный период времени в системе отопления
    private final ArrayList <Room> rooms; // список комнат в квартире
    
    public HeatingControlSystem()
    {
        this.consumption = 0;
        rooms = new ArrayList<>();
    }
    
    public void setConsumption(double c)
    {
        this.consumption = c;
    }
        
    public void addNewRoom(Room r)
    {
        this.rooms.add(r);
    }
    
    public ArrayList <Room> getRooms()
    {
        return this.rooms;
    }
    
    public double getConsumption()
    {
        return this.consumption;
    }
    
    public void makeChanges(MyTimer timer) // произвести изменения в системе отопления
    {
        for (Room room : this.rooms)
        {
            room.calculatePeopleCount(timer);
            room.changeDeviaionTemp();
            if (timer.getHour() > 20 || timer.getHour() < 8)
                room.changeNightTemp();
            else
                room.changeDayTemp();
            room.setStatistic();
        }
    }
    
}

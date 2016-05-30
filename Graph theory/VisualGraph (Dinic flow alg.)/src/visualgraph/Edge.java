package visualgraph;

import java.io.Serializable;

public class Edge  implements Serializable
{
    private int x1;
    private int y1;
    private int x2;
    private int y2;
    private int capacity;
    private int flow;
    private final Vertex v1;
    private final Vertex v2;
    
    public Edge(Vertex v1, Vertex v2, int c)
    {
        this.v1 = v1;
        this.v2 = v2;
        this.capacity = c;
        this.flow = 0;
        
        calculateCoordinates();
    }
    
    private void calculateCoordinates()
    {
       this.x1 = this.v1.getX() + 20;
       this.y1 = this.v1.getY() + 20;
       this.x2 = this.v2.getX() + 20;
       this.y2 = this.v2.getY() + 20;
       
       if (this.x1 < this.x2)
       {
           this.x1 += 20;
           this.x2 -= 20;
       }
       else
           if (this.x1 > this.x2)
           {
               this.x1 -= 20;
               this.x2 += 20;
           }
       
       if (this.y1 < this.y2)
       {
           this.y1 += 20;
           this.y2 -= 20;
       }
       else
           if (this.y1 > this.y2)
           {
               this.y1 -= 20;
               this.y2 += 20;
           }
       
    }
    
    public void setCapacity(int c)
    {
        this.capacity = c;
    }
    
    public void setFlow(int f)
    {
        this.flow = f;
    }
    
    public void setY2(int y2)
    {
        this.y2 = y2;
    }
    
    public int getX1()
    {
        return this.x1;
    }
    
    public int getY1()
    {
        return this.y1;
    }
    
    public int getX2()
    {
        return this.x2;
    }
    
    public int getY2()
    {
        return this.y2;
    }
    
    public Vertex getVertex2()
    {
        return this.v2;
    }
    
    public int getCapacity()
    {
        return this.capacity;
    }
    
    public int getFlow()
    {
        return this.flow;
    }

}

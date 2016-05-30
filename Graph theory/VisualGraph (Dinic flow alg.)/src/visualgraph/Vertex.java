package visualgraph;

import java.io.Serializable;

public class Vertex  implements Serializable
{
    private final int num;
    private int x;
    private int y;
    
    public Vertex(int n, int x, int y)
    {
        this.num = n;
        this.x = x;
        this.y = y;
    }
    
    public void setY(int y)
    {
        this.y = y;
    }
    
    public int getNum()
    {
        return this.num;
    }
    
    public int getX()
    {
        return this.x;
    }
    
    public int getY()
    {
        return this.y;
    }
    
}

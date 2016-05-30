package visualgraph;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;
import javafx.util.Pair;

public class Graph implements Serializable
{
    public ArrayList < Pair < Vertex, ArrayList < Edge > > > vertices;
    public ArrayList <Edge> bfs_edges;
    public ArrayList <Edge> dfs_edges;
    public int k;
    public int cur_flow;
    
    private int cur_x;
    private int cur_y;
    
    private final int height_screen;
    
    public Graph(int h)
    {
        this.vertices = new ArrayList<>();
        this.height_screen = h;
        this.k = 0;
    }
    
    private void addVertex(int u, int w)
    {
	if (findVertex(u) == null)
	{
            calculateCoordinates(u, w);
            Vertex v = new Vertex(u, this.cur_x, this.cur_y);
            ArrayList < Edge > l_vs = new ArrayList <>();
            
            Pair < Vertex, ArrayList < Edge > > p = new Pair <>(v, l_vs);  
            
            vertices.add(p);
	}
    }

    private void addEdge(int u, int v, int c)
    {
	addVertex(v, u);
	for ( Pair < Vertex, ArrayList < Edge > > vert : this.vertices )
	{
            if ( vert.getKey().getNum() == u )
            {
                boolean find = false;
                for ( Edge e : vert.getValue() )
                {
                    if ( e.getVertex2().getNum() == v )
                        find = true;
                }
                if ( !find )
                {
                    for ( Pair < Vertex, ArrayList < Edge > > verts : this.vertices )
                    {
                        if ( verts.getKey().getNum() == v )
                        {
                            vert.getValue().add( new Edge( findVertex(u), findVertex(v), c) );
                        }
                    }
                    
                }
            }
	}
    }
    
    private Vertex findVertex(int x)
    {
        for ( Pair < Vertex, ArrayList < Edge > > v : this.vertices )
        {
            if ( v.getKey().getNum() == x )
                return v.getKey();
        }
        return null;
    }
    
    private void calculateCoordinates(int u, int w)
    {
        this.cur_x = 0;
        this.cur_y = 0;
        if (u == 1)
        {
            this.cur_x = 50;
            this.cur_y = 50 + this.height_screen / 2; 
        }
        else
        {
            Vertex v = findVertex(w);
            this.cur_x = v.getX() + 150;
            if (w != 1)
            {
                
                    if ( isEmpty(this.cur_x, v.getY()) == true )
                        this.cur_y = v.getY();
                    else
                    {
                        if ( v.getY() < findVertex(1).getY() )
                        {
                            if ( isEmpty(this.cur_x, v.getY() - 100) == true )
                                this.cur_y = v.getY() - 100;
                            else
                            {
                                if ( isEmpty(this.cur_x, v.getY() + 100) == true )
                                    this.cur_y = v.getY() + 100;
                                else
                                {
                                    this.cur_x = -1;
                                    this.cur_y = -1;
                                }
                            }
                        }
                        else
                        {
                            if ( isEmpty(this.cur_x, v.getY() + 100) == true )
                                this.cur_y = v.getY() + 100;
                            else
                            {
                                if ( isEmpty(this.cur_x, v.getY() - 100) == true )
                                    this.cur_y = v.getY() - 100;
                                else
                                {
                                    this.cur_x = -1;
                                    this.cur_y = -1;
                                }
                            }
                        }
                    }
            }
            else
            {
                if ( isEmpty(this.cur_x, v.getY() - 100) == true )
                    this.cur_y = v.getY() - 100;
                else
                {
                    if ( isEmpty(this.cur_x, v.getY() + 100) == true )
                        this.cur_y = v.getY() + 100;
                    else
                    {
                        if ( isEmpty(this.cur_x, v.getY()) == true )
                            this.cur_y = v.getY();
                        else
                        {
                            this.cur_x = -1;
                            this.cur_y = -1;
                        }
                    }

                }
            }            
        }
    }
        
    private boolean isEmpty(int x, int y)
    {
        for ( Pair < Vertex, ArrayList < Edge > > v : this.vertices )
        {
            if ( v.getKey().getX() == x && v.getKey().getY() == y )
                return false;
        }
        
        return true;
    }
    
    public void readGraphTxt(String file)
    {
	try
        {
            FileReader fs = new FileReader(file);
            BufferedReader br = new BufferedReader(fs);
            String s = br.readLine();
            while (s != null) 
            {
                int x = s.indexOf(':');
		String s1 = s.substring(0, x);
		int v = Integer.parseInt(s1);
		addVertex(v, 0);
		x += 2;
		while ( x < s.length() )
		{
                    int p = s.indexOf('(', x);
                    s1 = s.substring(x, p);
                    int u = Integer.parseInt(s1);

                    x = p + 1;
                    p = s.indexOf(')', x);
                    s1 = s.substring(x, p);
                    int e = Integer.parseInt(s1);

                    addEdge(v, u, e);

                    x = p + 2;
		}
                
                s = br.readLine();
            }
            br.close();
            fs.close();
        }
        catch(Exception ex)
        {
            ex.printStackTrace();
        }
    }
    
    private int dfs(int s, int t)
    {
        Stack <Vertex> st = new Stack();
        boolean[] used = new boolean[this.vertices.size()];
        Arrays.fill(used, false);
        dfs_edges.clear();
        
        boolean flag = false;
        st.push( findVertex(s) );
        used[s - 1] = true;
        while ( !st.isEmpty() )
        {
            Vertex u = st.peek();
            boolean is_find = false;
            for ( Pair < Vertex, ArrayList < Edge > > vert : this.vertices )
            {
                if ( vert.getKey() == u )
                {
                    for ( Edge e : vert.getValue() )
                    {
                        if ( this.bfs_edges.indexOf(e) != -1 && !used[ e.getVertex2().getNum() - 1 ] )
                        {
                            st.push( e.getVertex2() );
                            used[ e.getVertex2().getNum() - 1 ] = true;
                            is_find = true;
                            if ( e.getVertex2().getNum() == t )
                            {
                                flag = true;
                                break;
                            }
                            break;
                        }
                    }
                    if (flag)
                        break;
                    if (!is_find)
                        st.pop();
                    break;
                }
            }
            if (flag)
                break;
        }
        
        int min_flow = Integer.MAX_VALUE;
        if ( !st.isEmpty() )
        {
            while( !st.isEmpty() )
            {
                Vertex v = st.pop();
                for ( Pair < Vertex, ArrayList < Edge > > vert : this.vertices )
                {
                    if ( vert.getKey() == st.peek() )
                    {
                        for ( Edge e : vert.getValue() )
                        {
                            if ( e.getVertex2() == v && this.bfs_edges.indexOf(e) != -1 )
                            {
                                this.dfs_edges.add(e);
                                if ( e.getCapacity() - e.getFlow() < min_flow )
                                    min_flow = e.getCapacity() - e.getFlow();
                                break;
                            }
                        }
                        if ( st.peek().getNum() == s )
                        {
                            st.pop();
                            break;
                        }
                    }
                }
            }
        }
        else
            return 0;
        
        for ( Pair < Vertex, ArrayList < Edge > > vert : this.vertices )
        {
            for ( Edge e : vert.getValue() )
            {
                if ( this.dfs_edges.indexOf(e) != -1 )
                {
                    e.setFlow( e.getFlow() + min_flow );
                }
            }
        }
        
        save();
        return min_flow;
    }
    
    private boolean bfs(int s, int t)
    {
        Queue <Vertex> q = new LinkedList<>();
        boolean[] used = new boolean[this.vertices.size()];
        Arrays.fill(used, false);
        bfs_edges.clear();
        
        q.offer( findVertex(s) );
        used[s - 1] = true;
        while ( !q.isEmpty() )
        {
            Vertex u = q.poll();
            for ( Pair < Vertex, ArrayList < Edge > > vert : this.vertices )
            {
                if ( vert.getKey() == u )
                    for ( Edge e : vert.getValue() )
                    {
                        if ( !used[ e.getVertex2().getNum() - 1 ] && e.getCapacity() > e.getFlow() )
                        {
                            q.offer(e.getVertex2());
                            used[ e.getVertex2().getNum() - 1 ] = true;
                            bfs_edges.add(e);
                        }
                    }
            }
        }
        for (Edge e : bfs_edges)
        {
            if (e.getVertex2().getNum() == t)
            {
                return true;
            }
        }
        return false;
    }
    
    public int dinic(int s, int t)
    {
        int max_flow = 0;
        for ( Pair < Vertex, ArrayList < Edge > > vert : this.vertices )
        {
            for ( Edge e : vert.getValue() )
            {
                e.setFlow(0);
            }
        }
        this.bfs_edges = new ArrayList<>();
        this.dfs_edges = new ArrayList<>();
        save();
        while ( bfs(s, t) )
        {
            save();
            int new_flow = dfs(s, t);
            if ( new_flow > 0 )
            {
                max_flow += new_flow;
                this.cur_flow = max_flow;
                save();
            }
            else
                break;
        }
        
        return max_flow;
    }
    
    private void save()
    {
        try
        {
            FileOutputStream fs = new FileOutputStream("" + this.k + ".ser");
            ObjectOutputStream os = new ObjectOutputStream(fs);
            os.writeObject(this);
            os.close();
            k++;
        }
        catch(Exception ex)
        {
            ex.printStackTrace();
        }
    }
    
}

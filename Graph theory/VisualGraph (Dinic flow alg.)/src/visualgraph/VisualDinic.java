package visualgraph;

import java.io.File;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextArea;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.util.Pair;

public class VisualDinic extends VBox
{
    private VisualGraph main_class;
    private VBox this_pane;
    private final Canvas canvas;
    private GraphicsContext gc;
    private Graph graph;
    private final String file;
    
    private final boolean flag;
    private int t;
    
    public VisualDinic( String file, VisualGraph main_class )
    {
        this.main_class = main_class;
        this.this_pane = this;
        this.flag = false;
        this.canvas = new Canvas(1000, 600);
        this.file = file;
                
        createCanvas();
        
        int flow = graph.dinic(1, graph.vertices.size());
        
        ScrollPane sp = new ScrollPane();
        sp.setContent(canvas);
        
        this.getChildren().add(sp);
        
        HBox hb = new HBox();
        Label lbl = new Label ("Максимальный поток: 0");
        lbl.setFont(new Font("Times New Roman", 20));
        
        t = 0;
        int k = graph.k;
        Button btn = new Button("Следующий шаг алгоритма");
        btn.setOnAction(new EventHandler<ActionEvent>() {
            
            @Override
            public void handle(ActionEvent event) 
            {
                if (t < k)
                {   
                    graph = readSaveGraph(t);
                    lbl.setText("Максимальный поток: " + graph.cur_flow);
                    t++;
                    drawGraph();
                }
                else
                {
                    btn.setText("Алгоритм закончил свою работу");
                }
            }
        });
        
        hb.setPadding( new Insets(15, 0, 15, 15) );
        hb.getChildren().add(btn);
        hb.setSpacing(15);
        hb.getChildren().add(lbl);
        
        TextArea txt_area = new TextArea();
        txt_area.setFont(new Font("Times New Roman", 17));
        txt_area.setMaxHeight(120);
        txt_area.setText("Зелёный цвет - исходная транспортная сеть \n"
                + "Оранжевый цвет - вспомогательная сеть \n"
                + "Красный цвет -  блокирующий поток");
        
        Button menu = new Button("Меню");
        menu.setOnAction(new EventHandler<ActionEvent>() 
        {
            @Override
            public void handle(ActionEvent event) 
            {
                while (t < k)
                {
                    File f = new File("" + t + ".ser");
                    f.delete();
                    t++;
                }
                main_class.openMenuPane();
            }
        });
        
        this.getChildren().add(hb);
        this.getChildren().add(txt_area);
        this.getChildren().add(menu);
    }
    
    private void createCanvas()
    {
        this.gc = canvas.getGraphicsContext2D();

        this.graph = new Graph((int)this.canvas.getHeight() - 100);
        graph.readGraphTxt(this.file);
        
        drawGraph();
        
    }
    
    private void drawGraph()
    {
        this.gc.clearRect(0, 0, 1000, 1000);
        for ( Pair < Vertex, ArrayList < Edge > > vert : graph.vertices)
        {
            drawVertex(vert.getKey());
            for ( Edge e : vert.getValue() )
            {
                if ( this.t == 0 )
                {
                    drawEdge(e);
                }
                else
                {
                    switch (this.t % 3) 
                    {
                        case 1:
                            drawEdge(e);
                            break;
                        case 2:
                            if ( graph.bfs_edges.indexOf(e) != -1 )
                            {
                                drawEdge(e);
                            }   break;
                        default:
                            if ( graph.bfs_edges.indexOf(e) != -1 )
                            {
                                drawEdge(e);
                            }   break;
                    }
                }
            }
        }
    }
    
    private void drawVertex(Vertex v)
    {
        gc.setFill(Color.BLUE);
        gc.fillOval( v.getX(), v.getY(), 40, 40 );
        gc.setFill(Color.YELLOW);
        gc.setFont( new Font("Times New Roman", 32) );
        gc.fillText("" + v.getNum(), v.getX() + 8, v.getY() + 30 );
    }
    
    private void drawEdge(Edge e)
    {
        if (this.t > 0 && this.t % 3 == 0 && this.graph.dfs_edges.indexOf(e) != -1)
            gc.setStroke(Color.RED);
        else if (this.t > 0 && ( this.t % 3 == 2 || this.t % 3 == 0 ) && this.graph.bfs_edges.indexOf(e) != -1 )
            gc.setStroke(Color.ORANGE);
        else 
            gc.setStroke(Color.GREEN);
        gc.setLineWidth(5);
        gc.strokeLine( e.getX1(), e.getY1(), e.getX2(), e.getY2() );
        
        int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        
        if ( e.getX1() == e.getX2() )
        {
            if ( e.getY1() < e.getY2() )
            {
                x1 = -20;
                x2 = 20;
                y1 = -20;
                y2 = y1;
            }
            else
            {
                x1 = -20;
                x2 = 20;
                y1 = 20;
                y2 = y1;
            }
        }
        else if ( e.getX1() < e.getX2() )
        {
            if ( e.getY1() == e.getY2() )
            {
                x1 = -20;
                x2 = x1;
                y1 = -20;
                y2 = 20;
            }
            else if ( e.getY1() < e.getY2() )
            {
                x1 = 0;
                x2 = -20;
                y1 = -20;
                y2 = 0;
            }
            else
            {
                x1 = 0;
                x2 = -20;
                y1 = 20;
                y2 = 0;
            }
        }
        else
        {
            if ( e.getY1() == e.getY2() )
            {
                x1 = 20;
                x2 = x1;
                y1 = -20;
                y2 = 20;
            }
            else if ( e.getY1() < e.getY2() )
            {
                x1 = 0;
                x2 = 20;
                y1 = -20;
                y2 = 0;
            }
            else
            {
                x1 = 0;
                x2 = 20;
                y1 = 20;
                y2 = 0;
            }
        }
        
        gc.strokeLine( e.getX2(), e.getY2(), e.getX2() + x1, e.getY2() + y1 );
        gc.strokeLine( e.getX2(), e.getY2(), e.getX2() + x2, e.getY2() + y2 );
        
        gc.setFill(Color.BLACK);
        gc.setFont( new Font("Times New Roman", 32) );
        int x = Math.min( e.getX1() + (e.getX2() - e.getX1()) / 2, e.getX2() + (e.getX1() - e.getX2()) / 2) - 10;
        int y = Math.min( e.getY1() + (e.getY2() - e.getY1()) / 2, e.getY2() + (e.getY1() - e.getY2()) / 2 );
        if ( this.t == 0 )
        {
            gc.fillText("" + e.getCapacity(), x, y );
        }
        else
        {
            switch (this.t % 3) 
            {
                case 1:
                    gc.fillText("" + e.getFlow() + "/" + e.getCapacity(), x, y );
                    break;
                case 2:
                    if ( graph.bfs_edges.indexOf(e) != -1 )
                    {
                        gc.fillText("" + (int)(e.getCapacity() - e.getFlow()), x, y );
                    }   break;
                default:
                    if ( graph.bfs_edges.indexOf(e) != -1 )
                    {
                        gc.fillText("" + (int)(e.getCapacity() - e.getFlow()), x, y );
                        break;
                    }
            }
        }

    }
    
    private Graph readSaveGraph(int t)
    {
        Graph g = new Graph((int)this.canvas.getHeight() - 100);
        
        try
        {
            FileInputStream fs = new FileInputStream("" + t + ".ser");    
            ObjectInputStream is = new ObjectInputStream(fs);

            g = (Graph) is.readObject();

            is.close();
            
            File f = new File("" + t + ".ser");
            f.delete();
        }
        catch(Exception ex)
        {
            ex.printStackTrace();
        }
        
        return g;
    }
    
}

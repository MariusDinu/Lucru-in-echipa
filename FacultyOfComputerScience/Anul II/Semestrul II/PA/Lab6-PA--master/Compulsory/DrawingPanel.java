import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.geom.Ellipse2D;
import java.awt.image.BufferedImage;
import java.util.Random;

public class DrawingPanel extends JPanel {
    final MainFrame frame;
    final static int W = 800, H = 600;
    BufferedImage image; //the offscreen image
    Graphics2D graphics; //the "tools" needed to draw in the image
    public DrawingPanel(MainFrame frame) {
        this.frame = frame; createOffscreenImage(); init();
    }



    private void createOffscreenImage() {
        image = new BufferedImage(W, H, BufferedImage.TYPE_INT_ARGB);
        graphics = image.createGraphics();
        graphics.setColor(Color.white); //fill the image with white
        graphics.fillRect(0, 0, W, H);
    }


private void init() {
        setPreferredSize(new Dimension(W, H)); //don’t use setSize. Why?
        setBorder(BorderFactory.createEtchedBorder()); //for fun
        this.addMouseListener(new MouseAdapter() {
@Override
public void mousePressed(MouseEvent e) {
        drawShape(e.getX(), e.getY()); repaint();
        } //Can’t use lambdas, JavaFX does a better job in these cases
        });
        }


    private void drawShape(int x, int y) {
    Random rand=new Random();
        int radius = rand.nextInt(255); //generate a random number
        int sides = (int) frame.configPanel.sidesField.getValue(); //get the value from UI (in ConfigPanel)
        String shapes= (String)frame.configPanel.shapeCombo.getSelectedItem(); // se primeste itemul selectat din Jcombobox

        String culoare=(String)frame.configPanel.colorCombo.getSelectedItem(); //se primeste itemul selectat din Jcombobox
//facem switch/case ca sa stabilim ce fel de forme vom desena
        switch (shapes) {
            case "circles":
              graphics.fillOval(x,y,70,70); // aici desenam cercuri , pentru ovaluri modificam ultimii 2 parametrii
                break;
            case "regular_polygons":
                graphics.fill(new RegularPolygon(x, y, radius, sides)); //aici desenam poligoane in functie de laturi
                break;


        }
        if(culoare!="Black")
        {Color color = new Color(rand.nextInt()); graphics.setColor(color);} // se preia culoarea random
            else {  Color color= new Color(0,0,0);graphics.setColor(color); } //se preia culoarea black
        }

@Override
public void update(Graphics g) { } //Why did I do that?

@Override
protected void paintComponent(Graphics g) {
        g.drawImage(image, 0, 0, this);
        }



        }
import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

public class Move implements MouseListener, MouseMotionListener {
private int X,Y;


 public Move(Component... pns){
     for (Component panel : pns){
         panel.addMouseListener(this);
         panel.addMouseMotionListener(this);
     }
 }
    @Override
    public void mouseClicked(MouseEvent e) {

    }

    @Override
    public void mousePressed(MouseEvent event) {
        X=event.getX();
        Y=event.getY();
    }

    @Override
    public void mouseReleased(MouseEvent event) {
        X=event.getX();
        Y=event.getY();
    }

    @Override
    public void mouseEntered(MouseEvent e) {

    }

    @Override
    public void mouseExited(MouseEvent e) {

    }

    @Override
    public void mouseDragged(MouseEvent event) {
        event.getComponent().setLocation((event.getX()+event.getComponent().getX())-X,(event.getY()+event.getComponent().getY())-Y);
    }

    @Override
    public void mouseMoved(MouseEvent e) {

    }
}

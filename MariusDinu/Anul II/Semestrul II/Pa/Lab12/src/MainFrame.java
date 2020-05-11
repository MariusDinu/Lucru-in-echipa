import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;

public class MainFrame extends JFrame{

    public MainFrame(){


            setTitle("My Lab 12");
            setSize(800, 600);
            setResizable(false);
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

             //This is where I'm clearly going wrong.

    }


    public static void main(String[] args){

       MainFrame frame=new MainFrame();
       DesignPanel designPanel=new DesignPanel();
       ControlPanel controlPanel=new ControlPanel(frame,designPanel);



       frame.add(controlPanel, BorderLayout.NORTH);


        frame.setVisible(true);







    }

}

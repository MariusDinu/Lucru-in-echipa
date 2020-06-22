import javax.swing.*;
import java.awt.*;


public class MainFrame extends JFrame {

    ConfigPanel configPanel;
    ControlPanel controlPanel;
    DrawingPanel canvas;

    public MainFrame() {
        super("My Drawing Application");
        init();
    }

    private void init() {
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        //create the components
        JPanel first=new JPanel();
        JPanel second=new JPanel();
        canvas = new DrawingPanel(this);
        controlPanel= new ControlPanel(this);
        configPanel=new ConfigPanel(this);
 //...TODO

        //arrange the components in the container (frame)
        //JFrame uses a BorderLayout by default

        add(configPanel,BorderLayout.NORTH);
        add(controlPanel,BorderLayout.SOUTH);
        add(canvas,BorderLayout.CENTER); //this is BorderLayout.CENTER
 //...TODO

        //invoke the layout manager
        pack();
    }
}

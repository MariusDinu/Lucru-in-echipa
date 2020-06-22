import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class ControlPanel extends JPanel {
    final MainFrame frame;
    JButton saveBtn = new JButton("Save");
    JButton loadBtn = new JButton("Load");
    JButton resetBtn = new JButton("Reset");
    JButton exitBtn = new JButton("Exit");


    public ControlPanel(MainFrame frame) {
        this.frame = frame; init();
    }



    private void init() {

        //change the default layout manager (just for fun)
        setLayout(new GridLayout(1, 4));
        //add all buttons ...TODO
        this.add(saveBtn);
        this.add(loadBtn);
        this.add(resetBtn);
        this.add(exitBtn);
        //configure listeners for all buttons
        saveBtn.addActionListener(this::save);
        loadBtn.addActionListener(this::load);
        resetBtn.addActionListener(this::reset);
        exitBtn.addActionListener(this::exit);

    }

//avem aici actiunile dupa apasarea butonului
    private void save(ActionEvent e) {
        try {
            ImageIO.write(frame.canvas.image, "PNG", new File("d:/test.png"));
        } catch (IOException ex) { System.err.println(ex); }
    }
    private void load(ActionEvent e) {
        BufferedImage img = null;
        try {
            img = ImageIO.read(new File("d:/test.png"));
        } catch (IOException ex) {System.err.println(ex); }
        }


    private void reset(ActionEvent e) {
            frame.setVisible(false);
            new MainFrame().setVisible(true);
    }
    private void exit(ActionEvent e) {
            System.exit(0);
    }

}

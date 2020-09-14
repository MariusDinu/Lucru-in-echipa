package application;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JButton;
import javax.swing.JPanel;

public class ControlPanel extends JPanel {
	final MainFrame frame;
	JButton saveBtn = new JButton("Save");
	JButton loadBtn = new JButton("load");
	JButton RestBtn = new JButton("Rest");
	JButton ExitBtn = new JButton("Exit");
	//create all buttons (Load, Reset, Exit)
	public ControlPanel(MainFrame frame) {
		this.frame = frame; init();
		}
	private void init() {
        
        setLayout(new GridLayout(1, 4));
        JPanel buttonPanel = new JPanel();
        this.add(buttonPanel, BorderLayout.NORTH);
        buttonPanel.add(saveBtn);
        buttonPanel.add(loadBtn);
        buttonPanel.add(RestBtn);
        buttonPanel.add(ExitBtn);
        //configure listeners for all buttons
        saveBtn.addActionListener(this::save);
        RestBtn.addActionListener(this::reset);
        loadBtn.addActionListener(this::load);
        ExitBtn.addActionListener(this::exit);
    }
    private void save(ActionEvent e) {
        try {
            ImageIO.write(frame.canvas.image, "PNG", new File("d:/test.png"));
        } catch (IOException ex) { System.err.println(ex); }
    }
    private void load(ActionEvent e) {
        try {
            ImageIO.read(new File("d:/test.png"));
        } catch (IOException ex) { System.err.println(ex); }
    }
    private void reset(ActionEvent e) {
        frame.setVisible(false);
        new MainFrame().setVisible(true);

    }
    private void exit(ActionEvent e) {
        System.exit(0);
    }


}



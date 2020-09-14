package application;

import java.awt.BorderLayout;

import javax.swing.JFrame;

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
		canvas = new DrawingPanel(this);    
		controlPanel=new ControlPanel(this);       
		configPanel=new ConfigPanel(this);
		add(controlPanel, BorderLayout.NORTH);
		add(canvas, BorderLayout.CENTER);
		add(configPanel, BorderLayout.SOUTH);
		pack();           
		
	}
}

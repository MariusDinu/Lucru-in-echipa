import javafx.scene.LightBase;

import javax.swing.*;
import java.awt.*;
import java.util.Random;

public class ConfigPanel extends JPanel {
    final MainFrame frame;
    JLabel label; // we’re drawing regular polygons
    JSpinner sidesField;// number of sides
    JSpinner sidesField2;// x from RegularPolygon
    JSpinner sidesField3;// y from RegularPolygon
    JSpinner sidesField4;// radius from RegularPolygon
    JSpinner sidesField5;// choose shape
   public JComboBox colorCombo; // the color of the shape
    public JComboBox shapeCombo;

    public ConfigPanel(MainFrame frame) {
        this.frame = frame;
        init();
    }


    private void init() {

        //create the label and the spinner
//aici selectam marimile diferite ale poligoanelor,practic setam noi dimensiunile
        JLabel sidesLabel = new JLabel("Number of sides:");
        sidesField = new JSpinner(new SpinnerNumberModel(0, 0, 100, 1));

        JLabel XLabel = new JLabel("Number of X:");
        sidesField2 = new JSpinner(new SpinnerNumberModel(0,0,100,1));

        JLabel YLabel = new JLabel("Number of Y:");
        sidesField3 = new JSpinner(new SpinnerNumberModel(0,0,100,1));

        JLabel radiusLabel = new JLabel("Number of radius:");
        sidesField4 = new JSpinner(new SpinnerNumberModel(0,0,100,1));



        sidesField.setValue(6); //default number of sides
        //avem aici cele 2 jcombobox cu elemente luate dintr-un string
        String [] colors={"Random","Black"};
        JLabel colorLabel = new JLabel("Choose color:");
        colorCombo= new JComboBox(colors);

        String [] shapes={ "circles", "squares", "regular_polygons", "snow flakes"};
        JLabel shapeLabel = new JLabel("Choose shape:");
        shapeCombo=new JComboBox(shapes);
//am adaugat aceste elemente in bara de sus
        add(sidesLabel); //JPanel uses FlowLayout by default
        add(sidesField);
        add(XLabel);
        add(sidesField2);
        add(YLabel);
        add(sidesField3);
        add(radiusLabel);
        add(sidesField4);
        add(colorLabel);
        add(colorCombo);
        add(shapeLabel);
        add(shapeCombo);
    }




}



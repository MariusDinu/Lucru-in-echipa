import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.Random;

public class ControlPanel extends JPanel {


    MainFrame frame=null;
    DesignPanel design=null;



    public ControlPanel(MainFrame frame,DesignPanel design){
        this.frame = frame;
        this.design=design;
        setControlPanel();
    }

    public void setControlPanel() {
        JLabel labelX = new JLabel("X:");
        JLabel labelY = new JLabel("Y:");
        JLabel sizeW = new JLabel("Size width:");
        JLabel sizeH = new JLabel("Size height:");
        TextField textX = new TextField();
        TextField textY = new TextField();
        TextField textSizeW = new TextField();
        TextField textSizeH = new TextField();
        JButton randomButton = new JButton("DateRandom");
        JButton select=new JButton("Select");
        JLabel numeBtn=new JLabel("Nume/Text:");
        TextField numeButton = new TextField();






        String[] lista = {"Buton", "Label", "CasetaText", "ProgresBar"};
        setLayout(new GridLayout(4, 4, 5, 20));
        setBorder(BorderFactory.createEmptyBorder(30, 30, 10, 30));

        setBackground(Color.blue);
        JComboBox componente = new JComboBox(lista);
        add(labelX);
        add(textX);
        add(labelY);
        add(textY);
        add(sizeW);
        add(textSizeW);
        add(sizeH);
        add(textSizeH);
        add(numeBtn);
        add(numeButton);
        add(componente);
        add(randomButton);

        add(select);
        setVisible(true);

        frame.add(design);

        select.addActionListener(e -> {

            if(componente.getSelectedItem().equals("Buton"))
            {

                final JButton newButton = new JButton(numeButton.getText());

                newButton.addMouseListener(new MouseListener() {
                 @Override
                 public void mouseClicked(MouseEvent e2) {
                   if (SwingUtilities.isRightMouseButton(e2)) {
                   design.remove(newButton);
                   design.revalidate();
                   design.repaint();
                   }
                   }

                 @Override
                 public void mousePressed(MouseEvent e) {
                 }
                 @Override
                 public void mouseReleased(MouseEvent e) {
                 }

                 @Override
                 public void mouseEntered(MouseEvent e) {
                 }

                 @Override
                 public void mouseExited(MouseEvent e) {
                 }
                 });

                newButton.setBounds(Integer.parseInt(textX.getText()),Integer.parseInt(textY.getText()),Integer.parseInt(textSizeW.getText()),Integer.parseInt(textSizeH.getText()));
                design.add(newButton);
                design.revalidate();
                design.repaint();
                Move mv=new Move(design.getComponents());
            }
            else if(componente.getSelectedItem().equals("Label")){

                final JLabel newLabel = new JLabel(numeButton.getText());
                newLabel.setForeground(Color.black);
                newLabel.setBackground(Color.white);
                newLabel.setOpaque(true);
                newLabel.addMouseListener(new MouseListener() {
                    @Override
                    public void mouseClicked(MouseEvent e) {
                        if(SwingUtilities.isRightMouseButton(e))
                        {  design.remove(newLabel);
                        design.revalidate();
                        design.repaint();}
                    }

                    @Override
                    public void mousePressed(MouseEvent e) {
                    }

                    @Override
                    public void mouseReleased(MouseEvent e) {
                    }

                    @Override
                    public void mouseEntered(MouseEvent e) {
                    }

                    @Override
                    public void mouseExited(MouseEvent e) {
                    }
                });

                newLabel.setBounds(Integer.parseInt(textX.getText()),Integer.parseInt(textY.getText()),Integer.parseInt(textSizeW.getText()),Integer.parseInt(textSizeH.getText()));
                design.add(newLabel);
                design.revalidate();
                design.repaint();
                Move mv=new Move(design.getComponents());

            }else if(componente.getSelectedItem().equals("CasetaText")) {
                final TextField newCasetaText = new TextField();

                newCasetaText.addMouseListener(new MouseListener() {
                    @Override
                    public void mouseClicked(MouseEvent e) {
                        if(SwingUtilities.isRightMouseButton(e))
                        {design.remove(newCasetaText);
                        design.revalidate();
                        design.repaint();}
                    }

                    @Override
                    public void mousePressed(MouseEvent e) {
                    }

                    @Override
                    public void mouseReleased(MouseEvent e) {
                    }

                    @Override
                    public void mouseEntered(MouseEvent e) {
                    }

                    @Override
                    public void mouseExited(MouseEvent e) {
                    }
                });

                newCasetaText.setBounds(Integer.parseInt(textX.getText()),Integer.parseInt(textY.getText()),Integer.parseInt(textSizeW.getText()),Integer.parseInt(textSizeH.getText()));
                design.add(newCasetaText);
                design.revalidate();
                design.repaint();
                Move mv=new Move(design.getComponents());
            }else if(componente.getSelectedItem().equals("ProgresBar")){
                final JProgressBar newProgresBar = new JProgressBar();

                newProgresBar.addMouseListener(new MouseListener() {
                    @Override
                    public void mouseClicked(MouseEvent e) {
                        if(SwingUtilities.isRightMouseButton(e)){
                        design.remove(newProgresBar);
                        design.revalidate();
                        design.repaint();}
                    }

                    @Override
                    public void mousePressed(MouseEvent event) {
                    }

                    @Override
                    public void mouseReleased(MouseEvent e) {
                    }

                    @Override
                    public void mouseEntered(MouseEvent e) {
                    }

                    @Override
                    public void mouseExited(MouseEvent e) {
                    }
                });

                newProgresBar.setBounds(Integer.parseInt(textX.getText()),Integer.parseInt(textY.getText()),Integer.parseInt(textSizeW.getText()),Integer.parseInt(textSizeH.getText()));
                newProgresBar.setValue(50);
                design.add(newProgresBar);
                design.revalidate();
                design.repaint();
                Move mv=new Move(design.getComponents());
            }







        });
        randomButton.addActionListener(e->{
            textX.setText(String.valueOf(random(200)));
            textY.setText(String.valueOf(random(200)));
            textSizeH.setText(String.valueOf(random(400)));
            textSizeW.setText(String.valueOf(random(500)));
            numeButton.setText("abc");

        });

    }
    public int random(int i){
        Random random=new Random();
        int n=random.nextInt(i);
        return n;
    }
}

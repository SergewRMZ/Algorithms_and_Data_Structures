package views;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.RenderingHints;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.Timer;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import javax.swing.border.LineBorder;

import automata.AutomataPushDown;
import automata.MyStack;

public class Interfaz {
    private static Interfaz instance;
    private MyStack pila;
    private int rectWidth = 150; // Ancho de rectangulo
    private int rectHeight = 50; // Altura de Rectangulo
    private int spaceBetweenRect = 10; // Espaciado entre cada rectángulo
    private int itemX;
    private int itemY; 
    private Font fuente;
    private JPanel canvas;
    private JFrame frame;
    private JLabel labelStringAutomata;
    private JLabel labelStringAccepted;
    private AutomataPushDown automata;

    // Colores
    private Color blueColor;
    private Color bgColor;

    // Constructor
    public Interfaz() {
        this.pila = new MyStack();
        this.fuente = new Font("Arial", Font.PLAIN, 20);
        this.itemX = 600; // Posición x de cada bloque
        this.itemY = 650; // Posición y de cada bloque

        this.blueColor = Color.decode("#398BE3");
        this.bgColor = Color.decode("#252525");
    }

    public void emptyStack() {
        pila.emptyStack();
        canvas.repaint();
    }


    public void pause () {
        try {
            Thread.sleep(200);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void addElement(char c) {
        pila.push(c);
        canvas.repaint();
        pause();
    }

    public void removeElement() {
        this.pila.pop();
        this.canvas.repaint();
        pause();
    }

    // Patrón de diseño Singleton, para obtener una única instancia de la clase.
    public static Interfaz getInstance() {
        if (instance == null) {
            instance = new Interfaz();
        }

        return instance;
    }

    public void setup() {
        frame = new JFrame("Autómata de Pila");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setPreferredSize(new Dimension(800, 800));
        this.canvas = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);

                // Cargando el fondo del canvas
                ImageIcon bgImage = new ImageIcon(getClass().getResource("../img/background.jpg"));
                Image img = bgImage.getImage();
                
                drawStack(g, img);
            }
        };

        this.canvas.setLayout(null); // Desactivar Layout por defecto

        drawStringToAnalyze(); // Colocar los labels
        drawButtonStart(); // Colocar el botón

        frame.getContentPane().add(canvas);
        frame.pack();
        frame.setLocationRelativeTo(null); // Centrar la vista
        frame.setVisible(true);
    }

    /**
     * Método para dibujar la pila en la ventana
     * @param g Object Graphics
     */
    private void drawStack(Graphics g, Image img) {
        g.setColor(this.bgColor);
        g.fillRect(0, 0, canvas.getWidth(), canvas.getHeight());
        g.drawImage(img, 0, 0, canvas.getWidth(), canvas.getHeight(), null);

        // Usando Graphics2D
        Graphics2D g2d = (Graphics2D) g;
        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
    
        // Fuente
        g2d.setColor(new Color(35, 160, 230));
        g2d.setFont(this.fuente);
    
        if (!pila.Empty()) {

            // Mostrar pila
            for (int i = 0; i < pila.size(); i++) {
                char value = pila.get(i);

                // Dibujar el rectángulo
                g2d.setColor(this.blueColor);
                g2d.fillRect(itemX, itemY - i * (rectHeight + spaceBetweenRect), rectWidth, rectHeight);
                
                // Dibujar el borde
                g2d.setColor(Color.WHITE);
                g2d.drawRect(itemX, itemY - i * (rectHeight + spaceBetweenRect), rectWidth, rectHeight);
        
                g2d.drawString(String.valueOf(value), (itemX + rectWidth / 2) - 5, itemY - i * (rectHeight + spaceBetweenRect) + rectHeight / 2 + 5);
            }
        }
    } 

    /**
     * Método para agregar un label que
     * mostrará la cadena que se está analizando
     */
    private void drawStringToAnalyze () {
        Font font = new Font("Arial", Font.PLAIN, 40);
        Font boldFont = font.deriveFont(Font.BOLD);
        JLabel tittle = new JLabel("Pushdown Automata", SwingConstants.CENTER);
        tittle.setBounds(150, 50, 500, 75);
        tittle.setFont(boldFont);
        tittle.setForeground(Color.WHITE); // Color de la fuente
        tittle.setOpaque(true);
        tittle.setBackground(Color.decode("#195499"));

        labelStringAutomata = new JLabel(); 
        labelStringAutomata.setBounds(200, 200, 300, 100);
        labelStringAutomata.setFont(font);
        labelStringAutomata.setForeground(Color.WHITE);
        tittle.setOpaque(true);
        tittle.setBackground(Color.decode("#195499"));
        
        labelStringAccepted = new JLabel("", SwingConstants.CENTER);
        labelStringAccepted.setBounds(100, 550, 400, 50);
        labelStringAccepted.setFont(boldFont);
        labelStringAccepted.setForeground(Color.WHITE);

        canvas.add(labelStringAccepted);
        canvas.add(tittle);
        canvas.add(labelStringAutomata);  
    }

    /**
     * Método para crear el botón de inicio
     */
    private void drawButtonStart () {
        JButton btn_start = new JButton("START");
        btn_start.setBounds(100, 650, 400, 50);
        btn_start.setFont(this.fuente);
        btn_start.setBackground(this.blueColor);
        btn_start.setBorder(new LineBorder(Color.WHITE, 2));
        btn_start.setFocusPainted(false);
        btn_start.setForeground(Color.WHITE);
        btn_start.addActionListener(onButtonStart(btn_start));
        canvas.add(btn_start);
    }

    public void addStringToLabel (String string) {
        Timer timer = new Timer(200, new ActionListener() {
            int i = 0;

            @Override
            public void actionPerformed(ActionEvent e) {
                if (i < string.length()) {
                    char c = string.charAt(i);
                    labelStringAutomata.setText(c + string.substring(i + 1, string.length()));
                    i++;
                }   else {
                    labelStringAutomata.setText("");
                    ((Timer) e.getSource()).stop();
                }
            }
        });

        timer.start();
    }

    public void setStringAccepted(String string) {
        labelStringAccepted.setText(string);
    }
    
    /**
     * Función para agregar el listener al botón de start.
     * @param btn
     * @return
     */
    private ActionListener onButtonStart(JButton btn) {
        return new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                btn.setEnabled(false); // Desactivar el botón una vez
                Thread thread = new Thread(() -> {
                        try {
                            automata = new AutomataPushDown();
                            automata.generateStrings(100);
                        } catch (Exception ex) {
                            ex.printStackTrace();
                        }
                });

                thread.start();
            }
        };
    }
}

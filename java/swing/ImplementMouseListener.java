import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import javax.swing.*;

public class ImplementMouseListener implements MouseListener
{
    JFrame f;
    public ImplementMouseListener()
    {
        f = new JFrame();
        f.setSize(300, 150);
        f.setVisible(true);
        f.addMouseListener(this);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void mousePressed(MouseEvent e)
    {
    }
    public void mouseReleased(MouseEvent e)
    {
    }
    public void mouseEntered(MouseEvent e)
    {
    }
    public void mouseExited(MouseEvent e)
    {
        f.setTitle("我爱陕科大");
    }
    public void mouseClicked(MouseEvent e)
    {
        f.setTitle("陕科大");
    }

    public static void main(String args[])
    {
        new ImplementMouseListener();
    }
}

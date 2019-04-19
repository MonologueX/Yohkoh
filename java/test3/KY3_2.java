import java.awt.*; 
import java.applet.Applet; 

public class KY3_2 extends Applet 
{ 
	MyBox b1 = new MyBox();//创建对象 b1 
	MyBox b2 = new MyBox(170, 20, 60, 60); //创建对象 b2 
	public void paint(Graphics g) 
	{ 
		b1.setPosition(20, 20); 
		b1.setSize(60, 60); 
		b1.draw(g); 
		g.drawString("矩形 1 的 X 位置: "+b1.getX(), 20, 100); 
		g.drawString("矩形 1 的 Y 位置: "+b1.getY(), 20, 120); 
		b2.draw(g); 
		g.drawString("矩形 2 的 X 位置: "+b2.getX(), b2.getX(), b2.getY()+80); 
		g.drawString("矩形 2 的 Y 位置: "+b2.getY(), b2.getX(), b2.getY()+100); 
	} 
}

class MyBox 
{ 
	private int x, y, width, height; 
	MyBox() 
    { 
		x = 0; 
		y = 0; 
		width = 0; 
		height = 0; 
	}
	MyBox(int xPos, int yPos, int w, int h) 
    { 
		x = xPos; 
		y = yPos; 
		width = w; 
		height = h; 
	}
	public void setPosition (int xPos, int yPos) 
    { 
		x = xPos; 
		y = yPos; 
	} 
	public void setSize (int w, int h) 
    { 
		width = w; 
		height = h; 
	} 
	public int getX() 
    { 
		return x; 
	} 
	public int getY() 
    { 
		return y; 
	} 
	public void draw(Graphics g) 
    { 
		g.drawRect(x, y, width, height); 
	} 
}

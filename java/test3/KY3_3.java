import java.awt.Graphics;
import java.applet.Applet;
import java.util.Calendar;

class Time 
{
	private Calendar t;
	private int y, m, d, hh, mm, ss;
	Time ()
    {
		t = Calendar.getInstance();
		y = t.get(t.YEAR);
		m = t.get(t.MONTH)+1;
		d = t.get(t.DATE);
		hh = t.get(t.HOUR_OF_DAY);
		mm = t.get(t.MINUTE);
		ss = t.get(t.SECOND);
	}
	public String getDate() 
    {
		return y+" 年"+m+"月"+d+"日";
	}
	public String getTime() 
    {
		String s = hh+" 时"+mm+"分"+ss+"秒";
		return s;
	}
}
public class KY3_3 extends Applet 
{
	Time t = new Time();
	public void paint(Graphics g) 
    {
		g.drawString("当前日期："+t.getDate(), 50, 40);
		g.drawString("当前时间："+t.getTime(), 50, 80);
	}
}

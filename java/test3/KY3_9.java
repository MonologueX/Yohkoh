import java.awt.Graphics;
import java.applet.Applet;

class IntSort 
{
    public String sort(int a, int b) 
    {
        if (a > b)
            return a+" "+b;
        else
            return b+" "+a;
    }
    public String sort(int a, int b, int c) 
    {
        int swap;
        if (a < b) 
        {
            swap = a;
            a = b;
            b = swap;
        }
        if (a < c) 
        {
            swap = a;
            a = c;
            c = swap;
        }
        if (b < c) 
        {
            swap = b;
            b = c;
            c = swap;
        }
        return a+" "+b+" "+c;
    }
    public String sort(int arr[]) 
    {
        String s=" ";
        int swap;
        for (int i = 0; i < arr.length; i++)
        {
            for (int j = 0; j < arr.length - 1; j++)
            {
                if (arr[j] > arr[j+1]) 
                {
                    swap = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = swap;
                }
            }
        }
        for (int i = 0; i < arr.length; i++)
            s = s+arr[i]+" ";
        return s;
    }
}

public class KY3_11 extends Applet 
{
    IntSort s = new IntSort();
    public void paint(Graphics g) 
    {
        int a = 30, b = 12, c = 40;
        int arr[] = {34, 8, 12, 67, 44, 98, 52, 23, 16, 16};
        g.drawString("两个数的排序结果："+s.sort(a, b), 30, 30);
        g.drawString("三个数的排序结果："+s.sort(a, b, c), 30, 60);
        g.drawString("数组的排序结果："+s.sort(arr), 30, 90);
    }
}

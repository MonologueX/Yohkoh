/***********************************
 * 文件名称: Complex.java
 * 文件描述: 
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/

public class Complex 
{
    private float shishu;
    private float xushu;
    Complex()
    {
        this.shishu = 0;
        this.xushu = 0;
    }
    Complex(float shishu, float xushu)
    {
        this.shishu = shishu;
        this.xushu = xushu;
    }
    public void Add(Complex p)
    {
        Complex result = new Complex();
        result.shishu = this.shishu + p.shishu;
        result.xushu = this.xushu + p.xushu;
        System.out.println("resulr = "+result.shishu+"+"+result.xushu+"i");
    }
    public static void main(String []args)
    {
        Complex flush1 = new Complex(2, 2);
        Complex flush2 = new Complex(3, 4);
        flush1.Add(flush2);
    }
}

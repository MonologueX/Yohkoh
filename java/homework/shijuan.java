/***********************************
 * 文件名称: 
 * 文件描述: 试卷
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/
public class Test
{
    public static void main(String args[])
    {
        String s = new String("信息");
        s += "学院";
        modify(s);
        System.out.println(s);
    }
    public static void modify(String s)
    {
        s += "学院";
    }
}

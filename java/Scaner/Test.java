import java.util.*;

public class Test
{
    public static void main(String []args)
    {
        Scanner input = new Scanner(System.in);
        System.out.print("请输入一个整数：");
        int num = input.nextInt();
        if ((num & 1) == 1)
            System.out.println(num+"不是偶数");
        else 
            System.out.println(num+"是偶数");
    }
}

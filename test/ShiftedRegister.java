package com.sust.cipher5;
import java.util.Scanner;
/*
 * n级线性移位寄存器f(x) = x^4 + x + 1,初始状态为1001
 * @author Matthew
 * @date 2018/5/15 9:15
*/
public class ShiftedRegister 
{
    public static void main(String[] args) 
    {
        //1. 以线性表记录初始状态
        int[] arr = new int[4];
        System.out.print("请输入4级线性移位寄存器的初始状态：");
        Scanner sc = new Scanner(System.in);
        //2. 以字符串形式接受输入
        String s = sc.nextLine();
        for(int i = 0; i < s.length();i ++) 
        {
            arr[i] = Integer.parseInt(s.substring(i,i+1));
        }
        System.out.println("演示输出 " + "  a1  a2  a3  a4        f ");
        System.out.print("第0次输出  " + arr[0] + "   " + arr[1] + "   "  + arr[2] + "   "  + arr[3]);
        System.out.println("          " + arr[3]);
        //3. 多项式系数
        int coef1 = arr[0];
        int coef2 = arr[1];
        int coef3 = arr[2];
        int coef4 = arr[3];
        //4. 输出多项式f(x)
        int counter = 0;
        while (true)
        {
            int f = coef4;
            coef4 = coef3;
            coef3 = coef2;
            coef2 = coef1;
            coef1 = xorOpe(f,coef1);
            counter ++;
            System.out.print("第"  + counter + "次输出  " + coef1 + "   " + coef2 + "   "  + coef3 + "   "  + coef4);
            System.out.println("          " + coef4);
            //此条件位置至关重要
            boolean condition = (coef1 == 1)&&(coef2 == 0)&&(coef3 == 0)&&(coef4 == 1);
            if (condition)
            {
                break;
            }
        }
        System.out.println("周期为：" + counter);
    }
    /**
     * 异或操作
     * @param a1
     * @param a4
     * @return
     */
    private static int xorOpe(int a1,int a4)
    {
        if(a1 == a4)
        {
            return 0;
        }
        else 
        {
            return 1;
        }
    }

}

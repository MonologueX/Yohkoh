import java.util.Scanner;
import java.io.*;
public class Test
{
    public static int Sum(int num)
    {
        if (num == 1)
        {
            return 1;
        }
        else 
        {
            return num + Sum(num-1);
        }
    }

    public static void Swap(int left, int right)
    {
        int temp = left; 
        left = right;
        right = temp;
    }

    public static int Partion(int array[], int left, int right)
    {
        int begin = left;
        int end = right;
        int key = array[right];
        while (begin < end)
        {
            while (begin < end && array[begin] <= key)
            {
                ++begin;
            }
            while (begin < end && array[end] >= key)
            {
                --end;
            }
            if (begin < end)
            {
                int temp = array[begin]; 
                array[begin] = array[end];
                array[end] = temp;
            }
        }
        int temp = array[begin]; 
        array[begin] = array[right];
        array[right] = temp;
        return begin;
    }
    public static void QuicklySort(int array[], int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int div = Partion(array, left, right);
        QuicklySort(array, left, div - 1);
        QuicklySort(array, div + 1, right);
    }
    public static void main(String [] args) throws IOException
    {
        int array[] = {5, 4, 6, 9, 1};
        for (int i = 0; i < 5; i++)
        {
            System.out.print(array[i]+"\t");
        }
        System.out.println();
        QuicklySort(array, 0, 4);
        for (int i = 0; i < 5; i++)
        {
            System.out.print(array[i]+"\t");
        }
        System.out.println();
        //Scanner input = new Scanner(System.in);
        //System.out.print("请输入一个整数：");
        //int num = input.nextInt();
        //int sum = Sum(num);
        //System.out.println("1+ ... "+num+" = "+sum);
        //System.out.print("请输入一个字符串：");
        //String str = input.nextLine();
        //System.out.println(str);
        //System.out.print("请输入一个字符串：");
        //str = input.next();
        //System.out.println(str);
        
        //boolean temp = true;
        //String s = "hello word";
        //int a = 10;
        //double b = 1.3;
        //int a = 1;
        //int b = 0;
        //int c = 0;
        //b = a++;
        //a = 1;
        //c = ++a;
        //System.out.print(b+"\t");
        //System.out.print(c+"\n");

        //String s = "hello";
        //Scanner input = new Scanner(System.in);
        //String s = input.next();
        //if (s.equals("o"))
        //{
        //    System.out.println("equal");
        //}
        //else 
        //{
        //    System.out.println("not equal");
        //}
        //char str = (char)System.in.read();


    }
}

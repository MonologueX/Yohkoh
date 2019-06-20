public class Mul
{
    public static void TestMul(int row)
    {
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                System.out.print(i+"*"+j+"="+i*j+" ");
            }
            System.out.println();
        }
    }
    public static void main(String [] args)
    {
        TestMul(3);
    }
}

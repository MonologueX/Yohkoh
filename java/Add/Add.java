public class Add
{
    public static double add(double a, double b)
    {
        return a+b;
    }
    public static int add(int a, int b)
    {
        return a+b;
    }
    public static void main(String [] args)
    {
        int a = 10;
        int b = 20;
        int sum = add(a, b);
        System.out.println(sum);
        double a_ = 1.3;
        double b_ = 1.2;
        double sum2 = add(a_, b_);
        System.out.println(sum2);
    }
}

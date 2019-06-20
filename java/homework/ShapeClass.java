class Circle3
{
    static double PI = 3.14159265;
    int radius;
    public double area()
    {
        return PI*radius*radius;
    }
}
public class ShapeClass
{
    public static void main(String args[])
    {
        double c;
        Circle3 x = new Circle3();
        x.radius = 5;
        c = 2*x.PI*x.radius;
        System.out.println("c+"+c);
        // free x;
    }
}

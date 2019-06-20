class Parent
{
    void printMe()
    {
        System.out.println("parent");
    }
}

class Child extends Parent 
{
    void printMe()
    {
        System.out.println("child");
    }
    void printAll()
    {
        super.printMe();
        this.printMe();
        printMe();
    }

}
public class Test
{
    public static void main(String args[])
    {
        Child c = new Child();
        c.printAll();
//        int i = 1;
//        int j = 10;
//        do 
//        {
//            if (i++ > --j)
//            {
//                continue;
//            }
//        }
//        while (i < 5);
//        System.out.println("i=:"+i+"andj="+j);
    }
}

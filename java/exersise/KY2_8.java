class KY2_8
{ 
    public static void main (String args[]) 
    { 
        int h , c; 
        System.out.println("摄氏温度 华氏温度"); 
        for (c = 0; c <= 40; c += 5) 
        { 
            h = c * 9 / 5 + 32; 
            System.out.println(" "+c+"          "+h); 
        } 
    } 
}

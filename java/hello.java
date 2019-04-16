class KY2_10 
{ 
    public static void main(String args[]) 
    { 
        int n = 1, sum = 0; 
        do 
        { 
            sum += n++; 
        } while (n <= 100); 
        System.out.println("1+2＋...+100 ="+sum);
    } 
}

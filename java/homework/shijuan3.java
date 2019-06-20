import java.util.*;
public class Test5
{
    public static void main(String args[])
    {
        String num[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
        Vector<String> aVector = new Vector<String>(java.util.Arrays.asList(num));
        Enumeration<String> nums = aVector.elements();
        while (nums.hasNext())
        {
            String aString = (String)nums.nextElement();
            if (aString.length() > 4)
            {
                aVector.remove(aString);
            }
        }
        System.out.println("After Vector:"+aVector);
    }
}

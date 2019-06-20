/***********************************
 * 文件名称: 
 * 文件描述: 读写文件 
 * 编译环境: Linux
 * 作者相关: 心文花雨
***********************************/
import java.io.*;
public class Test4 
{
    public static void main(String[] args) throws IOException
    {
        String path = "/home/ch/workspace/Yohkoh/java/homework/caihao.txt";
        File file = new File(path);
        if(!file.exists()){
            file.getParentFile().mkdirs();          
        }
        file.createNewFile();
        System.out.println("创建成功");

        // write
        FileWriter fw = new FileWriter(file, true);
        BufferedWriter bw = new BufferedWriter(fw);
        bw.write("hello java\n");
        bw.write("hello java\n");
        bw.write("hello java\n");
        bw.write("hello java\n");
        bw.write("hello java\n");
        bw.flush();
        bw.close();
        fw.close();

        // read
        FileReader fr = new FileReader(file);
        BufferedReader br = new BufferedReader(fr);
        String str = "";
        while ((str = br.readLine()) != null)
        {
            System.out.println(str);
        }
    }
}

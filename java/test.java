// （1）声明Java不同数据类型变量的程序代码：
public class KY2_1 { 
    public static void main(String args[]) { 
      byte b=0x55; 
      short s=0x55ff; 
      int i=1000000; 
  long l=0xffffL; 
      char c='a'; 
      float f=0.23F; 
      double d=0.7E-3; 
      boolean B=true; 
      String S="这是字符串类数据类型"; 
      System.out.println("字节型变量 b = "+b); 
      System.out.println("短整型变量 s = "+s); 
      System.out.println(" 整型变量 i = "+i); 
      System.out.println("长整型变量 l = "+l); 
      System.out.println("字符型变量 c = "+c); 
      System.out.println("浮点型变量 f = "+f); 
      System.out.println("双精度变量 d = "+d); 
      System.out.println("布尔型变量 B = "+B); 
      System.out.println("字符串类对象 S = "+S); 
    } 
  } 

// （2）了解变量的适用范围
     public class KY2_2 { 
     static int i=10; 
       public static void main(String args[]) { 
            { 
                int k=10; 
               System.out.println("i="+i); 
              System.out.println("k="+k); 
             } 
          System.out.println("i="+i); 
          System.out.println("k="+k); 
          //编译时将出错，已出 k 的使用范围 
         } 
 }

// （3）编写一个使用运算符、表达式、变量的程序
class KY2_3 { 
        public static void main(String args[]) { 
          int a=25, b=20, e=3, f=0; 
          boolean d=a<b; 
          System.out.println("a=25,b=20,e=3,f=0"); 
          System.out.println("因为关系表达式 a<b 为假，所以其逻辑值为 ： "+d); 
          if (e!=0 && a/e>5) 
             System.out.println("因为 e 非 0 且 a/e 为 8 大于 5，所以输出  a/e＝ "+a/e); 
          if (f!=0 && a/f>5) 
             System.out.println("a/f = "+a/f); 
          else 
            System.out.println("因为 f 值为 0，所以输出 f = "+f); 
        } 
      } 
// （4）使用表达式语句与复合语句
//  1． 建立包含表达式语句程序，源代码如下。
      class KY2_4{ 
          public static void main(String[] args) { 
              int k, i=3, j=4; 
               k=20*8/4+i+j*i; 
               System.out.println("表达式（20*8/4+i+j*i）＝"+k); 
          } 
      } 
// 2．建立包含复合语句程序，源代码如下。
 class KY2_5{ 
          public static void main(String args[]) { 
          int k, i=3, j=4; 
          k=i+j; 
          System.out.println("在复合块外的输出 k="+k); 
            { 
              float f; 
              f=j+4.5F; 
              i++; 
              System.out.println("在复合块内的输出 f="+f); 
              System.out.println("在复合块内的输出 k="+k); 
            } 
            System.out.println("在复合块外的输出 i="+i); 
          } 
      } 
// （5）使用选择语句
//   1．使用 if...else 语句 
// 程序功能：使用 if...else 语句构造多分支，判断某一年是否为闰年。闰年的条件是符合下面二者之一：能被 4 整除，但不能被 100 整除；能被 4 整除，又能被 100 整除。 
// 编写源程序文件，代码如下。
    public class KY2_6 { 
        public static void main(String args[]) { 
          boolean leap; 
          int year=2005; 
          if ((year%4==0 && year%100!=0) || (year%400==0)) // 方法 1 
             System.out.println(year+" 年是闰年"); 
          else 
          System.out.println(year+" 年不是闰年"); 
          year=2008; // 方法 2 
          if (year%4!=0) 
             leap=false; 
          else if (year%100!=0) 
             leap=true; 
          else if (year%400!=0) 
             leap=false; 
          else 
             leap=true; 
          if (leap==true) 
             System.out.println(year+" 年是闰年"); 
          else 
             System.out.println(year+" 年不是闰年"); 
          year=2050; // 方法 3 
          if (year%4==0) { 
             if (year%100==0) { 
               if (year%400==0) 
                 leap=true; 
               else 
                 leap=false; 
              } 
          else 
             leap=false; 
       } 
    else 
       leap=false; 
    if (leap==true) 
       System.out.println(year+" 年是闰年"); 
    else 
       System.out.println(year+" 年不是闰年"); 
   } 
  } 
// 2．使用 switch 语句 
// 程序功能：在不同温度时显示不同的解释说明。
// 程序源代码如下。 
   class KY2_7{ 
         public static void main(String args[]) { 
         int c=38; 
     switch (c<10?1:c<25?2:c<35?3:4) { 
          case 1: 
             System.out.println(" "+c+"℃ 有点冷。要多穿衣服。"); 
          case 2: 
             System.out.println(" "+c+"℃ 正合适。出去玩吧。"); 
          case 3: 
             System.out.println(" "+c+"℃ 有点热。"); 
          default: 
            System.out.println(" "+c+"℃ 太热了!开空调。"); 
        } 
      } 
   } 
// （6）使用循环语句
// 	1． for 循环语句练习 
// 程序功能：按 5 度的增量打印出一个从摄氏温度到华氏温度的转换表。 
// 程序源代码如下。 
        class KY2_8{ 
            public static void main (String args[]) { 
              int h,c; 
              System.out.println("摄氏温度 华氏温度"); 
              for (c=0; c<=40; c+=5) { 
                h=c*9/5+32; 
                System.out.println(" "+c+"          "+h); 
              } 
            } 
        } 
// 2 while 循环语句练习 
// 程序功能：运行程序后从键盘输入数字 1/2/3 后，可显示抽奖得到的奖品；如果输入其它数
// 字或字符显示“没有奖品给你!”。 
// 程序源代码如下。 
//      import java.io.*; 
//      class KY2_9 { 
//          public static void main(String args[]) throws IOException { 
//            char ch; 
//       System.out.println("按 1/2/3 数字键可得大奖!"); 
//       System.out.println("按空格键后回车可退出循环操作."); 
//       while ((ch=(char)System.in.read())!=' ')
// { 
//         System.in.skip(2);     // 跳过回车键 
//         switch (ch) { 
//           case '1': 
//             System.out.println("恭喜你得大奖，一辆汽车!"); 
//             break; 
//           case '2': 
//             System.out.println("不错呀，你得到一台笔记本电脑!"); 
//             break; 
//           case '3': 
//             System.out.println("没有白来，你得到一台冰箱!"); 
//             break; 
//           default: 
//             System.out.println("真不幸，你没有奖品!下次再来吧。"); 
//         } 
//       } 
//     } 
//   }
//
//// 3．do…while 循环语句练习 
//// 程序功能：求 1＋2＋…+100 之和，并将求和表达式与所求的和显示出来。 
//// 程序源代码如下。 
//           class KY2_10 { 
//             public static void main(String args[]) { 
//                int n=1, sum=0; 
//                do { 
//                         sum+=n++; 
//                 } 
//                while (n<=100); 
//                System.out.println("1+2＋...+100 ="+sum);
//              } 
//           } 
//// 4．多重循环练习 
//// 输出九九乘法表的程序，源代码如下。 
//     public class KY2_11 
//     { 
//      public static void main(String args[]) 
//         { 
//          int i,j,n=9; 
//          System.out.print("    *    |"); 
//          for (i=1;i<=n;i++) 
//              System.out.print("    "+i); 
//              System.out.print("\n-------|"); 
//         for (i=1;i<=n;i++) 
//              System.out.print("----"); 
//              System.out.println(); 
//       for (i=1;i<=n;i++) 
//       { 
//           System.out.print("     "+i+"    |"); 
//           for (j=1;j<=i;j++) 
//             System.out.print(" "+i*j); 
//           System.out.println(); 
//       } 
//   } 
//}
//

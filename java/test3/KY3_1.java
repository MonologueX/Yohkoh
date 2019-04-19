import java.awt.*; 
import java.awt.event.*; 
import java.applet.Applet; 

public class KY3_1 extends Applet implements ActionListener 
{ 
    Label label1 = new Label("+"); 
    Label label2 = new Label("="); 
    TextField field1 = new TextField(6); 
    TextField field2 = new TextField(6); 
    TextField field3 = new TextField(6); 
    Button button1 = new Button("相加"); 

    ///////////////////////////////////////////////
    //  初始化
    ///////////////////////////////////////////////

    public void init() 
    {
        add(field1); 
        add(label1); 
        add(field2); 
        add(label2); 
        add(field3); 
        add(button1); 
        button1.addActionListener(this); 
    } 

    ///////////////////////////////////////////////
    // 处理按钮事件 
    ///////////////////////////////////////////////

    public void actionPerformed(ActionEvent e) 
    { 
        int x = Integer.parseInt(field1.getText()) + Integer.parseInt(field2.getText()); 
        // 数值转换为字符串
        field3.setText(Integer.toString(x));
    } 
} 

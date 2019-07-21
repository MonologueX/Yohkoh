#!/bin/bash 

#i=0;
#((i++))
#echo $i

创建50个文件
i=1
for ((; i <= 50; i++))
do 
    touch file$i
done

#str="you are great man!"
#echo `expr index "$str" are`

#str="hello shell"
#echo ${str:6:10}

#str="shell"
#echo ${#str}

#删除变量
#x=100
#echo $x
#unset x
#echo $x

#只读变量
#readonly x=100
#echo $x
#x=200
#echo $x

#字符串拼接
#str1="hello"
#str2=" word"
#echo $str1${str2} haha

#myint=1234
#myfloat=3.24
#mystr="hello"
#mychar='c'
#
#echo $myint
#echo $myfloat
#echo $mystr
#echo $mychar

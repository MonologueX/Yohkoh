#function MyFun()
#{
#    echo "输入的数为: "
#    echo '$1 => '$1
#    echo '$2 => '$2
#    echo '$0 => '$0
#    echo '$# => '$#
#    echo '$@ => '$@
#    return 1;
#}

#read myint1
#read myint2
#MyFun $myint1 $myint2
#echo $?

#function MyFun()
#{
#    echo "haha"
#    echo "haha"
#}
#ret=`MyFun`
#echo $ret

#for i in {1..10}
#do 
#    set -x
#    touch file.$i
#    set +x
#done

# 数组
#array=(1 2 'hehe')
#echo ${array[0]}
#array[0]='haha'
#echo ${array[0]}

# 数组元素个数
#array=(1 2 'hehe')
#echo ${#array[@]}
#echo ${#array[*]}

# 遍历数组元素个数
#array=(1 2 3)
#array[8]=7
#for (( i = 0; i < ${#array[*]}; i++ ))
#do 
#    echo "$i -> ${array[i]}"
#done
#
#for i in ${array[@]}
#do 
#    echo $i
#done

# 输出重定向
#echo "hehe" > file

#for ((i = 0; i < 10; i++))
#do
#    echo "haha $i" >> file
#done

#for ((i = 0; i < 10; i++))
#do
#    echo "haha $i"
#done > file

# 输入重定向
#while read line
#do
#    echo $line".aaa"
#done

#find / -name test.c 2> /dev/null
#find / -name test.c > out 2>&1

#source ./api.sh
#ret=`Add 10 20`
#echo $ret

#myint=1
#printf "%d\n" $myint

echo $RANDOM

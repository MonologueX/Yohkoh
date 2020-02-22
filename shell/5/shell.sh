#! /bin/bash
# 进度条
#i=0;
#bar=''
#label=('/', '-', '\', '|')
#while [ $i -le 100 ]
#do
#    printf "[%d%%][%c]%s\r" $i ${label[$i%4]} $bar
#    let i++
#    bar=$bar"#"
#    sleep 0.1
#done
# 根据命令行参数计算
if [ $# -lt 3 ]
then
    echo "W:参数太少"
    exit 1
fi

min=$1
max=$1
sum=0
for i in $@
do
    [ $i -lt $min ] && min=$i
    [ $i -gt $max ] && max=$i
    let sum=$sum+$i
done
echo "min="$min
echo "max="$max
#((avg = $sum/$#))
avg=`echo "ibase=10; scale=2; $sum/$#" | bc`
echo "avg="$avg

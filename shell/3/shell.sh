#read mystring 
#case $mystring in 
#    [Ss]tart | -s )
#        echo "start!"
#        ;;
#    'stop' )
#        echo "stop!"
#        ;;
#    * )
#        echo "default!"
#        ;;
#esac

#for i in {0..9}
#do 
#    echo $i
#done

#for i in {0..9} {a..f}
#do 
#    echo $i
#done

#for i in {0..4}{a..c}
#do 
#    echo $i
#done

#i=0
#while [ $i -lt 5 ]
#do 
#    echo $i
#    #(( ++i ))
#    let ++i
#done

#for (( ;; ))
#do 
#    echo "haha"
#    sleep 1
#done

#while :
#do 
#    echo "haha"
#    sleep 1
#done

#while true
#do 
#    echo "haha"
#    sleep 1
#done

#until false
#do 
#    echo "haha"
#    sleep 1
#done

#sum=0
#for i in {1..100}
#do
#    #(( sum += i ))
#    let sum+=i
#done
#echo $sum

#sum=0
#str=""
#for i in {1..100}
#do
#    if [ $i -lt 2 ]
#    then
#        str=$str$i
#    else
#        str=$str" + "$i
#    fi
#    let sum+=i
#done
#echo $str" = "$sum

#sum=0
#str=""
#for (( i=1; i <= 100; i += 2 ))
#do
#    if [ $i -lt 2 ]
#    then
#        str=$str$i
#    else
#        str=$str" + "$i
#    fi
#    let sum+=i
#done
#echo $str" = "$sum

#echo "shift befor"
#echo "\$0 ==> $0"
#echo "\$1 ==> $1"
#echo "\$2 ==> $2"
#echo "\$3 ==> $3"
#echo "\$@ ==> $@"
#echo "\$# ==> $#"
#echo "\$? ==> $?"
#echo "\$$ ==> $$"
#
#shift 2
#
#echo "shift after"
#echo "\$0 ==> $0"
#echo "\$1 ==> $1"
#echo "\$2 ==> $2"
#echo "\$3 ==> $3"
#echo "\$@ ==> $@"
#echo "\$# ==> $#"
#echo "\$? ==> $?"
#echo "\$$ ==> $$"

#while [ $# -ne 0 ]
#do 
#    echo $1
#    shift 1
#done
for i in $@
do 
    echo $i
done

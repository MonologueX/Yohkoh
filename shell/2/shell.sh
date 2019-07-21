#!/bin/bash

#read myint

#test $myint -eq 100
#echo $?

#[ $myint -lt 50 ]
#echo $?
#read mystring

#[ $mystring == "hello" ]
#echo $?
#[ -z $mystring ]
#echo $?

#read mystring
#[ -n $mystring ]
#echo $?
#[ "X"$mysting == "Xhello" ]
#echo $?

#[ -f ./test.c ]
#echo $?

#[ -d ./test ]
#echo $?

#read mystring 
#[ ! "X"$mystring == "Xhello" ]
#echo $?

#read myint
#[ $myint -lt 100 -a $myint -gt 50 ]
#echo $?

#read myint 
#if [ $myint -lt 100 ]
#then 
#    echo "小于100"
#elif [ $myint -lt 150 -a $myint -ge 100  ]
#then
#    echo "100~150"
#else 
#    echo "大于150"
#fi 

#read myint 
#if [ $myint -lt 100 ]
#then 
#    :
#else 
#    echo "haha"
#fi 

read myint 
[ $myint -lt 100 ] && echo "haha"

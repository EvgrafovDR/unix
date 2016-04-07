#!/bin/bash
x1=$1
x2=$2
r=1
until [ "$r" -eq 0 ]
do
   let "r=x1%x2"
   x1=$x2
   x2=$r
done
echo; echo "НОД чисел $1 и $2 = $x1"; echo

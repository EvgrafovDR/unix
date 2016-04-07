#!/bin/bash

m1="1 – список файлов и подкаталогов текущего каталога."
m2="2 – создание нового файла."
m3="3 – переименование файла."
m4="4 – выход из скрипта."

select c in "$m1" "$m2" "$m3" "$m4"
do
case "$c" in
 "$m1" )
 ls
 ;;

 "$m2" )
 echo "Введите имя файла"
 rep=1
 until [ "$rep" -eq 0 ]
 do
 read dfile
 if [ "$dfile" != "" ]
 then
  if [ -e "$dfile" ]
  then
    echo "Такой файл уже существует, попробуйте ввести другое имя"
    rep=1
  else
    rep=0
    touch $dfile
  fi
 else
  rep=0
 fi
 done
 ;;

 "$m3" )
 echo "Введите старое имя файла"
 rep=1
 until [ "$rep" -eq 0 ]
 do
 read rfile
 if [ "$rfile" != "" ]
 then
  if [ ! -e "$rfile" ]
  then
    echo "Такого файла не существует, попробуйте ввести другое имя"
    rep=1
  else
    rep1=1
    echo "Введите новое имя файла"
    until [ "$rep1" -eq 0 ]
    do
     read rfile2
     if [ "$rfile2" != "" ]
     then
      if [ -e "$rfile2" ]
      then
       echo "Такой файл уже существует, попробуйте ввести другое имя"
       rep1=1
       rep=1
      else
       mv $rfile $rfile2
       rep1=0
       rep=0
      fi
     else
      rep1=0
     fi
    done
  fi
 else
  rep=0
 fi
 done
 ;;
 "$m4" )
 break
 ;;
esac
done
echo "До свидания!"
exit 0
#until [ "$r" -eq 0 ]
#do
#   let "r=x1%x2"
#   x1=$x2
#   x2=$r
#done
#echo; echo "НОД чисел $1 и $2 = $x1"; echo

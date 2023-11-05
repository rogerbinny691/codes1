create(){
echo "Enter Address book name"
read ab
res=`ls |grep $ab |wc -w`
if [ $res -gt 0 ]
then
  echo "Error:file is already exist"
else
  touch $ab
fi
}
display(){

echo "Enter Address book name"
read ab
res=`ls |grep $ab |wc -w`
if [ $res -gt 0 ]
then
echo -e "ROLLNO NAME CGPA BRANCH CLASS"
 i=1
 while read line               # reading line
 do
  echo  -e "$i/t$line\n"
  let "i++"
done <$ab
# cat $ab
#for line in $ab
#do
# echo -e "$line\n"
#done
else
   echo "Error:file is already exist"
fi
}

 insert(){
echo "Enter Address book name"
read ab

res=`ls |grep $ab |wc -w`
if [ $res -gt 0 ]
then
 echo -ne "Enter the number of records to create:"
 read num   
for((i=0;i<num;i++))
do
echo " enter roll number of student "  
   read rn  
len=`cat $ab | grep $rn |wc -w`
if [ $len -gt 0 ]
then
echo "error roll no is already exist"
else
   echo " enter name of student "  
   read nm  
   
   echo " enter CGPA of student "  
   read sk  
   echo " enter Branch of student "  
   read eg  
   echo " enter Class of student "  
   read hn  
   record="$rn   $nm   $sk   $eg   $hn "  
   echo $record>>$ab  
fi
done
else
echo "error:file does not exist"
fi
}
 modify(){
echo "Enter Address book name"
read ab
res=`ls |grep $ab |wc -w`
if [ $res -gt 0 ]
then
echo " enter rollnumber of student "  
   read rn  
len=`cat $ab | grep $rn |wc -w`
if [ $len -gt 0 ]
then
echo "Enter Modified Data"
 echo " enter name of student "  
   read nm 
   echo " enter CGPA of student "  
   read sk  
   echo " enter Branch of student"  
   read eg  
   echo " enter class of student "  
   read hn  
   newrecord="$rn   $nm   $sk   $eg   $hn "  
old=`cat $ab | grep $rn`
echo "old record:$old"
echo "new record:$newrecord"
sed -i s/"$old"/"$newrecord"/g $ab
    echo "record modified"
else
  echo "error roll no is already exist"

fi
else
echo "file not exist"
fi
}
 delete(){
echo "Enter Address book name"
read ab
res=`ls |grep $ab |wc -w`
if [ $res -gt 0 ]
then
echo " enter rollnumber of student "  
   read rn  
len=`cat $ab | grep $rn |wc -w`
if [ $len -gt 0 ]
then
old=`cat $ab | grep $rn`
sed -i s/"$old"//g $ab
sed -i '/^$/d' $ab
    echo "record deleted"
else
  echo "error roll no is already exist"

fi
else
echo "file not exist"
fi
}
search(){
echo "Enter Address book name"
read ab
res=`ls |grep $ab |wc -w`
if [ $res -gt 0 ]
then
echo " enter rollnumber of student "  
   read rn  
   echo "printing result "  
   old=`cat $ab | grep $rn`
   echo $old
   else
   echo "record is not found"
   fi
   
}


ans=y
while [ $ans = y ]
do
#clear

echo "*=*=*=*=* MENU *=*=*=*=*"          # display menu
echo "1)Create database "
echo "2)View database   "
echo "3)Insert a record "
echo "4)Delete a record "
echo "5)Modify a record "
echo "6)Result of a particular student "
echo "7)exit"

echo -ne "\nEnter your choice : "
read choice                         # reading choice and call functions

case $choice in
 1)  create ;;
 2) display ;;
 3)   insert ;;
 4) delete ;;
 5) modify ;;
 6)search ;;
 7) exit ;;  
 * ) echo "enter right choice"  
 esac
echo -ne "\nDo you want to continue? (y/n)"
read ans
done




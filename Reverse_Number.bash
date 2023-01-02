
echo "---------- Script to Reverse a given Number ----------"

echo " "

echo "Please Input a Number"

read num

sum=0
rem=0

echo "The given Number is" $num

while [ $num -gt 0 ]
do
    rem=`expr $num % 10`
    sum=`expr $sum \* 10 + $rem`
    num=`expr $num / 10`
done

echo "The Reverse of the given Number is" $sum

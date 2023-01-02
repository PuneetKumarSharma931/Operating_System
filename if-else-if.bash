
echo "---------- Script To find the greatest out of three numbers ----------"

echo "Input First Number"

read num1

echo "Input Second Number"

read num2

echo "Input Third Number"

read num3

if [ $num1 -gt $num2 -a $num1 -gt $num3 ]
then
echo $num1 "is greater then" $num2 "and" $num3
else if [ $num2 -gt $num1 -a $num2 -gt $num3 ]
then
echo $num2 "is greater then" $num1 "and" $num3
else
echo $num3 "is greater then" $num1 "and" $num2

fi
fi
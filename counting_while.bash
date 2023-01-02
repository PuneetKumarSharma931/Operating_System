
echo "Input a number to print digits from 1 to that number!"

read num

i=1
while [ $i -le $num ] 
do
echo $i
i=$(($i+1))
done
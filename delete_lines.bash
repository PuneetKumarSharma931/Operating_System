
echo "Input File Name"

read file
echo ""

echo "Input word to match"

read word

echo ""

echo "Contents of the file before deleting"

echo ""

cat $file


echo ""

echo "Contents of the file after deleting"

echo ""

sed "/$word/d" $file



echo "Input File Name"

read file

echo "Input the Starting Line to Print"

read start

echo "Input the Ending Line to Print"

read end

echo "The Contents of the file are"

sed -n $start,$end\p $file
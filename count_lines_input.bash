
echo "Input File Name"

read file

awk 'BEGIN{c1=0} //{c1++} END{print "Number of lines in the file: ",c1}' $file

awk 'BEGIN{c=0} //{c++} END{print "Number of words in the file: ",c}' RS="[[:space:]]" $file

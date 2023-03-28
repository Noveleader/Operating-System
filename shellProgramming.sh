# Read n strings and display the strings which are palindrome.
# Code:
#!/bin/bash
echo "Enter string: "
read str
len=${#str}
for (( i=$len-1; i>=0; i-- ))
do
 reveres_str="$reveres_str${str:$i:1}"
 
done
if [ "$str" == "$reveres_str" ]
then
 echo "$str is a palindrome"
else
 echo "$str is not a pallindrome"
fi

# Check the given number is prime or not.
# Code:
#!/bin/bash
echo "Enter Number : "
read num
for((i=2; i<=$num/2; i++))
do
 n=$(( num%i ))
 if [ $n -eq 0 ]
 then
 echo "$num is not a prime number."
 exit 0
 fi
done
echo "$num is a prime number.

# Check the given number is Armstrong or not for a 4 digit number. 
# (Ex. Armstrong numbers with 4 digits are 1634, 8208, and 9474)
# Code:
#!/bin/bash
echo "Enter 4 digit number:"
read num
sum=0
temp=$num
while [ $temp -gt 0 ]
do
 c_digit=$((temp % 10))
 sum=$((sum + c_digit*c_digit*c_digit*c_digit))
 temp=$((temp / 10))
done
if [ $num -eq $sum ]
then
 echo "$num is an Armstrong number."
else
 echo "$num is not an Armstrong number."
fi


# Display the factors of the given number
# Code:
#!/bin/bash
echo "Enter number: "
read num
echo "Factors of $num are: "
for (( i=2; i<=$num; i++ ));do
 while [ $((num%$i)) == 0 ];do
 echo $i
 num=$((num/$i))
 done
done

/**
Assuming a 1 KB page size, what are the page numbers and offsets 
for the following logical addresses references. Develop a shell 
script for the same.
 a) 21942
 b) 5500850
Code:
**/
#!/bin/bash
addresses=(21942 5500850)
for address in "${addresses[@]}"
do
 page_number=$((address / 1024))
 offset=$((address % 1024))
 echo "Logical address: $address"
 echo "Page number: $page_number"
 echo "Offset: $offset"
done



#!/bin/bash
:<<'HEADER-COMMENT'
> File              :   bash4.sh
> Project           :   None
> Programmer        :   Braiden Gole
> First version     :   2021-02-18
> Description       :   This is another smaller sample just exploring what
>                       bash scripting is all about.
>
>                       This sample includes a bubble sort algorithm.
HEADER-COMMENT

# Who are you logged in as currently.
whoami

# Who else is logged in currently?
printf "Users in system: "
users

printf "\n-- System user statistics --\n"
w

# Display code with numbered lines along the left hand margin.
printf "\n-- <CODE SAMPLE> | Interprocess Communication --\n"
cat -b sampleFile.txt

printf "\n\nHow many lines, words, characters are in this program ?\n"
wc sampleFile.txt

# Lets change some of the permissions on the sample file in the current directory.
# The command "chmod" can change permissions of files and directories.
# chmod u=(Users can ?) g=(People of your group can ?) o=(Others can ?)
chmod u=r sampleFile.txt

# We have changed permissions so that only users can read to this file.
# Now lets test to see what happens when we try to write to it.
printf "\n"
printf "This is just some random data to feed !" >> sampleFile.txt

# We can change ownership of a file with the command "chown" but I only
# have 1 user on this operating system,

# The result of the line below can change based on your OS.
# This opens up an app called "Image Magick."
# display

# Lets sort an array of numbers manually.
numbers=(-45 100 1 60 -80 300 5 -66 6 66 800)

temp=0
bubble=0
nums=0

while [ $bubble -le 11 ]
do
    for ((nums = 0; nums < 11-bubble-1; nums++))
    do
        if [ "${numbers[nums]}" -gt "${numbers[$((nums+1))]}" ]
        then
            temp="${numbers[nums]}"
            numbers[$nums]="${numbers[$((nums+1))]}"
            numbers[$((nums+1))]="$temp"
        fi
    done
    bubble=$((bubble+1))
done

# Use a for loop to display the sorted set of numbers.
printf "\n> Sorted set: ["
for ((nums = 0; nums < 11; nums++))
do
    printf "%s " "${numbers[nums]}"
done
printf "]\n\n"
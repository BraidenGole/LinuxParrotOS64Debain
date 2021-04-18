#!/bin/bash
:<<'HEADER-COMMENT'
> File              :   track.sh
> Project           :   None
> Programmer        :   Braiden Gole
> First version     :   2021-04-16
> Description       :   This is a small errand app that allows us
>                       to manually record our daily tasks or errands.
>
>   [NOTE]: An update requires the user to correctly enter the line that
>           they want to update as well as entering the matching errand to update
>           in order to properly update an entry.
HEADER-COMMENT

while true; do
    printf "%s\n" "-- Menu --"
    printf "\t%s\n" "1. Create errand."
    printf "\t%s\n" "2. Update errand."
    printf "\t%s\n" "3. Delete errand."
    printf "\t%s\n" "4. Show all errands."
    read -r -p "Selection: " selection
    
    if [ $selection -eq 1 ]
    then
        printf "\nEnter description CTRL + D to end !\n"
        description=$(</dev/stdin)
        echo $description >> braidens_shell_exercise.txt
    elif [ $selection -eq 2 ]
    then
        cat -b braidens_shell_exercise.txt
        echo
        echo
        read -r -p "The line to update: " lineToUpdate
        read -r -p "Enter in the matching errand to update: " matchingErrand

        echo
        printf "\nEnter new description CTRL + D to end !\n"
        newDescription=$(</dev/stdin)

        sed -i "$lineToUpdate s/$matchingErrand/$newDescription/g" braidens_shell_exercise.txt
        
    elif [ $selection -eq 3 ]
    then
        cat -b braidens_shell_exercise.txt
        echo
        echo
        read -r -p "The line to delete: " lineToDelete

        sed -i "$lineToDelete d" braidens_shell_exercise.txt
    elif [ $selection -eq 4 ]
    then
        echo
        cat -b braidens_shell_exercise.txt
        echo
    fi
done


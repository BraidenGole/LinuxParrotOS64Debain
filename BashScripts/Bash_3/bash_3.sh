#!/bin/bash
:<<'HEADER-COMMENT'
> File              :   bash_3.sh
> Project           :   None
> Programmer        :   Briaden Gole
> First version     :   2021-01-26
> Description       :   This is the 3rd sample for bash scripting.
>
>                       Just building random functionality getting
>                       more familiar with the commands and operations.
>
> (Unix / Linux style commands - Tutorialspoint - Special Variables & Shell arrays)
> [SOURCE / REFERENCED]: 
>       https://www.tutorialspoint.com/unix/unix-special-variables.htm
>       https://www.tutorialspoint.com/unix/unix-using-arrays.htm
>
>
> (Mobile Android Application - Basic commands)
> [SOURCE]: https://play.google.com/store/apps/details?id=linux.teach&hl=en&gl=US
HEADER-COMMENT

# Linux style echo %CD% = pwd (Print working directory)
printf "\n"
echo The directory that we are currently in below:
pwd

# Create a read-only like constant variable.
readonly NAME="Braiden"
readonly LASTNAME="Gole"
readonly SCRIPTNAME=$0

# Echo the PID of the current shell.
printf "\n"
echo Process ID: $$
echo Name of script: "$SCRIPTNAME"
echo First name: "$NAME"
echo Last name: "$LASTNAME"

# Echo the last background PID.
echo Last background process ID: $!

# Lets work with some shell arrays.
printf "\nProgramming languages\n"
programmingLanguages=(Python C C# Java)
for language in "${programmingLanguages[@]}"
do
    echo "$language"
done

# Lets look for our bash_3.sh file.
printf "\n"
find aFileWeDoNotHave.txt

# Linux style %ERRORLEVEL% check with a shell style if statement.
if [ $? -eq 1 ]
then
    echo "Not here, thats okay the shell caught the error !"
fi

# Create a file from a directory that we are not in.
touch "$HOME/Desktop/braidens_shell_exercise.txt"

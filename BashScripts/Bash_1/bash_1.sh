#!/bin/bash
:<<'HEADER-COMMENT'
> File            :   bash_1.sh
> Project         :   None
> Programmer      :   Braiden Gole
> First version   :   2021-01-26
> Description     :   This is my first "Bash script" something simple to get started !
>
>       [NOTE]: RUN a ".sh" file by entering what is inside of the square brackets.
>
>           [ bash filename.sh arg1 arg2 arg3 arg4 ]
>
>       Before you run the file it is intended that we fill in the command-line
>       arguments with the following pieces of information.
>
>       1. Name
>       2. Last name
>       3. Favourite video game.
>
> [IMPORTANT]: If you want multiple words to count as (1) argument you have to
>              enter it in with double quotes example below:
>
>              bash filename.sh Braiden Gole "Red Dead Redemption 2"
>
>              Where the Video game is encased in double quotes and we have
>              a total of [3] command-line arguments passed in.
>
>
> [IMPORTANT]: If we need extra HELP ! Or guidance use "--help" example:
>
>              ls --help        // Linux style dir listing command.
>
> HEADER-COMMENT
HEADER-COMMENT

printf "\n> Braiden's Bash Script Exercise:\n"
echo "Account name: $1"
echo "Age of user: $2"
echo "Your favourite video game: $3"
echo "Number of command-line args: $#"
printf "\n"
read -r -p "Press | ENTER | when you are ready to continue..."

# Clear the screen.
clear

# Display the value of an environment variable.
printenv HOME

# Take a linux style directory listing of the HOME variable.
ls -a "$HOME"
printf "\n"
read -r -p "Press | ENTER | when you are ready to continue..."
clear

# Take an entire listing of all of the environment variables 5 line at a time.
printenv | more -n 5
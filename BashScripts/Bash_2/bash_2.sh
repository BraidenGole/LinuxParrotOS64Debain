#!/bin/bash
:<<'HEADER-COMMENT'
> File              :   bash_2.sh
> Project           :   None
> Programmer        :   Braiden Gole
> First version     :   2021-01-26
> Description       :   This is our second bash file.
>
>   You are to first launch the "live server" from VSCode.
>   Then you are to run the command:
>
>   bash bash_2.sh
>
>   When that command is run it will log the results into a text file and then embed
>   the text file from the output of the curl commond to a HTML document.
>   
>   Make sure you are on the right PORT !
>  
>   (Live server extension)
>   [SOURCE]: https://marketplace.visualstudio.com/items?itemName=ritwickdey.LiveServer
HEADER-COMMENT

curl 127.0.0.1:5500 > curlData.txt

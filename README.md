
![alt tag] (https://github.com/justin-chandra/rshell/blob/exec/images/logo.png)  
Logo made with [OnlineLogoMaker.](http://www.onlinelogomaker.com/logomaker/#)  
Rshell imitates BASH, able to execute built in BASH commands.  

##How to Use:  
```
cd rshell/  
git checkout hw2  
make  
./bin/rshell  
```    
Note: Running the rshell within the rshell is not recommended, as it can lead to memory problems.
  
##List of Known Bugs:  
* Executing a command with a connector with a comment directly after (instead of an argument) will result in a segmentation fault. Example:
```
 echo lorem && #ipsum
```

* Executing a command with multiple semicolons and no spaces will result in a segmentation fault. Example: 
```  
lorem;ipsum;dolor
```  
* Executing a test command is nested within multiple sets of parentheses, it will result in a segmentation fault. Example:
```
(((test -e src)))
``` 

##Authors:  
J. Chandra  
A. Der

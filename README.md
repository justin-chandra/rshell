# rshell
![alt tag] (https://github.com/justin-chandra/rshell/blob/exec/images/logo.png)

Rshell imitates BASH, able to execute all the built in BASH commands.

HOW TO USE:  
```
cd rshell/  
make  
./bin/rshell  
```    
Note: Running the rshell within the rshell is not recommended, as it can lead to memory problems.
  
LIST OF KNOWN BUGS:  
	-executing a command with a connector with a comment directly after (and not an argument) will result in a segmentation fault. e.g.
```
 echo lorem && #ipsum
```
  
EXECVP CODE SNIPPET:  
```

```







AUTHORS:  
J. Chandra  
A. Der

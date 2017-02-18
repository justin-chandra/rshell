# rshell
![alt tag] (https://scontent-sjc2-1.xx.fbcdn.net/v/t34.0-12/16522591_1195453097237149_1366364199_n.png?oh=f6a99679fada0549f17583640b47f392&oe=589991F6)

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

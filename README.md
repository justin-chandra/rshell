
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
* executing a command with a connector with a comment directly after (instead of an argument) will result in a segmentation fault. Example:
```
 echo lorem && #ipsum
```
  
##execvp code snippet:  
```c++
char ** vloc = &v[0];
if (execvp(v.at(0), vloc) == -1)
{	
	cout << "-rshell: " << v.at(0) << ": command not found" << endl;
	_exit(1); 
}
```  
##UML Diagram:  
  
![alt tag] (https://github.com/justin-chandra/rshell/blob/exec/images/download.png) 



##Authors:  
J. Chandra  
A. Der

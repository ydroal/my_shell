## my_shell

It is a simple version of the shell used by Linux.
This is project for learning how does Shell work and C language.


## Description
my_shell is a a UNIX command line interpreter. It works under the following conditions,
* No handle special characters : ", ', `, \, *, &, #
* Commands must be on a single line.


## Compilation

```-Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh```


### List of system calls that I use

* ```access``` (man 2 access)
* ```execve``` (man 2 execve)
* ```exit``` (man 3 exit)
* ```fork``` (man 2 fork)
* ```free``` (man 3 free)
* ```getline``` (man 3 getline)
* ```isatty``` (man 3 isatty)
* ```malloc``` (man 3 malloc)
* ```perror``` (man 3 perror)
* ```stat``` (__xstat) (man 2 stat)
* ```strtok``` (man 3 strtok)
* ```wait``` (man 2 wait)
* ```write``` (man 2 write)

## Examples
##### Input
```
ls
```
##### Result
A list of the files in the directory appears.

##### Input
```
exit
```
##### Result
The loop stops and the prompt disappears.




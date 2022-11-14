# SIMPLE SHELL

This project incorporates all topics covered in the ALX-low_level_programming so far, and marks the conclusion of the section of the first trimester of the programme.

## Prerequisites
Only use the following functions and system calls:

```
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)
```

### Installation
```
gcc -Wall -Wextra -Werror -pedantic -g *.c -o hsh
```
`-g` is used for tracing Valgrind errors.


## Usage

Shell should work like this oin interactive mode:


```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## DESCRIPTION OF FILE STRUCTURE
1. [set_unset_env.c](https://github.com/SamuelIbanga5/simple_shell/blob/main/set_unset_env.c) - Includes functions for setting and unsetting an environment variable.
- `find_env` - finds the given environmental variable in the linked list.
- `_unset_env` - Unsets an environmental variable.
- `_set_env` - Sets an environmental variable.
2. [_strtok.c](https://github.com/SamuelIbanga5/simple_shell/blob/main/_strtok.c)
- `t_strlen` - Returns token string length for memory allocating.
- `t_size` - Returns number of delimiters ignoring continuous delimiters.
- `ignore_delm` - Returns a version of string without preceeding delims.
- `_str_tok` - Tokenizes a string and returns an array of tokens.
3. [_exit.c](https://github.com/MelissaN/simple_shell/blob/master/__exit.c) - Includes functions that enable exiting of the shell.
- `c_atoi` - Custom atoi converts string to int.
- `__exit` - Frees user input and then exits main program with a value.

# FSS
## FSS: File Settings Script
------------------------
## What is FSS?
FSS is like MAKE Files but for your projects and environments using .fss files.

------------------------
## Gettings Started with FSS

1) First make a new file in your project named settings.fss

2) Next add FSS code/Commands

3) Run the FSS compiler or runner for scripting 

4) Eset the the executable settings file this the fss interpreter

## FSS Basic Code and Commands
 the most important command in FSS is the:
 ```cmd
 main:FILE and admin.main:FILE
 ```
 using ``admin.main:`` will run the core file as admin and main will run it as client. 

## FSS and Python

FSS has built in support for pip pkgs and setup. Using:
```cmd
pip: mypkg,mypkg2,!END
```
will download the packafes mypkg and mypkg2 it is important to add !END to list commands or your last file will not register!

## CMD 

Your can run windows CMD with the following command line:
```cmd
cmd:MY COMMANDS
```
Using this will run CMD 

## Windows OS Support with FSS

Whant your project to only be used on certain platforms use:
```cmd
winos:WINOS
```
This is only for windows and not for MAC support.

The following Windows platforms are supported in FSS format:
```cmd
win10
win11
win7
win8
winxp
winserver
winvista
and(or) all
```

## Hiding Script pop up with FSS

Using the command:
```cmd 
showcon:True/False
```
Will hide or show the setup windows

## Removing Files
 The command ```del:FILE``` will remove files in the project environment

## Copying Files 
using the following command will copy text from file to another one:
```cmd
mov:FILE1>FILE2
```

## Making Files

To make a new file using the follow command: 
```cmd
makefile:FILE.txt
```
## Writing Files
When it comes to writing to files there are two ways to write. Using the command: 
```cmd 
write:FILE
``` 
will override all existing text in the given file. On the other hand the command:
```cmd 
awrite:FILE
```
will append all text in the given file. 
## Braking Files

The ```brake``` command with no input takes place in a file when a cool down of commands in needed in the compiler. The brake command and prevent errors before they happen in a file as shown below. 
```cmd
makefile:FILE
write:FILE>Hello Mom
write:FILE>Hello Dad
brake
write:FILE>Hello Grandma
write:FILE>Hello Grandpa
```
## Renaming Files
There is no main command for renaming command in FSS but there are still commands to get the same goal shown below:
```cmd
mov:FILE1>FILE2
del:FILE1
```
## Downloading outside code

To grab github raw source and save it or anyother file handing source site use: 
```cmd
make-source:FILE>DOWNLOADURL
```

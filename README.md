# diceRoller
A simple C library for rolling dice

## You have to compile the program using gcc using the c17 standard.

## Usage:
  ./rolldice -d\<die size\> -c\<dice count\>
 
## Custom Bash Command
 	I would recommend setting up a custom bash command so you can access
	it from anywhere. Mine is as follows:


   function roll() {
	   ./<directory of your install> "$@"
	}



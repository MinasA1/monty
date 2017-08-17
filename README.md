## Monty Project
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project was to create an interpreter for Monty ByteCodes files.

#### Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
push 0
push 1
push 2
  push 3
                     pall
		     push 4
		         push 5
			       push    6
			       pall
```
##### Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$

push 2
  push 3
                     pall

				push 4$

				push 5
			    push 6
```
#### The monty program
`Usage: monty file`
where 'file' is the path to the file containing Monty byte code
##### Compile:
`gcc -Wall -Werror -Wextra -pedantic *.c -o monty`

#### Instructions - Opcodes:

```
push  /*adds the int to stack/queue*/
pall  /*prints all the elements from top to bottom*/
pint  /*prints the top element*/
pop   /*deletes the top element*/
swap  /*swaps the top two elements*/
add   /*adds the top element to its previous one and makes it the top one*/
sub   /*subtractss the top element from previous one and makes it the top one*/
div   /*dividess the top element with previous one and makes it the top one*/
mul   /*multiplies the top element with previous and makes it the top one */
mod   /*modules the top element with previous and makes it the top one*/
nop   /*does nothing*/
pchar /*prints the ascii char with the value of the top element*/
pstr  /*prints all ascii char of the entire list until the 1st non-matching*/
rotl  /*rotates the stack to the top*/
rotr  /*rotates the stack to the bottom*/
stack /*sets push mode to LIFO*/
queue /*sets push mode to FIFO*/

```
#### Comments
Every good language comes with the capability of commenting. When the first non-space character of a line is `#`, line is treated as a comment.

#### Files:
monty.c
monty.h
opcodes.c
opcodes2.c
opcodes3.c
mode.c

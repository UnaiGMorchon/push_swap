*This project has been created as part of the 42 curriculum by patperez*

# LIBFT

## Description
The project involves building a library by recreating commonly used standard C functions. By recreating these functions, you learn how they work by implementing them yourself and learning to use them effectively. This library will further be used and expanded in future assignments.

The functions included in the project are described below.

The first part includes a set of Libc functions with the same prototypes and behaviours of the originals, adhering to the manual page descriptions.

`isalpha:` Checks whether input is an alphabetic character. The  values  returned  are nonzero if input falls into the tested class, and zero if not.

`isdigit:` Checks whether input is a digit. The  values  returned  are nonzero if input falls into the tested class, and zero if not.

`isalnum:` Checks whether input is an alphanumeric character. The  values  returned  are nonzero if input falls into the tested class, and zero if not.

`isascii:` Checks whether input is a 7-bit unsigned char value that fits int the ASCII character set. The  values  returned  are nonzero if input falls into the tested class, and zero if not.

`isprint:` Checks whether input is a printable character. The  values  returned  are nonzero if input falls into the tested class, and zero if not.

`strlen:` Calculates length of a string pointed to by s, excluding '\0' byte.

`memset:` Fills first n bytes of memory area pointed to by s with constant byte c.

`bzero:` Erases data in the n bytes of memory starting at the location pointed to by s by writing zeros ('\0') to that area.

`memcpy:` Copies n bytes from memory area src to memory area dest. if memory areas overlap, content gets overwritten.

`memmove:` Copies n bytes from memory area src to memory area dest. Avoids overlap by copying according to memory occupied.

`strlcpy:` Copies string src onto dst and NUL-terminates the result.

`strlcat:` Concatenates string src to string dst, appending one after the other, according to size, and NUL-terminates the result.

`toupper:` When c is a lowercase letter, returns its uppercase equivalent.

`tolower:` When c is an uppercase letter, returns its lowercase equivalent.

`strchr:` Returns pointer to first occurrence of character c in string s.

`strrchr:` Returns pointer to last occurrence of character c in string s.

`strncmp:` Compares strings s1 and s2 according to their ASCII value, returning 0 if both are equal, a negative value if s1 is less than s2, and a positive value if s1 is greater than s2.

`memchr:` Scans n bytes of memory area pointed to by s for first instance of c.

`memcmp:` Compares n bytes of memory areas s1 and s2 according to their ascii values.

`strnstr:` Searches a string for a substring only for n number of characters.

`atoi:` Converts initial portion of the string pointed to by nptr from ASCII to int.

`calloc:` Allocates memory for an array of nmemb elements of size bytes each and returns pointer to allocated memory. NUL-terminates allocation.

`strdup:` Returns pointer to a new string which is a duplicate of string s. Memory is obtained for new string with malloc.


The second part includes a set of functions that are either not in the Libc, or exist in different form.

`ft_substr:` Allocates memory with malloc and returns substring from s. Substring begins with start (as index) and has max length len. Returns substring.

`ft_strjoin:` Allocates memory and returns new string made by concatenated s1 and s2.

`ft_strtrim:` Allocates memory and returns a copy of s1 with characters in set eliminated from the beginning and the end of s.

`ft_split:` Allocates memory and returns array of strings obtained by dividing string s into substrings using the delim c. Each substring array memory is allocated independently, as well as the array. Returns pointer to NULL.

`ft_itoa:` Converts int to its ASCII equivalent, allocating memory for the conversion.

`ft_strmapi:` Iterates over string applying function f to each character of the string.

`ft_striteri:` Same as strmapi, but iterates and modifies same string instead of creating a new one.

`ft_putchar_fd:` Prints character to file descriptor file.

`ft_putstr_fd:` Prints string to file descriptor file.

`ft_putendl_fd:` Prints new line to file descriptor file.

`ft_putnbr_fd:` Prints number to file descriptor file.

The third part includes functions that use a structure to manipulate linked lists.

`ft_lstnew:` Adds new node to linked list. Uses malloc to allocate memory for new node

`ft_lstadd_front:` Adds new node to the front of linked list.

`ft_lstsize:` Calculates number of nodes in a linked list.

`ft_lstlast:` Returns last node of linked list.

`ft_lstadd_back:` Adds new node to the back of linked list.

`ft_lstdelone:` Deletes content of a node in a linked list.

`ft_lstclear:` Deletes node and all its successors of a linked list. Uses free().

`ft_lstiter:` Iterates through linked list and applies function f to the content of each node.

`ft_lstmap:` Iterates through a list, applies function f to the content of each node, and creates new list resulting of the successive applications of function f.


## Instructions
The project is written in C and requires the cc compiler and make. The instructions to install are as follows:
* Clone the repository linked here through the Terminal:
```bash
git@vogsphere.42urduliz.com:vogsphere/intra-uuid-72e12e5f-e07e-4458-b77e-6ec7d0d7ecb8-7378129-patperez
```
* Compile the library with the command "make". 
```bash
make
```
This will generate the libft.a file.

To use this library, include the header in your C files and link the library during compilation:
```
#include "libft.h"
```
Compile your code with:
```
cc main.c -L. -lft -o my_program
```
Other commands are:
* `make clean:` Removes all object files (.o).
* `make fclean:` Removes object files and the library file (libft.a).
* `make re:` Recompiles the entire project.

## Resources
A series of tutorial websites were used in the creation of this project, being the most often consulted these:
* ``` www.geeksforgeeks.org```
* ``` www.w3schools.com```
* ``` www.stackoverflow.com```
* ``` www.pythontutor.com```

Use of AI:
The AI was used in these limited instances:
* Occasionally used to define or describe words or concepts with more clarity than could be found online after research provided with insufficient understanding.
* During the replication of the `ft_split` exercise to aid in the search of an error that could not be found on the code after several days of search.
* To aid with the initial draft of this `README.md` to better understad the structure of the file.

Peer support:

Several of my peers provided invaluable support through the creation of this project, aiding through the explanation of exercises, debugging, and brainstorming.

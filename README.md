#ft_printf

## Overview 
> 이 프로젝트는 'printf' 함수를 똑같이 구현한 것 입니다.

## Mandatory part

-The prototype of ft_printf should be int ft_printf(const char *, ...);
-You have to recode the libc’s printf function
-It must not do the buffer management like the real printf
-It will manage the following conversions: cspdiuxX%
-It will be compared with the real printf
-You must use the command ar to create your librairy, using the command libtool is forbidden.


A small description of the required conversion:

- %c print a single character.

- %s print a string of characters.

- %p The void * pointer argument is printed in hexadecimal.

- %d print a decimal (base 10) number.

- %i print an integer in base 10.

- %u print an unsigned decimal (base 10) number.

- %x print a number in hexadecimal (base 16), with lowercase.

- %X print a number in hexadecimal (base 16), with uppercase.

- %% print a percent sign.

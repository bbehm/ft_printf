# ft_printf - A Hive Helsinki project

ft_printf is the printf function coded from scratch in pure C.
The only library functions used are:
- `malloc`
- `free`
- `exit`
- The functions of `man 3 stdarg`

# Specs

My ft_printf can handle the following format specifiers:

Conversion | Flags | Description
------------ | ------------- | --------------
%c | - | Single character
%s | - | String of characters
%p | - | Pointer
%i | hh, h, l, ll | Integer, defaults to decimal
%d | hh, h, l, ll | Decimal base 10
%o | hh, h, l, ll | Octal
%x or %X | hh, h, l, ll | Hexadecimal
%f | l, L | Floating point
%% | - | Prints percent %



# ft_printf - A Hive Helsinki project

ft_printf is the printf function coded from scratch in pure C.
The only library functions used are:
- `malloc`
- `free`
- `exit`
- The functions of `man 3 stdarg`

# Specs


`%[flag][min width][precision][length modifier][conversion specifier]`

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

The length specifiers explained:

Length Specifier | %d, %i | %o, %x, %X | %f
--------- | ------------ | --------- | ----------
hh | signed char | unsigned char | -
h | short int | unsigned short int | -
l | long int | unsigned long int |
ll | long long int | unsigned long long int |
L | - | - | long double

The following flags are also handled:

Flag | Description
-------- | -----------
'#' | Adds prefixes or shows decimal point 
'0' | Pad with leading zeros
'-' | Left justify
'+' | Always display sign
' ' | Display space if no sign

Other features:
- __precision__
- __minimum field-width__
- __wildcard (*)__

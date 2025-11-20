tester used:
https://github.com/paulo-santana/ft_printf_tester
https://github.com/Tripouille/printfTester

• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.

Flags = "-0."
Additional Flags = "# +"

For c allowed flags combination: '-'.
For s allowed flags combination: '-', '.', ' ', 'w'.
For d/i allowed flags combination: '-', '.', ' ', '+', '0', 'w'
For u allowed flags combination: '-', '.', ' ', '0', 'w'
For p allowed flags combination: '-', ' ', '0', 'w'
For x/X allowed flags combination: '-', '.', '0', 'w', '#'
[
	w (s, d, i, u, p, x, X):
	width is the with of the string the printf will print on the terminal, (width - len(str)) will be filled by 0 for 0 padding, ' ' if 0 is not used on left side of the len (str) and is '-' is used padding is done on the right side.

	- (c, s, d, i, u, p, x, X):
	value is right padded by (width - len(str)) ' ' space character if width > len(str).
	if - is used with 0, 0 padding is ignored.

	. (c, s, d, i, u, p, x, X):
	. is called precision, is usually followed by a int vale, if no integer provided, precision is 0.
	for s, the int value tell the maximum number of character to be printed.
	for d, i, u, x, X, the int value tell the minimum number of character to be printed. If len (int str) < precision, the int str is left padded by '0'. If int is negative, '-' is printed before 0 and it is not part of the precision.

	0 (d, i, u, p, x, X): 
	value is padded with 0 time by width if width > len(int str).
	if - is used with 0, 0 padding is ignored.
	if . is used with 0, 0 padding is ignored, if width > precision, ' ' padding is used for (width - precision) always.

	' ' (s, d, i, u):
	a blank is left before positive number or empty string.
	if '+' and ' ' used, '+' overrides the ' '.
	if ' ' and 0 is given, the left most '0' of width is replaced by ' '.

	+ (d, i):
	sign of the int is placed before the string.

	# (x, X):
	if provided int is non-zero, 0x/0X is added before the integer string.
]

%-10c : value of c is left padded by (10 - len(c)) ' ' character, if len(c) > 10, no padding will be used;


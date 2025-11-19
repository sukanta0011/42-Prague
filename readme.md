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

%-10c : value of c is left padded by (10 - len(c)) ' ' character, if len(c) > 10, no padding will be used;


# ft_printf 

A custom implementation of the C standard library `printf` function, developed as part of the 42 school curriculum. This project covers advanced string manipulation, variadic arguments (`stdarg.h`), and strict adherence to formatting flags, widths, and precisions.

## 📋 Features & Conversions

The function mimics the standard `printf` and handles the following mandatory conversions:

| Conversion | Description |
| :--- | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string (as defined by the common C convention). |
| `%p` | Prints the `void *` pointer argument in hexadecimal format. |
| `%d` | Prints a decimal (base 10) number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format. |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format. |
| `%%` | Prints a percent sign. |

---

## 🛠️ Flags & Combinations Matrix

The project implements full support for **Width**, **Precision**, and the **Bonus Flags** (`-`, `0`, `.`, `#`, `+`, ` `). 

### Allowed Matrix per Conversion

| Specifier | Allowed Flags / Modifiers |
| :---: | :--- |
| **`%c`** | `-`, `w` |
| **`%s`** | `-`, `.`, ` `, `w` |
| **`%d` / `%i`** | `-`, `.`, ` `, `+`, `0`, `w` |
| **`%u`** | `-`, `.`, ` `, `0`, `w` |
| **`%p`** | `-`, ` `, `0`, `w` |
| **`%x` / `%X`** | `-`, `.`, `0`, `w`, `#` |

---

## 📖 Flag Behavior Rules

### 1. Modifiers (`w` and `.`)
* **`w` (Width)**: Specifies the minimum field width to print. If the output string length is less than the width, it is padded with spaces `' '` on the left.
* **`.` (Precision)**: Followed by an integer (defaults to `0` if empty).
  * **For `%s`**: Specifies the *maximum* number of characters to print (truncates the string).
  * **For integers (`d, i, u, x, X`)**: Specifies the *minimum* number of digits to print. If the number is shorter, it is left-padded with zeros `'0'`. (A negative sign `-` is placed before these zeros and does not count toward precision).

### 2. Formatting Flags
* **`-` (Left Justify)**: Pads the value on the right side with spaces instead of the left side. **Overrides the `0` flag** if both are present.
* **`0` (Zero Padding)**: Pads the number with leading zeros instead of spaces. 
  * **Ignored** if `-` is present.
  * **Ignored** for numbers if precision `.` is present (defaults to space padding for width).
* **` ` (Space)**: Leaves a blank space before positive numbers or empty strings. **Ignored** if `+` is present.
* **`+` (Plus)**: Forces a sign (`+` or `-`) to be placed before a decimal/integer string. **Overrides the space flag**.
* **`#` (Hash)**: Prefixes non-zero hexadecimal numbers with `0x` (for `%x`) or `0X` (for `%X`). Does nothing if the value is `0`.

---

## 🧪 Critical Edge Cases to Remember

To pass rigorous community testers, the logic must handle these unique behaviors:

* **Zero Value with Zero Precision (`%.d` with `0`)**: 
  If the value is `0` and precision is explicitly `0`, **no digits are printed**. 
  * `ft_printf("%.d", 0)` $\rightarrow$ (Prints 0 characters)
  * `ft_printf("%5.d", 0)` $\rightarrow$ `     ` (Prints 5 spaces)
* **Sign/Prefix vs. Width**:
  Signs (`+`, `-`), spaces (` `), and hex prefixes (`0x`, `0X`) **count toward the total field width**.
  * `ft_printf("%+5d", 42)` $\rightarrow$ `  +42` (2 spaces, 1 sign, 2 digits = 5 total width)
* **Hex Hash with Precision**:
  The precision modifier only dictates the minimum number of mathematical digits, excluding the `0x` prefix.
  * `ft_printf("%#8.4x", 255)` $\rightarrow$ `  0x00ff`

---

## 🔍 Tested With

This implementation has been validated against the following standard 42 testers:
* [printfTester (Tripouille)](https://github.com)
* [ft_printf_tester (paulo-santana)](https://github.com)

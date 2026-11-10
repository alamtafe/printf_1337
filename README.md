*This project has been created as part of the 42 curriculum by alamtafe.*

# Description

The `ft_printf` project is a recreation of the standard C `printf()` function. It supports formatted output using different conversion specifiers.

# Instructions

Compile the project:

```bash
make
```

This creates the `libftprintf.a` static library.

To use it, include `ft_printf.h` in your C file and compile:

```bash
cc main.c libftprintf.a -o program
```

Run the program:

```bash
./program
```

# Algorithm and Data Structures

The algorithm reads the format string character by character. When it finds a `%` character, it checks the next character to identify the conversion specifier.

For each specifier, it retrieves the corresponding argument using `va_arg` and prints it using the appropriate function.

The project uses a `va_list` to access variadic arguments and an integer counter to track the number of characters printed. No complex data structures are needed because the format string is processed sequentially.

This approach is simple and efficient because each character is processed once.

# Supported Conversions

- `%c` — character
- `%s` — string
- `%p` — pointer address
- `%d` and `%i` — signed integer
- `%u` — unsigned integer
- `%x` and `%X` — hexadecimal
- `%%` — percent sign

# Resources

- [printf manual](https://man7.org/linux/man-pages/man3/printf.3.html)
- [C variable arguments](https://en.cppreference.com/w/c/variadic.html)

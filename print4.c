#include "main.h"
/**
 * handle_print - Print based on the given format string and arguments.
 * @format: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: Buffer to handle print.
 * @flags: enabled flags
 * @width:  width.
 * @precision: Precision
 * @size:  specifier
 * Return: 1 or 2;
 */
int handle_print(const char *format, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, len = 0, chars = -1;
	format_t types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexadecimal_upper}, {'p', print_address}, {'S', non_printable},
		{'r', print_reverse}, {'R', print_rot13}, {'\0', NULL}
	};
	for (i = 0; types[i].format != '\0'; i++)
		if (format[*ind] == types[i].format)
			return (types[i].fn(list, buffer, flags, width, precision, size));

	if (types[i].format == '\0')
	{
		if (format[*ind] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (format[*ind - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (format[*ind] != ' ' && format[*ind] != '%')
				--(*ind);
			if (format[*ind] == ' ')
				--(*ind);
			return (1);
		}
		len += write(1, &format[*ind], 1);
		return (len);
	}
	return (chars);
}

/**
 * non_printable - Converts non-printable characters in a string
 * to hexadecimal representation and stores it in a buffer.
 * @list: List of arguments
 * @buffer: Buffer to handle print
 * @flags:  enabled flags
 * @width:  width
 * @precision: Precision
 * @size: Size specifier
 * Return: Number of chars printed
 */



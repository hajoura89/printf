i#include "main.h"

/**
 * print_char - Prints a character
 * @list: List of arguments
 * @buffer: Buffer to print
 * @flags:  enabled flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_char(va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(list, int);

	return (write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string - loops through a string and prints
 * every character
 * @list: List of arguments
 * @buffer: Buffer to print
 * @flags:  enabled flags
 * @width:  Width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_string(va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(list, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}
/**
 * print_percent - Prints a percent
 * @list: List of arguments
 * @buffer: Buffer to print
 * @flags:  enabled flags
 * @width:  Width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_percent(va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(list);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print an integer value
 * @list: List of arguments
 * @buffer: Buffer to print
 * @flags:  enabled flags
 * @width:  width.
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */

int print_int(va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int neg = 0;
	long int n = va_arg(list, long int);
	unsigned long int nbr;

	n = convert_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	nbr = (unsigned long int)n;

	if (n < 0)
	{
		nbr = (unsigned long int)((-1) * n);
		neg = 1;
	}

	while (nbr > 0)
	{
		buffer[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}

	i++;

	return (write_number(neg, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @list: List of arguments
 * @buffer: Buffer to print
 * @flags:  enabled flags
 * @width:  width.
 * @precision: Precision
 * @size: Size
 * Return: Numbers of char printed.
 */
int print_binary(va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int n, j, i, sum;
	unsigned int u[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(list, unsigned int);
	j = 2147483648; /* (2 ^ 31) */
	u[0] = n / j;
	for (i = 1; i < 32; i++)
	{
		j /= 2;
		u[i] = (n / j) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += u[i];
		if (sum || i == 31)
		{
			char z = '0' + u[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

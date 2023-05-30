#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @list: List of arguments
 * @buffer: Buffer to print
 * @flags:  Enabled flags
 * @width:  width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed.
 */
int print_unsigned(va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int nbr = va_arg(list, unsigned long int);

	nbr = convert_unsigned(nbr, size);

	if (nbr == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (nbr > 0)
	{
		buffer[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}

	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints a number in base 8
 * @list: List of arguments
 * @buffer: Buffer to print
 * @flags:  enabled flags
 * @width:  width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_octal(va_list list, char buffer[],
		int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int nbr = va_arg(list, unsigned long int);
	unsigned long int init_nbr = nbr;

	UNUSED(width);

	nbr = convert_unsigned(nbr, size);

	if (nbr == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (nbr > 0)
	{
		buffer[i--] = (nbr % 8) + '0';
		nbr /= 8;
	}

	if (flags & F_HASH && init_nbr != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints a number in lowercase hexadecimal base,
 * @list: List of arguments
 * @buffer: Buffer to  print
 * @flags:  enabled flags
 * @width:  width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hex(list, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/**
 * print_hexadecimal_upper - Prints an unsigned number
 * in upper hexadecimal notation
 * @list: List of arguments
 * @buffer: Buffer to  print
 * @flags:  enabled flags
 * @width:  width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_hexadecimal_upper(va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hex(list, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
 * print_hex - Converts an unsigned integer to hexadecimal and prints it.
 * Description: This function converts an unsigned integer to
 * its hexadecimal representation and prints it. It supports
 * various formatting options like flags, width, and
 * precision. The converted hexadecimal number is stored in the buffer array.
 * @list: The va_list containing the argument to be printed.
 * @map_to: The mapping array for hexadecimal conversion.
 * @buffer: The buffer to store the converted hexadecimal number.
 * @flags: The flags specifying additional formatting options.
 * @flag_ch: The flag character to be included in the output.
 * @width: The minimum width for the output.
 * @precision: The precision specifier for the output.
 * @size: The size specifier for the conversion.
 * Return: The number of characters written to the output.
 */
int print_hex(va_list list, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int nbr = va_arg(list, unsigned long int);
	unsigned long int init_nbr = nbr;

	UNUSED(width);

	nbr = convert_unsigned(nbr, size);

	if (nbr == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (nbr > 0)
	{
		buffer[i--] = map_to[nbr % 16];
		nbr /= 16;
	}

	if (flags & F_HASH && init_nbr != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsigned(0, i, buffer, flags, width, precision, size));
}



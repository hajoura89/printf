#include "main.h"


/**
 * print_address - Prints the hexadecimal
 * representation of a memory address
 * Description: This function takes a memory address
 * and prints its hexadecimal representation.
 * It supports various formatting options such as width, precision, and flags.
 * The resulting string is stored in the buffer.
 * @list: A va_list containing the arguments
 * @buffer: The buffer to store the formatted output
 * @flags: Flags indicating the formatting options
 * @width: The width of the field
 * @precision: The precision for the field
 * @size: The size of the field
 * Return: The number of characters written to
 * the buffer (excluding the null terminator)
 */
int print_address(va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = 0, pad = ' ';
	int index = BUFF_SIZE - 2, length = 2, pad_start = 1;
	unsigned long addr_num;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(list, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	addr_num = (unsigned long)addrs;

	while (addr_num > 0)
	{
		buffer[index--] = map_to[addr_num % 16];
		addr_num /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (flags & F_PLUS)
		c = '+', length++;
	else if (flags & F_SPACE)
		c = ' ', length++;

	index++;

	return (write_address(buffer, index, length,
				width, flags, pad, c, pad_start));
}


/**
 * print_reverse - Prints a string in reverse.
 * @list: A va_list containing the arguments.
 * @buffer: Unused buffer.
 * @flags: Unused flags.
 * @width: Unused width.
 * @precision: Unused precision.
 * @size: Unused size.
 * Return: The count of characters printed.
 */

int print_reverse(va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(list, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13 - Prints a string using the ROT13 encryption algorithm.
 * @list: A va_list containing the arguments.
 * @buffer: A character buffer.
 * @flags: Integer representing flags.
 * @width: Integer representing width.
 * @precision: Integer representing precision.
 * @size: Integer representing size.
 * Return: The number of characters printed.
 */
int print_rot13(va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char c[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char c1[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; c[j]; j++)
		{
			if (c[j] == str[i])
			{
				x = c1[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!c[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

/**
 * append_hex - Appends the hexadecimal representation
 * of an ASCII code to a buffer.
 * @code: The ASCII code to convert to hexadecimal.
 * @buffer: The buffer to which the hexadecimal
 * representation will be appended.
 * @index: The current index in the buffer.
 *
 * Return: The number of characters appended to the buffer (always 3).
 */
int append_hex(char code, char buffer[], int index)
{
	char to[] = "0123456789ABCDEF";

	if (code < 0)
		code *= -1;

	buffer[index++] = '\\';
	buffer[index++] = 'x';

	buffer[index++] = to[code / 16];
	buffer[index] = to[code % 16];

	return (3);
}






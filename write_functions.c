#include "main.h"

/**
 * write_char - Prints a string
 * @c: char types
 * @buffer: Buffer to print
 * @flags:  Enabled flags
 * @width:  Width.
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int write_char(char c, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0;
	char pad = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		pad = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = pad;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * write_number - Prints a string
 * @neg: List of arguments
 * @ind: char types
 * @buffer: Buffer to print
 * @flags:  enabled flags
 * @width:  width
 * @precision: precision
 * @size: Size
 * Return: Number of chars printed
 */
int write_number(int neg, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char pad = ' ', ch = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (neg)
		ch = '-';
	else if (flags & F_PLUS)
		ch = '+';
	else if (flags & F_SPACE)
		ch = ' ';

	return (write_num(ind, buffer, flags, width, precision,
				len, pad, ch));
}
/**
 * write_num - Write a number
 * @index: Index
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @precision: Precision specifier
 * @len: Number length
 * @pad: Pading char
 * @c: Extra char
 * Return: Number of printed chars.
 */
int write_num(int index, char buffer[],
		int flags, int width, int precision,
		int len, char pad, char c)
{
	int i, pad1 = 1;

	if (precision == 0 && index == BUFF_SIZE - 2 &&
			buffer[index] == '0' && width == 0)
		return (0);
	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = pad = ' ';
	if (precision > 0 && precision < len)
		pad = ' ';
	while (precision > len)
		buffer[--index] = '0', len++;
	if (c != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			if (c)
				buffer[--index] = c;
			return (write(1, &buffer[index], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			if (c)
				buffer[--index] = c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[index], len));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (c)
				buffer[--pad1] = c;
			return (write(1, &buffer[pad1], i - pad1) +
					write(1, &buffer[index], len - (1 - pad1)));
		}
	}
	if (c)
		buffer[--index] = c;
	return (write(1, &buffer[index], len));
}

/**
 * write_unsigned - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of written chars.
 */
int write_unsigned(int is_negative, int ind,
		char buffer[],
		int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1, i = 0;
	char pad = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < len)
		pad = ' ';

	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';

	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = pad;

		buffer[i] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[ind], len) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], len));
		}
	}

	return (write(1, &buffer[ind], len));
}
/**
 * write_address - Write an address
 * @buffer: Arrays of chars
 * @index: Index at which the number starts in the buffer
 * @len: Length of number
 * @width: Width
 * @flags: Flags
 * @pad: the padding
 * @c: extra char
 * @pad1: Index padding
 * Return: Number of written chars.
 */
int write_address(char buffer[], int index, int len,
		int width, int flags, char pad, char c, int pad1)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flags & F_MINUS && pad == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (c)
				buffer[--index] = c;
			return (write(1, &buffer[index], len) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & F_MINUS) && pad == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (c)
				buffer[--index] = c;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], len));
		}
		else if (!(flags & F_MINUS) && pad == '0')
		{
			if (c)
				buffer[--pad1] = c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad1], i - pad1) +
					write(1, &buffer[index], len - (1 - pad1) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (c)
		buffer[--index] = c;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}

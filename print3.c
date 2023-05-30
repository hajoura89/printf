#include "main.h"

/**
 * get_width - Extracts the width from the format string
 * @format: The format string
 * @i: Pointer to the current position in the format string
 * @list: The va_list of arguments
 * Return: The width extracted from the format string
 */
int get_width(const char *format, int *i, va_list list)
{
	int current;
	int width = 0;

	for (current = *i + 1; format[current] != '\0'; current++)
	{
		if (is_digit(format[current]))
		{
			width *= 10;
			width += format[current] - '0';
		}
		else if (format[current] == '*')
		{
			current++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = current - 1;

	return (width);
}
/**
 * get_size - Returns the size of a data type based on a given format
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int current = *i + 1;
	int size = 0;

	if (format[current] == 'l')
		size = S_LONG;
	else if (format[current] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = current - 1;
	else
		*i = current;

	return (size);
}

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int current = *i + 1;
	int precision = -1;

	if (format[current] != '.')
		return (precision);

	precision = 0;

	for (current += 1; format[current] != '\0'; current++)
	{
		if (is_digit(format[current]))
		{
			precision *= 10;
			precision += format[current] - '0';
		}
		else if (format[current] == '*')
		{
			current++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = current - 1;

	return (precision);
}
/**
 * get_flags - scans the format string
 * for specific flags and sets the flag values
 * @format: the format string
 * @i: pointer to the current index in the format string
 * Return: the flag values
 */
int get_flags(const char *format, int *i)
{
	int j, current;
	int flags = 0;
	const char flags1[] = {'-', '+', '0', '#', ' ', '\0'};
	const int flags2[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current = *i + 1; format[current] != '\0'; current++)
	{
		for (j = 0; flags1[j] != '\0'; j++)
			if (format[current] == flags1[j])
			{
				flags |= flags2[j];
				break;
			}

		if (flags1[j] == 0)
			break;
	}

	*i = current - 1;

	return (flags);
}


#include "main.h"
/**
 * _printf - Displays output according to a format
 * Description: the function will call the selectPrintingFunction() to
 * determine which printing function to call depending on the conversion
 * specifiers contained into format
 * @format: format string containing the characters and the specifiers
 * Return: length of the formatted output string
 */
int _printf(const char *format, ...)
{
	int i, p = 0, p1 = 0;
	int flags, width, precision, size, index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[index++] = format[i];
			if (index == BUFF_SIZE)
				printbuffer(buffer, &index);
			/* write(1, &format[i], 1);*/
			p1++;
		}
		else
		{
			printbuffer(buffer, &index);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			p = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (p == -1)
				return (-1);
			p1 += p;
		}
	}

	printbuffer(buffer, &index);
	va_end(list);
	return (p1);
}



#include "main.h"


/**
 * ischar_printable - Checks if a character is printable.
 * @c: The character to be checked.
 * Return: 1 if the character is printable, 0 otherwise.
 */
int ischar_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}


/**
 * is_digit - Checks if a character is a digit.
 * @c: The character to be checked.
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_number - Converts a number to a different size based
 * on the specified size parameter.
 * If size is S_LONG, returns the number as is.
 * If size is S_SHORT, converts the number to a short integer and returns it.
 * Otherwise, converts the number to an integer and returns it.
 * @nbr: The number to be converted.
 * @size: The desired size for the converted number.
 * Return: The converted number.
 */
long int convert_number(long int nbr, int size)
{
	if (size == S_LONG)
		return (nbr);
	else if (size == S_SHORT)
		return ((short)nbr);

	return ((int)nbr);
}


/**
 * convert_unsigned - Converts a number to a different size based
 * on the specified size parameter.
 * If size is S_LONG, returns the number as is.
 * If size is S_SHORT, converts the number to an unsigned
 * short integer and returns it.
 * Otherwise, converts the number to an
 * unsigned integer and returns it.
 * @nbr: The number to be converted.
 * @size: The desired size for the converted number.
 * Return: The converted number.
 */
long int convert_unsigned(unsigned long int nbr, int size)
{
	if (size == S_LONG)
		return (nbr);
	else if (size == S_SHORT)
		return ((unsigned short)nbr);

	return ((unsigned int)nbr);
}

/**
 * printbuffer  - This function prints the contents of the
 * character array buffer to the standard output,
 * starting from the first element up to the element at the
 * index specified by ind.After printing, the index is reset to 0.
 * @buffer: The character array containing the data to be printed.
 * @ind:  A pointer to the index indicating the last element in the buffer.
 * Return: the content
 */
void printbuffer(char buffer[], int *ind)
{
	if (*ind > 0)
		write(1, &buffer[0], *ind);

	*ind = 0;
}

#include <limits.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int len;
	int len2;
	unsigned int ui;
	void *addr;
	int num = 42;
	float floatNum = 3.14159;
	long num1 = 1234567890L;
	unsigned long unum = 4294967295UL;
	short num2 = 32767;
	unsigned short unum2 = 65535;

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Address:[%p]\n", addr);
	printf("Address:[%p]\n", addr);
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("reverse:[%r]\n", "HELLO");
	_printf("ROT13:[%R]\n", "HELLO");
	printf("Zero padding: %08d\n", num);
	_printf("Zero padding: %08d\n", num);
	printf("Left justify: %-8d\n", num);
	_printf("Left justify: %-8d\n", num);
	printf("Long integer: %ld\n", (long)2147483648);
	_printf("Long integer: %ld\n", (long)2147483648);
	printf("Short integer: %hd\n", (short)100);
	_printf("Short integer: %hd\n", (short)100);
	printf("Float with precision: %.2f\n", floatNum);
	_printf("Float with precision: %.2f\n", floatNum);
	printf("Minimum field width: %6d\n", num);
	_printf("Minimum field width: %6d\n", num);
	printf("%ld\n", num1);
	_printf("%ld\n", num1);
	printf("%lu\n", unum);
	_printf("%lu\n", unum);
	printf("%hd\n", num2);
	_printf("%hd\n", num2);
	printf("%hu\n", unum2);
	_printf("%hu\n", unum2);

	return (0);
}


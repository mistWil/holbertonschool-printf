#include "holberton.h"

/**
 * print_dec - prints decimal
 * @args: the argument decimal
 *
 * Return: counter
 */

int print_dec(va_list args)
{
	int value;
	unsigned int abs, a, len;
	unsigned int countn = 1;

	len = 0;

	value = va_arg(args, int);

	if (value < 0)
	{
		len = len + _putchar('-');
		abs = value * -1;
	}
	else
		abs = value;

	a = abs;
	while (a > 9)
	{
		a = a / 10;
		countn = countn * 10;
	}
	while (countn >= 1)
	{
		len = len + _putchar(((abs / countn) % 10) + '0');
		countn = countn / 10;
	}
	return (len);
}


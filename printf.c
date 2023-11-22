#include "main.h"

/**
 * _printf - prints to output according to format
 * @format: character string containing format specification
 *
 * Return: number of characters printed or -1 if format NULL
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0;
	int ctr = 0;
	int (*pDisplay)(va_list va);

	va_start(list, format);
	if (format == NULL)
		return (-1);

	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			ctr++;
			i++;
			continue;
		}
		i++;
		if (format[i] == '\0')
			break; /* Handle case where '%' is at the end of the string */

		pDisplay = isCharFormat(format[i]);
		if (pDisplay != NULL)
		{
			/*This is a known format character*/
			ctr += pDisplay(list);
		}
		else
		{
			_putchar('%');
			_putchar(format[i]);
			ctr += 2;
		}
		i++;
	}

	va_end(list);
	return (ctr);
}


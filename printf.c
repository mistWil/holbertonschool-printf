#include "main.h"


/**
 *_printf - prints to output according to format
 *@format: character string containing format specification
 *
 *Return: number of characters printed or -1 if format NULL
 */

int _printf(const char *format, ...)
{
	va_list list;
	int i = 0;
	int ctr = 0;
	int (*pDisplay)(va_list va);

	va_start(list, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar (format[i]);
			ctr++;
			i++;
			continue;
		}
		i++;
		pDisplay = isCharFormat(format[i]);
		if (pDisplay != NULL)
			ctr += pDisplay(list);
		else
		{
			if (format[i] == '\0')
			{
				ctr = -1;
				continue;
			}
			if (format[i] == '%')
				_putchar('%');
			else
			{
				_putchar(format[i - 1]);
				_putchar(format[i]);
			}
			ctr += 2;
		}
		i++;
	}
	va_end(list);
	return (ctr);
}

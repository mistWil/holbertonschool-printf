#include "main.h"

/**
 * get_func - check for known specifier
 * @format: character to check
 * Return: pointer to function
 */
int (*get_func(const char *format))(va_list)
{
	int i;
	func_t p[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_pct},
		{"d", print_dec},
		{"i", print_dec},
		{NULL, NULL}
	};

	for (i = 0; p[i].t; i++)
	{
		if (*format == *(p[i].t))
		{
			return (p[i].f);
		}
	}
	return (NULL);
}

/**
 *print_char - prints character
 *@args: argument
 *
 *Return: character
 */

int print_char(va_list args)
{

	_putchar(va_arg(args, int));
	return (1);
}


/**
 *print_str - print string
 *@args: arguments
 *Return: string
 */

int print_str(va_list args)
{

	int j;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";
	for (j = 0; str[j]; j++)
	{
		_putchar(str[j]);
	}
	return (j);
}

/**
 *print_pct - print "%"
 *@args : arguments
 *
 *Return: "%"
 */
int print_pct(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}

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
	unsigned int num, a, len;
	unsigned int ctr = 1;

	len = 0;

	value = va_arg(args, int);

	if (value < 0)
	{
		len = len + _putchar('-');
		num = value * -1;
	}
	else
		num = value;

	a = num;
	while (a > 9)
	{
		a = a / 10;
		ctr = ctr * 10;
	}
	while (ctr >= 1)
	{
		len = len + _putchar(((abs / countn) % 10) + '0');
		ctr = ctr / 10;
	}
	return (len);
}

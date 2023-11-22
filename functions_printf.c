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

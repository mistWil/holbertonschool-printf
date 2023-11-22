#include "main.h"

/**
 * is_known_spec - check for known specifier
 * @format: character to check
 * Return: pointer to function
 */
int (*is_known_spec(const char *format))(va_list)
{
	int i;
	t_display display[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"d", print_decim},
		{"i", print_decim},
		{NULL, NULL}
	};

	for (i = 0; display[i].format_type; i++)
	{
		if (*format == *(display[i].format_type))
		{
			return (display[i].fdisplay);
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
int print_percent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}

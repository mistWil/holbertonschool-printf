#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/**
 * struct t_display - Format specifier and associated display function
 *
 * @format_type: Format specifier string.
 * @fdisplay: Pointer to the function for displaying the format.
 *
 */

typedef struct t_display
{
	char *format_type;
	int (*fdisplay)(va_list);
} t_display;

int (*is_known_spec(const char *format))(va_list);
int _putchar(char c);
int _printf(const char *format, ...);
int print_str(va_list args);
int print_char(va_list args);
int print_percent(va_list args);
int print_decim(va_list args);

#endif

#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/**
 * struct t_display - type structure
 * @format_type: pointer to the argument
 * @fdisplay: pointer function associated with the argument
 */
typedef struct 
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

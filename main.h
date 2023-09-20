#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

int _printf(const char *format, ...);
int _putchar(char);
int get_case(va_list vl, const char *);

int print_str(va_list vl);
int print_int(va_list vl);
int print_unsigned(va_list vl);
int print_octal(va_list vl);
int print_hex_x(va_list vl);
int print_hex_X(va_list vl);
int print_char(va_list vl);

int print_string(char *);
int print_integer(int);
int print_unsigned_int(unsigned int);
int print_octal_nums(unsigned int);
int print_hexa_x(unsigned int);
int print_hexa_X(unsigned int);
int print_address(void *);
int print_unknown(const char *);

#endif /* end PRINTF_H */

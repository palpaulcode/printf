#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char);
int print_str(char *);
int print_int(int);
int print_unsigned(unsigned int);
int print_octal(unsigned int);
int print_hex_x(unsigned int);
int print_hex_X(unsigned int);
int print_addr(void *);
int print_unknown(const char *);
int get_case(va_list vl, const char *);

#endif /* end PRINTF_H */

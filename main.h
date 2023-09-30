#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * struct case_s - selects a case and its function
 * @ch: case to use
 * @f: function to use for given case
 */
struct case_s
{
	char *ch;
	int (*f)(va_list vl);
};

typedef struct case_s case_t;

int _printf(const char *format, ...);
int _putchar(char);
int get_case(va_list vl, const char *);

int print_str(va_list vl);
int print_int(va_list vl);
int print_unsgnd(va_list vl);
int print_octal(va_list vl);
int print_hex_x(va_list vl);
int print_hex_X(va_list vl);
int print_addr(va_list vl);
int print_char(va_list vl);
int print_pct(va_list vl);
int print_bin(va_list vl);
int print_rev(va_list vl);
int print_rot13(va_list vl);
int print_S(va_list vl);

int print_string(char *);
int print_integer(int);
int print_unsgnd_int(unsigned int);
int print_octal_nums(unsigned int);
int print_hexa_x(unsigned int);
int print_hexa_X(unsigned int);
int print_address(void *);
int print_unknown(const char *);
int valid_format(const char *);
int print_binary(uintmax_t);
int base_count(unsigned int, int);
char *reverse(char *);
char *rot13(char *);
int print_str_s(char *);

#endif /* end PRINTF_H */

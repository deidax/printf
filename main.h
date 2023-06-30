#ifndef MAIN_H
#define MAIN_H
#ifndef NULL
#define NULL ((void *)0)
#endif
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
int _putchar(char c);
int _put(char *str);
int print_char(va_list args);
int print_string(va_list args);
int print_percentage(va_list args);
int print_empty(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_unsigned_int(va_list args);
int print_unsigned_oct(va_list args);
int print_unsigned_heX(va_list args);
int print_unsigned_hex(va_list args);
int _printf(const char *format, ...);
int (*get_format_func(char c))(va_list);
int get_format(const char * const format);
int check_spec(char f_spec);
int print_int_helper(int n);
int print_binary_helper(unsigned int n);
int print_unsigned_helper(unsigned int n, int base, int lower_case);
#endif

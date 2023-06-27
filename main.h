#ifndef MAIN_H
#define MAIN_H
#ifndef NULL
#define NULL ((void *)0)
#endif
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
int _putchar(char c);
int put(char *str);
void print_char(va_list args);
void print_string(va_list args);
void print_percentage(va_list args);
int _printf(const char *format, ...);
void (*get_format_func(char c))(va_list);
#endif

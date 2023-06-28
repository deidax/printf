#include "main.h"
/**
 * _printf - Custom printf function that prints formatted output to stdout.
 * @format: A pointer to a format string specifying the output format.
 * @...: Additional variadic arguments based on the format string.
 *
 * Description:
 *      The _printf function prints formatted output to stdout based on the
 *      format string and additional variadic arguments. It supports the
 *      following format specifiers: %c (character), %s (string), and %% '%'.
 *      The function returns the total number of characters printed to stdout.
 *
 * Return:
 *      The total number of characters printed to stdout.
 */
int _printf(const char *format, ...)
{
	int num_args;
	va_list args;
	va_list args_copy;
	int (*fun_format)(va_list);
	char f_indicator;
	char f_spec;
	int i = 0;
	int count = 0;

	num_args = get_format(format);
	va_start(args, format);
	va_copy(args_copy, args);
	while (i < num_args)
	{
		f_indicator = format[i];
		f_spec = format[i + 1];
		if (f_indicator == '%' && (f_spec == 'c' ||
					f_spec == 's' ||
					f_spec == '%' ||
					f_spec == 'i' ||
					f_spec == 'd' ||
					f_spec == 'b'))
		{
			fun_format = get_format_func(f_spec);
			count += fun_format(args_copy);
			i++;
		}
		else if (f_indicator == '%' && num_args == 1)
		{
			fun_format = get_format_func('@');
			count += fun_format(args_copy);
		}
		else
		{
			count += _putchar(f_indicator);
		}
		i++;
	}
	va_end(args);
	return (count);
}

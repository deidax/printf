#include "main.h"

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
		if (f_indicator == '%' && (f_spec == 'c' || f_spec == 's' || f_spec == '%'))
		{
			fun_format = get_format_func(f_spec);
			count += fun_format(args_copy);
		}
		else
		{
			count += _putchar(f_indicator);
		}
		_putchar('\n');
		_putchar(f_indicator);
		i++;
	}
	va_end(args);
	return (count);
}

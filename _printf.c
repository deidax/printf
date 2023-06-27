#include "main.h"

int _printf(const char *format, ...)
{
	int num_args;
	va_list args;
	va_list args_copy;
	int (*fun_format)(va_list);
	char f_c;
	int i = 0;

	num_args = get_format(format);
	va_start(args, format);
	va_copy(args_copy, args);
	while (i < num_args)
	{
		f_c = format[i];
		if (f_c == 'c' || f_c == 's')
		{
			fun_format = get_format_func(f_c);
			return (fun_format(args_copy));
		}
		i++;
	}
	va_end(args);
	return (0);
}

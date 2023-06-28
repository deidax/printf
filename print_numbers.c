#include "main.h"
/**
 * print_int - Prints an integer using putchar.
 * @args: A va_list containing the integer argument.
 *
 * Description:
 *      The print_int function is used to print an integer to the standard
 *      output using the putchar function. It takes a va_list as input,
 *      extracts the integer argument using va_arg, and calls a helper function
 *      to handle the printing of the integer.
 *
 * Return:
 *      The total number of characters printed.
 */
int print_int(va_list args)
{
	int v;
	int count = 0;

	v = va_arg(args, int);
	count = print_int_helper(v);
	return (count);
}

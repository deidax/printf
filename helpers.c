#include "main.h"
/**
 * get_format_func - Returns a pointer to a function based on the format.
 *
 * @c: The format string.
 *
 * Description:
 *   The get_format_func function takes an operator string @s as input and
 *   returns a pointer to a function that corresponds to the provided
 *   format.
 *
 * Return:
 *   Pointer to a function that performs the format corresponding to @s.
 */

int (*get_format_func(char c))(va_list)
{
	char opt_char[] = "cs%@idbuo";
	int (*opt_cmd[])(va_list) = {
		print_char,
		print_string,
		print_percentage,
		print_empty,
		print_int,
		print_int,
		print_binary,
		print_unsigned_int,
		print_unsigned_oct
	};
	int i = 0;

	while (opt_char[i] != '\0')
	{
		if (opt_char[i] == c)
		{
			return (opt_cmd[i]);
		}
		i++;
	}
	return (NULL);
}
/**
 * get_format - Get the length of a format string.
 * @format: The format string.
 *
 * Description:
 *   This function calculates the length of the format string @format.
 *   If the format string is NULL, the function returns 0.
 *
 * Return:
 *   The length of the format string, or 0 if @format is NULL.
 */
int get_format(const char * const format)
{
	if (format == NULL)
		return (0);
	return (strlen(format));
}
/**
 * print_int_helper - Helper function to print an integer using putchar.
 * @n: The integer to be printed.
 *
 * Description:
 *      The print_int_helper is a helper function used by other functions
 *      to print an integer to the standard output using the putchar function.
 *      to print each digit of the number.
 *
 * Return:
 *      The total number of characters printed.
 */
int print_int_helper(int n)
{
	int count = 0;
	if (n == INT_MIN)
	{
		count += _putchar('-');
		count += print_int_helper(-(n / 10));
		count += _putchar(-(n % 10) + '0');
	}
	else if (n < 0)
	{
		count += _putchar('-');
		n = -n;
		count += print_int_helper(n);
	}
	else if (n / 10)
	{
		count += print_int_helper(n / 10);
		count += _putchar(n % 10 + '0');
	}
	else
	{
		count += _putchar(n + '0');
	}
	return (count);
}
/**
 * print_binary_helper - Prints the binary representation of an unsigned integer.
 * @n: The unsigned integer to be printed in binary.
 *
 * Description:
 *      The print_binary_helper function is a recursive helper function used to
 *      print the binary representation of the given unsigned integer @n. It
 *      divides the number by 2 recursively and prints the remainder (0 or 1)
 *      using _putchar. The function returns the total number of characters printed.
 *
 * Return:
 *      The total number of characters printed.
 */
int print_binary_helper(unsigned int n)
{
	int count = 0;
	if (n > 1)
		count += print_binary_helper(n / 2);
	count += _putchar((n % 2) + '0');
	return (count);
}
/**
 * print_unsigned_helper - Prints an unsigned integer in the specified base.
 * @n: The unsigned integer to be printed.
 * @base: The base in which to print the number.
 *
 * Description:
 *     The print_unsigned_helper function prints an unsigned integer @n to the
 *     standard output using the putchar function. It recursively divides the
 *     number by @base to extract and print each digit from right to left.
 *
 * Return:
 *     The total number of characters printed.
 */
int print_unsigned_helper(unsigned int n, int base)
{
	int count = 0;

	if (n >= (unsigned int) base)
	{
		count += print_unsigned_helper((n / base), base);
	}
	count += _putchar((n % base) + '0');
	return (count);
}

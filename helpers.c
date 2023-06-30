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
	char opt_char[] = "cs%@idbuoXx";
	int (*opt_cmd[])(va_list) = {
		print_char,
		print_string,
		print_percentage,
		print_empty,
		print_int,
		print_int,
		print_binary,
		print_unsigned_int,
		print_unsigned_oct,
		print_unsigned_heX,
		print_unsigned_hex
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
 * check_spec - Check if a character is a valid format specifier.
 * @f_spec: The character to be checked.
 *
 * Description:
 *   The check_spec function is used to determine if a given character
 *   @f_spec is a valid format specifier for printf-like functions. It
 *   checks if the character matches any of the supported specifiers
 *   including 'c', 's', '%', 'i', 'd', 'b', 'u', 'o', 'X', and 'x'.
 *
 * Return:
 *   Returns 1 if @f_spec is a valid format specifier, otherwise returns 0.
 */
int check_spec(char f_spec)
{
	if ((f_spec == 'c' ||
		f_spec == 's' ||
		f_spec == '%' ||
		f_spec == 'i' ||
		f_spec == 'd' ||
		f_spec == 'b' ||
		f_spec == 'u' ||
		f_spec == 'o' ||
		f_spec == 'X' ||
		f_spec == 'x'))
		return (1);
	return (0);
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
 * @lower_case: if it's greater less than 0 lower characters will be used
 * 	in hex format, if it's greater than   upper case will be used.
 * 	if it's not hex format this variable will be ignored.
 *
 * Description:
 *     The print_unsigned_helper function prints an unsigned integer @n to the
 *     standard output using the putchar function. It recursively divides the
 *     number by @base to extract and print each digit from right to left.
 *
 * Return:
 *     The total number of characters printed.
 */
int print_unsigned_helper(unsigned int n, int base, int lower_case)
{
	int count = 0;
	int r = 0;
	char hex;

	if (n >= (unsigned int) base)
	{
		count += print_unsigned_helper((n / base), base, lower_case);
	}
	r = n % base;
	if ( r < 10 )
	{
		(void) lower_case;
		count += _putchar(r + '0');
	}
	else
	{
		if (lower_case > 0)
			hex = 'A';
		else
			hex = 'a';
		count += _putchar(r - 10 + hex);
	}

	return (count);
}
int print_special_helper(char c)
{
	int count = 0;
	
	if ((c > 0 && c < 32) || c >= 127)
	{
		count += _printf("\x");
		int tmp_count += print_unsigned_helper((unsigned int) c, 16, 1);
		if (tmp_count == 1)
		{
			count += tmp_count + _putchar('0');
		}
	}
	count += _putchar(c);
	return (count);
}

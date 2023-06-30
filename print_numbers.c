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
/**
 * print_binary - Prints an unsigned integer in binary format.
 * @args: The argument list containing the unsigned integer.
 *
 * Description:
 *     The print_binary function takes an argument list and retrieves
 *     an unsigned integer from it. It then prints the binary representation
 *     of the unsigned integer to the standard output using putchar.
 *
 * Return:
 *     The total number of characters printed.
 */
int print_binary(va_list args)
{
	unsigned int v;
	int count = 0;

	v = va_arg(args, unsigned int);
	count = print_binary_helper(v);
	return (count);
}
/**
 * print_unsigned_int - Prints an unsigned integer using putchar.
 * @args: The variadic argument list containing the unsigned integer.
 *
 * Description:
 *      The print_unsigned_int function is used to print an unsigned integer
 *      to the standard output using the putchar function. It extracts each
 *      digit of the unsigned integer and prints them individually.
 *
 * Return:
 *      The total number of characters printed.
 */
int print_unsigned_int(va_list args)
{
	unsigned int v;
	int count = 0;

	v = va_arg(args, unsigned int);
	count = print_unsigned_helper(v, 10, -1);
	return (count);
}
/**
 * print_unsigned_oct - Print an unsigned integer as octal using putchar.
 * @args: The va_list containing the unsigned integer argument.
 *
 * Description:
 *      The print_unsigned_oct function takes an unsigned integer argument
 *      from a va_list and prints it as an octal number using putchar. It
 *      returns the total number of characters printed.
 *
 * Return:
 *      The total number of characters printed.
 */
int print_unsigned_oct(va_list args)
{
	unsigned int v;
	int count = 0;

	v = va_arg(args, unsigned int);
	count = print_unsigned_helper(v, 8, -1);
	return (count);
}
/**
 * print_unsigned_heX - Prints an unsigned int in hexadecimal (uppercase).
 * @args: A variable argument list containing the unsigned int to be printed.
 *
 * Description:
 *   The print_unsigned_heX function takes an unsigned int from the variable
 *   argument list and prints it to the standard output using putchar. The
 *   number is printed in hexadecimal format, with uppercase letters (A-F).
 *   The function returns the total number of characters printed.
 *
 * Return:
 *   The total number of characters printed to the standard output.
 */
int print_unsigned_heX(va_list args)
{
	unsigned int v;
	int count = 0;

	v = va_arg(args, unsigned int);
	count = print_unsigned_helper(v, 16, 1);
	return (count);
}
/**
 * print_unsigned_hex - Prints an unsigned int in hexadecimal (lowercase).
 * @args: A variable argument list containing the unsigned int to be printed.
 *
 * Description:
 *   The print_unsigned_hex function takes an unsigned int from the variable
 *   argument list and prints it to the standard output using putchar. The
 *   number is printed in hexadecimal format, with lower letters (a-f).
 *   The function returns the total number of characters printed.
 *
 * Return:
 *   The total number of characters printed to the standard output.
 */
int print_unsigned_hex(va_list args)
{
	unsigned int v;
	int count = 0;

	v = va_arg(args, unsigned int);
	count = print_unsigned_helper(v, 16, -1);
	return (count);
}

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
	char opt_char[] = "cs";
	int (*opt_cmd[])(va_list) = {
		print_char, print_string
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

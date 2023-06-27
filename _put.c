#include "main.h"
/**
 * _put - Print a string and return the number of characters printed.
 * @str: The input string to be printed.
 *
 * Description:
 *     The `put` function prints the characters of the input string @str
 *     and returns the number of characters printed. If @str is NULL,
 *     it does not print anything and returns 0.
 *
 * Return:
 *     The number of characters printed.
 */
int _put(char *str)
{
	int count = 0;

	if (str != NULL)
	{
		while (*str != '\0')
		{
			putchar(*str);
			str++;
			count++;
		}
		return (count);
	}
	_put("(null)");
}

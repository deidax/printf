#include "main.h"

int main()
{
	int _count = 0;
	int count = 0;
    count = printf("%s  %%\n", "KABOOM!!", 'X');
    _count = _printf("%s  %%\n", "KABOOM!!", 'X');

    count = printf("String:[%s]\n", "I am a string !");
    _count =_printf("String:[%s]\n", "I am a string !");

    	count = printf("%s %c\n", NULL, 'K');
	_count = _printf("%s %c\n", NULL, 'K');
    printf("%i\n", count);
    printf("_ %i\n", _count);
	return (count);
}

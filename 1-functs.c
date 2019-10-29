#include "holberton.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * put_numb - print number
 * @arg: next argument.
 * Return: number of chars printed
 */
int put_numb(va_list arg)
{
int n = va_arg(arg, int);
int div = 1;
int len = 0;
unsigned int num;
if (n < 0)
{
len += _putchar('-');
num = n * -1;
}
else
num = n;
while (num / div > 9)
div *= 10;
while (div != 0)
{
len += _putchar('0' + num / div);
num %= div;
div /= 10;
}
return (len);
}
/**
 * put_bin - print number in binary
 * @arg: next argument.
 * Return: number of chars printerd.
 */
int put_bin(va_list arg)
{
return (binary(va_arg(arg, unsigned int)));
}
/**
 * binary - put_bin helper.
 * @n: int we want to convert.
 * Return: number of chars printed
 */
int binary(unsigned int n)
{
    int z = 0;
    if (n == 0)
    {
    return (z);
    }
    if (n > 0)
    {
    binary(n / 2 );
    putchar((n % 2) + '0');
    z++;
    }
return (z);
}
/**
 * put_rot13 - converts to rot13
 * @arg: The name for va_list
 * Return: String Length.
 */
int put_rot13(va_list arg)
{
	int length = 0, i = 0, j;
	char from[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char to[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *str = va_arg(arg, char *);
	for (i = 0; str[i] != '\0'; i++)
	{
		j = 0;
		while ((from[j] != '\0') && (str[i] != from[j]))
		{
			j++;
		}
		if (str[i] == from[j])
		{
			_putchar(to[j]);
			length++;
		}
		else if (from[j] == '\0')
		{
			_putchar(str[i]);
			length++;
		}
	}
	return (length);
}

#include "holberton.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * Error - prints Error str.
 *
 * Return: Error and new line.
 */
void Error(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}
/**
 * allDigits - checks if all the characters are digits.
 * @arg: the arguments of program.
 * Return: 1 all digits 0 otherwise.
 */
int allDigits(char **arg)
{
	int i, j;

	for (i = 1; i <= 2; i++)
		for (j = 0; arg[i][j]; j++)
		{
			if (arg[i][j] < '0' || arg[i][j] > '9')
				return (0);
		}
	return (1);
}
/**
 * _calloc- initializes memory spaces with zero.
 * @nmemb: string 1.
 * @size: string 2, concatenated to 1
 *
 * Return: pointer to the concatenated string.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *newArray;

	if (nmemb == 0 || size == 0)
		return (NULL);

	newArray = malloc(nmemb * size);
	if (newArray == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
	{
		*(newArray + i) = 0;
	}

	return (newArray);
}
/**
 * main- multiplies 2 positive numbers.
 * @argc: counter of arguments.
 * @argv: vector of arguments
 * Return: ans or Error.
 */

int main(int argc, char **argv)
{
	int i, j, carry, len;
	char *s1 = argv[1];
	char *s2 = argv[2];
	int l1 = 0;
	int l2 = 0;
	int *a, *b, *ans;

	if (argc != 3 || allDigits(argv) != 1)
		Error();
	while (argv[1][l1])
		l1++;
	while (argv[2][l2])
		l2++;
	len = l1 + l2;
	a = (int *) malloc(l1 * sizeof(int));
	b = (int *) malloc(l2 * sizeof(int));
	ans = _calloc(len, sizeof(int));
	if (a == NULL || b == NULL || ans == NULL)
		Error();
	for (i = l1 - 1, j = 0; i >= 0; i--, j++)
		a[j] = s1[i] - '0';
	for (i = l2 - 1, j = 0; i >= 0; i--, j++)
		b[j] = s2[i] - '0';
	for (i = 0; i < l2; i++)
		for (j = 0; j < l1; j++)
			ans[i + j] += b[i] * a[j];
	for (i = 0; i < l1 + l2; i++)
	{
		carry = ans[i] / 10;
		ans[i] = ans[i] % 10;
		ans[i + 1] = ans[i + 1] + carry;
	}
	for (i = l1 + l2; i >= 0; i--)
		if (ans[i] > 0)
			break;
	for (; i >= 0; i--)
		_putchar(ans[i] + '0');
	_putchar('\n');
	free(a), free(b), free(ans);
	return (0);
}

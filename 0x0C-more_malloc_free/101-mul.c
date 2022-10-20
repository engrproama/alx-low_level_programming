#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int isNumber(char *str);
int *int_calloc(int nmemb, unsigned int size);
void multiply(int *product, char *n1, char *n2, int len1, int len2);

/**
  * error - print error message.
  * @code: error code for exit
  * Return: void
  */
void error(int code)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(code);
}

/**
* main - multiplies two numbers recieved through command line.
* @argc: number of command line arguments
* @argv: An array containing the program command line arguments
*
* Return: 0 if success otherwise 1.
*/

int main(int argc, char *argv[])
{
	int *mul, i, j, len1 = 0, len2 = 0;

	if (argc != 3)
		error(98);

	for (i = 1; i < argc; ++i)
	{
		if (!isNumber(argv[i]))
			error(98);
		if (i == 1)
		{
			for (j = 0; argv[i][j]; j++)
				++len1;
		}
		if (i == 2)
		{
			for (j = 0; argv[i][j]; j++)
				++len2;
		}
	}

	mul = int_calloc(len1 + len2, sizeof(int));
	if (mul == NULL)
		error(98);

	multiply(mul, argv[1], argv[2], len1, len2);
	free(mul);

return (0);
}

/**
* isNumber - check if string is number.
* @str: string parameter
*
* Return: 1 if number otherwise 0.
*/

int isNumber(char *str)
{
	int j = strlen(str);

	while (j--)
	{
		if (str[j] > 47 && str[j] < 58)
			continue;
		return (0);
	}
return (1);
}

/**
  * int_calloc - special calloc for int arrays
  * @nmemb: n memb
  * @size: size of array
  * Return: int *
  */
int *int_calloc(int nmemb, unsigned int size)
{
	int *p, n;

	if (nmemb == 0 || size == 0)
		return (NULL);

	/* malloc the space & check for fail */
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);

	for (n = 0; n < nmemb; n++)
		p[n] = 0;

	return (p);
}

/**
  * multiply - perform multiplication
  *
  * @product: int pointer for mul answer
  * @n1: num1 as a string param
  * @n2: num2 as a string param
  * @len1: len of num1
  * @len2: len of num2
  *
  * Return: void
  */

void multiply(int *product, char *n1, char *n2, int len1, int len2)
{
	int i, j, i_n1 = 0, i_n2 = 0, res1, res2, sum, carry;

	/* the long math */
	/* Go from right to left in num1 */
	for (i = len1 - 1; i >= 0; i--)
	{
		sum = 0;
		carry = 0;
		i_n2 = 0;
		res1 = n1[i] - '0';

		/* Go from right to left in num2 */
		for (j = len2 - 1; j >= 0; j--)
		{
			res2 = n2[j] - '0';
			sum = (res1 * res2) + product[i_n1 + i_n2] + carry;
			 product[i_n1 + i_n2] = sum % 10;
			carry = sum / 10;
			i_n2++;
		}

		if (carry > 0)
			product[i_n1 + i_n2] += carry;
		i_n1++;
	}
	i = len1 + len2;
	while (--i > 0 && product[i] == 0)
		;

	if (i == -1)
		_putchar('0');

	while (i >= 0)
		_putchar(product[i--] + '0');
	_putchar('\n');
}

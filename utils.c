#include "main.h"

/**
 * is_printable - evaluating if a char is printable.
 * @c: character to be evaluated.
 *
 * Return: 1 if c is printable , 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - appending ascci in hexadecimal code to buffer.
 * @buffer: array of characters.
 * @i: index where to start to append.
 * @ascii_code: Asscii code.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - verify if char is a digit.
 * @c: character to evaluate
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - casting a num to specified size.
 * @num: num to cast.
 * @size: num indicates type to be casted.
 *
 * Return: casted value of number
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - casting a num to a specified size.
 * @num: num to be casted.
 * @size: num indicates type to be casted.
 *
 * Return: casted value of number.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

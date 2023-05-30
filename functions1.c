#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - printing an unsigned num.
 * @types: lists of arguments.
 * @buffer: the buffer array to handle printing.
 * @flags:  calculating active flags.
 * @width: get the width.
 * @precision: precision and specification
 * @size: the size of specifier
 * Return: how many chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - printing an unsigned num in octal notation.
 * @types: a list of arguments.
 * @buffer: the buffer array to handle printing.
 * @flags:  calculating active flags.
 * @width: get the width.
 * @precision: precision and specification.
 * @size: the size of specifier
 * Return: how many chars to print.
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - printing an unsigned num in hexadecimal notation.
 * @types: a list of arguments.
 * @buffer: the buffer array to handle the print.
 * @flags:  calculating active flags.
 * @width: get the width
 * @precision: precision and specification
 * @size: the size of specifier.
 * Return: num of characters printed.
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - printing an unsigned num in upper hexadecimal notation.
 * @types: alist of arguments
 * @buffer: the buffer array to handle print.
 * @flags:  calculating active flags.
 * @width: get the width.
 * @precision: precision and specification.
 * @size: size of specifier
 * Return: how many chars are printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - printing hexadecimal num in lower or upper.
 * @types: arguments list.
 * @map_to: an array of values to map the num to.
 * @buffer: a buffer array to handle print.
 * @flags:  calculating active flags.
 * @flag_ch: calculating active flags
 * @width: Get the width.
 * @precision: precision and specification.
 * @size: the size specifier.
 * @size: the size specification.
 * Return: Num of chars printed.
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

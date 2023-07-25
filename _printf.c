#include "main.h"
/**
 * _printf - a function that produces output according to a format.
 * @format: is a character string
 * Return:  the number of characters printed
 */
int _printf(const char *format, ...)
{
	int char_counter, length = 0;
	va_list args;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_counter++;
		}
		else
		{
			format++;
			if (*format != '0')
			{
				break;
			}
			if (*format == '%')
			{
				write(1, format, 1);
				char_counter++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				char_counter++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char*);

				while (s[length] != '\0')
				{
					length++;
				}
				write(1, s, length);
				char_counter += length;
			}
		}
		format++;
	}
	va_end(args);
	return (char_counter);
}

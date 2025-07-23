/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhelbig <jhelbig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:19:49 by jhelbig           #+#    #+#             */
/*   Updated: 2024/12/03 11:19:35 by jhelbig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = count + print_char(va_arg(ap, int));
	else if (specifier == 's')
		count = count + print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_number_base((long)va_arg(ap, int), "0123456789", 10);
	else if (specifier == 'u')
		count += print_number_base((long)va_arg(ap, unsigned int),
				"0123456789", 10);
	else if (specifier == 'x')
		count += print_number_base((long)va_arg(ap, unsigned int),
				"0123456789abcdef", 16);
	else if (specifier == 'X')
		count += print_number_base((long)va_arg(ap, unsigned int),
				"0123456789ABCDEF", 16);
	else if (specifier == 'p')
		count += print_pointer(va_arg(ap, void *));
	else
		count = count + write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(format + 1) == '\0')
				return (count);
			else if (*(format + 1) == ' ')
				return (print_char('%'));
			else
				count += print_format(*(++format), ap);
		}
		else
		{
			count = count + write(1, format, 1);
		}
		format++;
	}
	va_end(ap);
	return (count);
}
/*
int	main(void)
{
	int	count;
	count = ft_printf("", 42, 7);
	ft_printf("chars are %d\n", count);
	count = printf("", 42, 7);
	printf("chars are %d\n", count);
	
	ft_printf("number %d, char %c, hex %x, HEX %X\n", 42, '\0', 42, 42);
	printf("number %d, char %c, hex %x, HEX %X\n", 42, '\0', 42, 42);
	
	void *ptr = "wordl";
	ft_printf("pointer %c\n", ptr);
	printf("pointer %c\n", ptr);
	void *ptr2 = "wordl";
	ft_printf("pointer %p\n", ptr2);
	printf("pointer %p\n", ptr2);
	ft_printf("%d % \n", 10);	
	printf("----\n");
	
	void *ptr1 = NULL;
	ft_printf("pointer % world\n", 3126546346562);
	printf("pointer % world\n", 3126546346562);
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabril-h <rabril-h@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:58:43 by rabril-h          #+#    #+#             */
/*   Updated: 2022/03/17 18:54:35 by rabril-h         ###   ########.bcn      */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_printf_s(char *str)
{
	int	iprint;

	iprint = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[iprint])
		iprint += ft_putchar(str[iprint]);
	return (iprint);
}

int	ft_putnbr(int nb, int c)
{
	if (nb > 10 && nb < 2147483647)
	{
		c += ft_putnbr(nb / 10, c);
		c += ft_putchar((nb % 10) + 48);
	}
	else
	{
		c += ft_putchar(nb + 48);
	}
	return (c);
}

int	ft_printf_n(int nb)
{
	int	iprint;

	iprint = 0;
	if (nb == -2147483648)
		iprint += ft_printf_s("-2147483648");
	else
	{
		if (nb < 0)
		{
			iprint += ft_putchar('-');
			nb = nb * -1;
		}
		iprint += ft_putnbr(nb, 0);
	}
	return (iprint);
}

int	ft_puthnbr(unsigned int nb, char *base, int l, int c)
{
	if (nb >= (unsigned int)l)
	{
		c += ft_puthnbr(nb / (unsigned int)l, base, l, c);
		c += ft_putchar(base[nb % (unsigned int)l]);
	}
	else
	{
		c += ft_putchar(base[nb]);
	}
	return (c);
}

int	ft_printf_h(unsigned int nb)
{
	int	iprint;
	char base[] = "0123456789abcdef";

	iprint = 0;
	iprint += ft_puthnbr(nb, base, 16, 0);
	return (iprint);
}


int	checkargs(va_list args, char c)
{
	int	iprint;

	iprint = 0;
	if (c == 's')
		iprint += ft_printf_s(va_arg(args, char *));
	else if (c == 'd')
		iprint += ft_printf_n(va_arg(args, int));
	else if (c == 'x')
		//write(1, "hexa", 4);
		iprint += ft_printf_h(va_arg(args, unsigned int));
	return (iprint);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int 	iprint;
	va_list	args;

	count = 0;
	iprint = 0;
	va_start(args, s);
	if (!s)
		return (0);
	while (s[count])
	{
		if (s[count] == '%')
		{
			count++;
			iprint += checkargs(args, s[count]);
		}
		else
		{
			iprint += ft_putchar(s[count]);
		}
		count++;
	}
	va_end(args);
	return (iprint);
}

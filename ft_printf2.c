/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:45:27 by pcariou           #+#    #+#             */
/*   Updated: 2019/11/28 17:06:47 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	classic_print5(const char *t, char *f, int *n, va_list p)
{
	char	current_c;

	if (t[n[0]] == 'c' && f[2] != '.')
	{
		current_c = va_arg(p, int);
		if (f[1] != '-')
			n[4] += write_spaces(n[1], f[0], 1);
		n[4] += ft_putchar_count(current_c);
		if (f[1] == '-')
			n[4] += write_spaces(n[1], ' ', 1);
	}
	with_precision(t, f, n, p);
}

void	classic_print4(const char *t, char *f, int *n, va_list p)
{
	char	*current_s;

	if ((t[n[0]] == 's' || t[n[0]] == 'x' || t[n[0]] == 'X') && f[2] != '.')
	{
		if (t[n[0]] == 'x' || t[n[0]] == 'X')
			current_s = hexaconverter(va_arg(p, int), t[n[0]]);
		else
		{
			current_s = va_arg(p, char *);
			n[6] = (current_s == NULL) ? 1 : 0;
			current_s = (current_s == NULL) ? create_null() : current_s;
		}
		if (f[1] != '-')
			n[4] += write_spaces(n[1], f[0], ft_strlen(current_s));
		n[4] += ft_putstr(current_s);
		if (f[1] == '-')
			n[4] += write_spaces(n[1], ' ', ft_strlen(current_s));
		if (t[n[0]] == 's' && n[6] == 1)
			free(current_s);
		else if (t[n[0]] == 'x' || t[n[0]] == 'X')
			free(current_s);
	}
	classic_print5(t, f, n, p);
}

void	classic_print3(const char *t, char *f, int *n, va_list p)
{
	char	*current_s;

	if (t[n[0]] == 'p' && f[2] != '.')
	{
		current_s = pointerconverter((long unsigned int)(va_arg(p, void *)));
		if (f[1] != '-' && f[0] != '0')
			n[4] += write_spaces(n[1], f[0], ft_strlen(current_s) + 2);
		n[4] += write_ox();
		if (f[1] != '-' && f[0] == '0')
			n[4] += write_spaces(n[1], f[0], ft_strlen(current_s) + 2);
		n[4] += ft_putstr(current_s);
		if (f[1] == '-')
			n[4] += write_spaces(n[1], ' ', ft_strlen(current_s) + 2);
		free(current_s);
	}
	classic_print4(t, f, n, p);
}

void	classic_print2(const char *t, char *f, int *n, va_list p)
{
	int	current_d;

	if ((t[n[0]] == 'd' || t[n[0]] == 'i') && f[2] != '.')
	{
		current_d = va_arg(p, int);
		if (current_d < 0 && f[0] == '0')
			n[4] += ft_putchar_count('-');
		if (f[1] != '-')
			n[4] += write_spaces(n[1], f[0], count_length_nbr(current_d));
		if (current_d < 0 && f[0] == '0')
		{
			current_d *= -1;
			n[3]++;
		}
		n[4] += ft_putnbr_count(current_d, 1);
		if (f[1] == '-' && n[3] != 2)
			n[4] += write_spaces(n[1], ' ', count_length_nbr(current_d));
		else if (f[1] == '-' && n[3] == 2)
			n[4] += write_spaces(n[1], ' ', count_length_nbr(current_d) + 1);
	}
	classic_print3(t, f, n, p);
}

void	classic_print(const char *t, char *f, int *n, va_list p)
{
	int current_d;

	if (t[n[0]] == 'u' && f[2] != '.')
	{
		current_d = va_arg(p, int);
		if (f[1] != '-')
			n[4] += write_spaces(n[1], f[0], count_length_unbr(current_d));
		n[4] += ft_putunbr_count(current_d, 1);
		if (f[1] == '-')
			n[4] += write_spaces(n[1], ' ', count_length_unbr(current_d));
	}
	classic_print2(t, f, n, p);
}

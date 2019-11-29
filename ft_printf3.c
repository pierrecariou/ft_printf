/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 20:42:25 by pcariou           #+#    #+#             */
/*   Updated: 2019/11/28 17:06:57 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	with_x(const char *t, char *f, int *n, va_list p)
{
	char *current_s;

	if ((t[n[0]] == 'x' || t[n[0]] == 'X') && f[2] == '.')
	{
		current_s = hexaconverter(va_arg(p, unsigned int), t[n[0]]);
		if (f[1] == '-')
			n[4] = with_x2(n, current_s);
		if (n[1] != 0 && n[2] <= (int)ft_strlen(current_s))
		{
			if (n[2] == 0 && current_s[0] == '0' && ft_strlen(current_s) == 1)
				n[4] += write_spaces(n[1], ' ', 0);
			else
				n[4] += write_spaces(n[1], ' ', ft_strlen(current_s));
		}
		else if (n[1] != 0)
		{
			n[4] += write_spaces(n[1], ' ', ft_strlen(current_s) +
					(n[2] - ft_strlen(current_s)));
		}
		if (f[1] != '-')
			n[4] = with_x2(n, current_s);
		free(current_s);
	}
	with_p(t, f, n, p);
}

int		with_i2(int *n, int current_d)
{
	if (current_d < 0 && n[2] >= count_length_nbr(current_d))
		n[4] += ft_putchar_count('-');
	if (n[2] >= count_length_nbr(current_d))
		n[4] += write_spaces(n[2] + n[5], '0', count_length_nbr(current_d));
	if (current_d < 0 && n[2] >= count_length_nbr(current_d))
		current_d *= -1;
	if ((n[2] != 0 || current_d != 0))
		n[4] += ft_putnbr_count(current_d, 1);
	return (n[4]);
}

void	with_i(const char *t, char *f, int *n, va_list p)
{
	int current_d;

	if ((t[n[0]] == 'd' || t[n[0]] == 'i') && f[2] == '.')
	{
		current_d = va_arg(p, int);
		if (current_d < 0 && n[2] >= count_length_nbr(current_d))
			n[5] = 1;
		if (f[1] == '-')
			n[4] = with_i2(n, current_d);
		if (n[1] != 0 && n[2] < count_length_nbr(current_d))
		{
			if (n[2] == 0 && current_d == 0)
				n[4] += write_spaces(n[1], ' ', 0);
			else
				n[4] += write_spaces(n[1], ' ', count_length_nbr(current_d));
		}
		else if (n[1] != 0)
		{
			n[4] += write_spaces(n[1], ' ', count_length_nbr(current_d) +
					(n[2] - count_length_nbr(current_d) + n[5]));
		}
		if (f[1] != '-')
			n[4] = with_i2(n, current_d);
	}
	with_x(t, f, n, p);
}

int		with_u2(int *n, int current_d)
{
	if (n[2] > count_length_unbr(current_d))
		n[4] += write_spaces(n[2], '0', count_length_unbr(current_d));
	if ((n[2] != 0 || current_d != 0))
		n[4] += ft_putunbr_count(current_d, 1);
	return (n[4]);
}

void	with_precision(const char *t, char *f, int *n, va_list p)
{
	int current_d;

	if (t[n[0]] == 'u' && f[2] == '.')
	{
		current_d = va_arg(p, int);
		if (f[1] == '-')
			n[4] = with_u2(n, current_d);
		if (n[1] != 0 && n[2] <= count_length_unbr(current_d))
		{
			if (n[2] == 0 && current_d == 0)
				n[4] += write_spaces(n[1], ' ', 0);
			else
				n[4] += write_spaces(n[1], ' ', count_length_unbr(current_d));
		}
		else if (n[1] != 0)
		{
			n[4] += write_spaces(n[1], ' ', count_length_unbr(current_d) +
					(n[2] - count_length_unbr(current_d)));
		}
		if (f[1] != '-')
			n[4] = with_u2(n, current_d);
	}
	with_i(t, f, n, p);
}

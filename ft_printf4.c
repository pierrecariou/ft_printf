/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:51:17 by pcariou           #+#    #+#             */
/*   Updated: 2019/11/28 17:07:04 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	end_of_logic(const char *t, char *f, int *n)
{
	n[1] = 0;
	n[2] = 0;
	n[5] = 0;
	n[6] = 0;
	n[3] = 0;
	f[0] = ' ';
	f[1] = ' ';
	f[2] = ' ';
	if (t[n[0]] != '%')
		n[0]++;
	return_i(n[0]);
	return_count(n[4]);
}

void	with_s(const char *t, char *f, int *n, va_list p)
{
	char *current_s;

	if (t[n[0]] == 's' && f[2] == '.')
	{
		current_s = va_arg(p, char *);
		n[6] = (current_s == NULL) ? 1 : 0;
		current_s = (current_s == NULL) ? create_null() : current_s;
		if (f[1] == '-')
			n[4] += ft_putnstr(current_s, n[2]);
		if (n[1] != 0 && n[2] <= (int)ft_strlen(current_s))
			n[4] += write_spaces(n[1], f[0], n[2]);
		else if (n[1] != 0)
			n[4] += write_spaces(n[1], f[0], ft_strlen(current_s));
		if (f[1] != '-')
			n[4] += ft_putnstr(current_s, n[2]);
		if (n[6] == 1)
			free(current_s);
	}
	end_of_logic(t, f, n);
}

int		with_p2(int *n, char *current_s)
{
	n[4] += write_ox();
	if (n[2] > (int)ft_strlen(current_s))
		n[4] += write_spaces(n[2], '0', ft_strlen(current_s));
	n[4] += ft_putstr(current_s);
	return (n[4]);
}

void	with_p(const char *t, char *f, int *n, va_list p)
{
	char *current_s;

	if (t[n[0]] == 'p' && f[2] == '.')
	{
		current_s = pointerconverter((int)(va_arg(p, void *)));
		if (f[1] == '-')
			n[4] = with_p2(n, current_s);
		if (n[2] > (int)ft_strlen(current_s))
			n[4] += write_spaces(n[1], f[0], (int)ft_strlen(current_s) + 2
					+ (n[2] - ft_strlen(current_s)));
		else if (n[1] > (int)ft_strlen(current_s) + 2)
			n[4] += write_spaces(n[1], f[0], (int)ft_strlen(current_s) + 2);
		if (f[1] != '-')
			n[4] = with_p2(n, current_s);
		free(current_s);
	}
	with_s(t, f, n, p);
}

int		with_x2(int *n, char *current_s)
{
	if (n[2] > (int)ft_strlen(current_s))
		n[4] += write_spaces(n[2], '0', ft_strlen(current_s));
	if (n[2] != 0 || current_s[0] != '0' || ft_strlen(current_s) != 1)
		n[4] += ft_putstr(current_s);
	return (n[4]);
}

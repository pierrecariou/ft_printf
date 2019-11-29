/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:48:26 by pcariou           #+#    #+#             */
/*   Updated: 2019/11/28 22:44:25 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		check_flag(char *types, int i)
{
	int	i_cpy;

	i_cpy = i;
	while (types[i] == '0' || types[i] == '-')
		i++;
	if (types[i] == '*')
		i++;
	while (ft_isdigit(types[i]))
		i++;
	if (types[i] == '.')
		i++;
	if (types[i] == '*')
		i++;
	while (ft_isdigit(types[i]))
		i++;
	if (types[i] == 'c' || types[i] == 's' || types[i] == 'p' ||
			types[i] == 'd' || types[i] == 'i' || types[i] == 'u' ||
			types[i] == 'x' || types[i] == 'X')
		return (1);
	return (0);
}

void	find_flags2(const char *t, char *f, int *n, va_list p)
{
	if (t[n[0]] == '.')
	{
		f[2] = '.';
		n[0]++;
	}
	while (ft_isdigit(t[n[0]]) == 1 && f[2] == '.')
	{
		n[2] += (t[n[0]] - '0');
		if (ft_isdigit(t[n[0] + 1]) == 1)
			n[2] *= 10;
		n[0]++;
	}
	if (t[n[0]] == '*' && t[n[0] - 1] == '.')
	{
		n[2] = va_arg(p, int);
		f[2] = (n[2] < 0) ? ' ' : '.';
		n[0]++;
	}
	classic_print(t, f, n, p);
}

void	find_flags1(const char *t, char *f, int *n, va_list p)
{
	while (t[n[0]] == '0' || t[n[0]] == '-')
	{
		if (t[n[0]] == '-')
			f[1] = '-';
		if (t[n[0]] == '0' && f[1] != '-')
			f[0] = '0';
		n[0]++;
	}
	while (ft_isdigit(t[n[0]]) == 1 && f[2] != '.')
	{
		n[1] += (t[n[0]] - '0');
		if (ft_isdigit(t[n[0] + 1]) == 1)
			n[1] *= 10;
		n[0]++;
	}
	if (t[n[0]] == '*' && t[n[0] - 1] != '.')
	{
		n[1] = va_arg(p, int);
		f[1] = (n[1] < 0) ? '-' : f[1];
		n[3] = (n[1] < 0) ? n[3] + 1 : n[3];
		n[1] = (n[1] < 0) ? n[1] * -1 : n[1];
		n[0]++;
	}
	find_flags2(t, f, n, p);
}

void	false_pourcent(va_list p, char *f, int *n, const char *t)
{
	if (t[n[0]] == '%')
	{
		if (check_flag((char *)t, n[0] + 1) == 0)
		{
			if (t[n[0] + 1] == '%')
				n[4] += ft_putchar_count('%');
			while (t[n[0] + 2] != '%' && t[n[0] + 2])
			{
				n[4] += ft_putchar_count(t[n[0] + 2]);
				n[0]++;
			}
			n[0] += 2;
		}
		else if (check_flag((char *)t, n[0] + 1) == 1)
		{
			n[0]++;
		}
	}
	find_flags1(t, f, n, p);
}

/*
** i
** nums[0] = 0;
** number
** nums[1] = 0;
** precision
** nums[2] = 0;
** a
** nums[3] = 0;
** count
** nums[4] = 0;
** isneg
** nums[5] = 0;
** null
** nums[6] = 0;
*/

int		ft_printf(const char *types, ...)
{
	va_list	parameter;
	char	*flags;
	int		*nums;

	va_start(parameter, types);
	flags = create_flags();
	nums = create_nums();
	while (types[nums[0]])
	{
		while (types[nums[0]] != '%')
		{
			if (types[nums[0]] == '\0')
			{
				end_va_list(flags, nums, parameter);
				return (nums[4]);
			}
			nums[4] += ft_putchar_count(types[nums[0]]);
			nums[0]++;
		}
		false_pourcent(parameter, flags, nums, types);
		nums[0] = return_i(-1);
		nums[4] = return_count(-1);
	}
	end_va_list(flags, nums, parameter);
	return (nums[4]);
}

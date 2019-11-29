/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_fts2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:02:57 by pcariou           #+#    #+#             */
/*   Updated: 2019/11/28 17:07:21 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*create_null(void)
{
	char	*null;
	int		i;

	i = 0;
	if (!(null = malloc(sizeof(char) * 7)))
		return (0);
	null[i++] = '(';
	null[i++] = 'n';
	null[i++] = 'u';
	null[i++] = 'l';
	null[i++] = 'l';
	null[i++] = ')';
	null[i] = 0;
	return (null);
}

int		write_ox(void)
{
	char	*ox;
	int		i;

	i = 0;
	if (!(ox = malloc(sizeof(char) * 3)))
		return (0);
	ox[i++] = '0';
	ox[i++] = 'x';
	ox[i] = 0;
	ft_putstr_fd(ox, 1);
	free(ox);
	return (2);
}

int		write_0(void)
{
	ft_putchar_fd('0', 1);
	return (1);
}

int		write_spaces(int n, char c, int length)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (n == 0)
		return (0);
	while (i < n - length)
	{
		ft_putchar_fd(c, 1);
		count++;
		i++;
	}
	return (count);
}

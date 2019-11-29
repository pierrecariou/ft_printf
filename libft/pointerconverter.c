/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointerconverter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:45:50 by pcariou           #+#    #+#             */
/*   Updated: 2019/11/28 16:59:24 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_0(void)
{
	char *str;

	if (!(str = malloc(2)))
		return (0);
	str[0] = '0';
	str[1] = 0;
	return (str);
}

char	*pointerconverter2(void)
{
	char	*hexa;
	int		i;
	char	c;

	i = 0;
	c = 'a';
	if (!(hexa = malloc(sizeof(char) * 17)))
		return (0);
	while (i <= 9)
	{
		hexa[i] = i + '0';
		i++;
	}
	while (c <= 'f')
	{
		hexa[i] = c;
		c++;
		i++;
	}
	hexa[i] = '\0';
	return (hexa);
}

char	*pointerconverter(long unsigned int a)
{
	long unsigned int	cp;
	int					i;
	char				*str;
	char				*hexa;

	i = 0;
	cp = a;
	if (a == 0)
	{
		str = str_0();
		return (str);
	}
	hexa = pointerconverter2();
	if (!(str = malloc(sizeof(char) * count_length_ulnbr(a) + 1)))
		return (0);
	while (a >= 16)
	{
		str[i] = hexa[(a % 16)];
		a /= 16;
		i++;
	}
	str[i++] = hexa[a];
	str[i] = '\0';
	free(hexa);
	return (ft_strrev(str));
}

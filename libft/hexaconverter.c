/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexaconverter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:42:35 by pcariou           #+#    #+#             */
/*   Updated: 2019/11/28 16:53:26 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*hexarray(char c)
{
	int		i;
	char	a;
	char	z;
	char	*hexa;

	i = 0;
	a = (c == 'x') ? 'a' : 'A';
	z = a + 5;
	if (!(hexa = malloc(sizeof(char) * 17)))
		return (0);
	while (i <= 9)
	{
		hexa[i] = i + '0';
		i++;
	}
	while (a <= z)
	{
		hexa[i] = a;
		a++;
		i++;
	}
	hexa[i] = '\0';
	return (hexa);
}

char	*hexaconverter(unsigned int n, char c)
{
	int				i;
	unsigned int	cp;
	char			*str;
	char			*hexarray_str;

	i = 0;
	cp = n;
	hexarray_str = hexarray(c);
	while (cp >= 16)
	{
		cp /= 16;
		i++;
	}
	str = malloc(i + 1);
	i = 0;
	while (n >= 16)
	{
		str[i] = hexarray_str[n % 16];
		n /= 16;
		i++;
	}
	str[i] = hexarray_str[n];
	str[i + 1] = '\0';
	free(hexarray_str);
	return (ft_strrev(str));
}

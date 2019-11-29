/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 11:50:01 by pcariou           #+#    #+#             */
/*   Updated: 2019/11/27 14:58:49 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	c;

	i = 0;
	size = ft_strlen(str);
	while (i < size)
	{
		c = str[i];
		str[i] = str[size - 1];
		str[size - 1] = c;
		i++;
		size--;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:46:52 by pcariou           #+#    #+#             */
/*   Updated: 2019/11/27 15:52:00 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char *s)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		write(1, &s[i], 1);
		count++;
		i++;
	}
	return (count);
}

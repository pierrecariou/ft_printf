/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:46:33 by pcariou           #+#    #+#             */
/*   Updated: 2019/11/27 15:47:52 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnstr(char *str, int n)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (str == 0)
		return (0);
	while (str[i] && i < n)
	{
		ft_putchar_fd(str[i], 1);
		count++;
		i++;
	}
	return (count);
}

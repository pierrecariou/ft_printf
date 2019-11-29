/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_str_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:40:46 by pcariou           #+#    #+#             */
/*   Updated: 2019/11/27 15:50:58 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		write_str_rev(char *str)
{
	int len;
	int count;

	len = ft_strlen(str);
	count = 0;
	while (len--)
	{
		ft_putchar_fd(str[len], 1);
		count++;
	}
	return (count);
}

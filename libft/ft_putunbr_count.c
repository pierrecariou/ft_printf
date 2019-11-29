/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:43:41 by pcariou           #+#    #+#             */
/*   Updated: 2019/11/27 15:49:31 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putunbr_count(unsigned int n, int count)
{
	long unsigned int num;

	num = n;
	if (num > 9)
		count = ft_putunbr_count(num / 10, count + 1);
	ft_putchar_fd(num % 10 + '0', 1);
	return (count);
}

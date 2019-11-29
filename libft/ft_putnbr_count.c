/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:43:21 by pcariou           #+#    #+#             */
/*   Updated: 2019/11/27 15:49:51 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_count(int n, int count)
{
	long int num;

	num = n;
	if (num < 0)
	{
		num *= -1;
		ft_putchar_fd('-', 1);
		count++;
	}
	if (num > 9)
		count = ft_putnbr_count(num / 10, count + 1);
	ft_putchar_fd(num % 10 + '0', 1);
	return (count);
}

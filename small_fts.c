/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_fts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 19:07:57 by pcariou           #+#    #+#             */
/*   Updated: 2019/11/28 17:07:11 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int		return_count(int count)
{
	static int return_count;

	if (count != -1)
		return_count = count;
	return (return_count);
}

int		return_i(int i)
{
	static int return_i;

	if (i != -1)
		return_i = i;
	return (return_i);
}

void	end_va_list(char *flags, int *nums, va_list parameter)
{
	free(flags);
	free(nums);
	va_end(parameter);
}

char	*create_flags(void)
{
	char	*flags;
	int		l;

	if (!(flags = malloc(sizeof(int) * 3)))
		return (0);
	l = -1;
	while (l++ <= 3)
		flags[l] = ' ';
	return (flags);
}

int		*create_nums(void)
{
	int *nums;
	int l;

	if (!(nums = malloc(sizeof(int) * 6)))
		return (0);
	l = -1;
	while (l++ <= 6)
		nums[l] = 0;
	return (nums);
}

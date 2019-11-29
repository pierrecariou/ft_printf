/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcariou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:53:24 by pcariou           #+#    #+#             */
/*   Updated: 2019/11/28 17:09:19 by pcariou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	end_va_list(char *flags, int *nums, va_list parameter);
char	*create_flags(void);
int		*create_nums(void);
char	*create_null(void);
int		write_ox(void);
int		write_spaces(int n, char c, int length);
int		return_count(int count);
int		return_i(int i);
void	with_precision(const char *types, char *flags,
		int *nums, va_list parameter);
void	classic_print(const char *types, char *flags,
		int *nums, va_list parameter);
void	classic_print2(const char *types, char *flags,
		int *nums, va_list parameter);
void	classic_print3(const char *types, char *flags,
		int *nums, va_list parameter);
void	classic_print4(const char *types, char *flags,
		int *nums, va_list parameter);
void	classic_print5(const char *types, char *flags,
		int *nums, va_list parameter);
void	with_p(const char *t, char *f, int *n, va_list p);
int		with_x2(int *n, char *current_s);
#endif

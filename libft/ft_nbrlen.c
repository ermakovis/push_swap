/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:19:22 by tcase             #+#    #+#             */
/*   Updated: 2019/05/05 15:00:37 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int			ft_nbrlen(__intmax_t num, int base)
{
	int i;

	i = 1;
	if (num < 0)
	{
		i++;
		num = -num;
	}
	while (num > base - 1)
	{
		num /= base;
		i++;
	}
	return (i);
}

int			ft_unbrlen(__uintmax_t num, int base)
{
	int i;

	i = 1;
	while (num > base - 1)
	{
		num /= base;
		i++;
	}
	return (i);
}

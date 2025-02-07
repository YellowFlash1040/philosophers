/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovtune <akovtune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:34:38 by akovtune          #+#    #+#             */
/*   Updated: 2025/02/06 17:39:25 by akovtune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

bool	check_and_atoi(const char *str, int *res)
{
	bool	m;
	int		digit;

	if (!str || !*str)
		return (false);
	*res = 0;
	m = false;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			m = true;
	while (*str >= '0' && *str <= '9')
	{
		*res *= 10;
		digit = *str++ - '0';
		if (!(INT_MAX - *res >= digit || (m && *res + digit == INT_MIN)))
			return (false);
		*res += digit;
	}
	if (*str != '\0')
		return (false);
	if (m)
		*res = -*res;
	return (true);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-ouis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 22:15:14 by ael-ouis          #+#    #+#             */
/*   Updated: 2020/07/28 21:29:14 by ael-ouis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbrlen(int n)
{
	int		len;

	len = (n < 0) ? 1 : 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return ((len) ? len : 1);
}

char			*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	unsigned int	nb;

	len = ft_nbrlen(n);
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	*(s + len) = '\0';
	nb = (n < 0) ? -n : n;
	while (len--)
	{
		*(s + len) = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		*s = '-';
	return (s);
}

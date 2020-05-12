/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jremarqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 16:36:53 by jremarqu          #+#    #+#             */
/*   Updated: 2019/04/28 01:07:33 by jremarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t i;
	size_t len;

	if (s == 0)
		return ;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		s[i] = '\0';
		i++;
	}
}
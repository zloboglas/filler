/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlabadie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:59:05 by dlabadie          #+#    #+#             */
/*   Updated: 2018/11/26 11:59:06 by dlabadie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == (-2147483647 - 1))
	{
		ft_putchar('-');
		ft_putnbr((n / 10) * -1);
		ft_putchar('8');
	}
	else if (n < 0)
	{
		ft_putchar('-');
		return (ft_putnbr(n * -1));
	}
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:07:43 by matvivan          #+#    #+#             */
/*   Updated: 2019/11/12 16:46:06 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int len(int n, int base)
{
	if (n / base)
		return (1 + len(n / base, base));
	return (1 + (n < 0));
}

void put(char *s, int n, int base)
{
	if (n / base)
		put(s - 1, n / base, base);
	*s = "0123456789ABCDEF"[(n % base) * (n < 0 ? -1 : 1)];
}

char *ft_itoa_base(int value, int base)
{
	char *n;
	int l;
	
	l = len(value, base);
	n = (char *)malloc(sizeof(char) * l + 1);
	if (value < 0)
		*n = '-';
	put(n + l - 1, value, base);
	n[l] = 0;
	return (n + (base != 10 && value < 0));
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%d\n", len(atoi(av[1]), atoi(av[2])));
		printf("%s\n", ft_itoa_base(atoi(av[1]), atoi(av[2])));
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:40:46 by exam              #+#    #+#             */
/*   Updated: 2020/01/07 13:00:04 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int oper(int a, int b, char c)
{
	if (c == '+')
		return (a + b);
	if (c == '-')
		return (a - b);
	if (c == '*')
		return (a * b);
	if (c == '/')
		return (a / b);
	if (c == '%')
		return (a % b);
}

int nota(int first, char *s)
{
	int second;

	second = atoi(*s);
	while (*s > 32)
		++s;
	while (*s && *s < 33)
		++s;
	if (*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '%')
		return (nota(oper(first, second, *s), s));
	else
		return (nota(second, s));
}

int valid(char *s)
{
	int dig;
	int oper;

	dig = 0;
	oper = 0;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			++dig;
		while (*s)
			if (*s++ < 33 && *s > 32)
			{
				if (*s >= '0' && *s <= '9')
					++dig;
				else if (oper == dig - 2)
					oper += (*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '%'); 
				else
					return (0);
			}
	}
	return (oper == dig - 1);
}

int main(int ac, char **av)
{
	if (ac == 2 && valid(av[1], &dig))
	{
		while (*av[1] && *av[1] < 33)
			++av[1];
		ac = atoi(av[1]);
		while (*av[1] > 32)
			++av[1];
		while (*av[1] && *av[1] < 33)
			++av[1];
		printf("%d\n", nota(ac, av[1]));
		return (0);
	}
	printf("Error\n");
	return (0);
}

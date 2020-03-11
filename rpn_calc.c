/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:57:08 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/24 20:49:56 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static char *next(char *s)
{
	while (*s != '\0' && *s != ' ')
		s++;
	while (*s != '\0' && *s == ' ')
		s++;
	return (s);
}

static int *push(int *stack, int size, int elem)
{
	int *new;
	int i;

	new = (int *)malloc(sizeof(int) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = stack[i];
		i++;
	}
	new[i] = elem;
	return (new);
}

static int res(int a, int b, char c)
{
	int result;

	if (c == '+')
		result = a + b;
	else if (c == '-')
		result = a - b;
	else if (c == '*')
		result = a * b;
	else if (c == '/')
		result = a / b;
	else if (c == '%')
		result = a % b;
	return (result);
}

int main(int ac, char **av)
{
	int size;
	int result;
	int *stack;

	if (ac == 2)
	{
		size = 0;
		result = 0;
		while (*av[1] != '\0')
		{
			if (*av[1] >= '0' && *av[1] <= '9')
				stack = push(stack, size++, atoi(av[1]));
			else
			{
				if (size < 2)
					return (write(1, "Error\n", 6));
				result = res(stack[size - 2], stack[size - 1], av[1][0]);
				stack = push(stack, --size - 1, result);
			}
			av[1] = next(av[1]);
		}
		if (size == 1)
		{
			printf("%d\n", stack[--size]);
			return (0);
		}
	}
	return (write(1, "Error\n", 6));
}

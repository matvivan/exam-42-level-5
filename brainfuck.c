/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:47:55 by matvivan          #+#    #+#             */
/*   Updated: 2019/11/12 19:36:22 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int len(char *s)
{
	if (*s)
		return (1 + len(s + 1));
	return (0);
}

char *set(char *s, int k)
{
	if (--k)
		set(s + 1, k);
	*s = 0;
	return (s);
}

void fuck(char *s, char *com, int tmp)
{
	while (*com)
	{
		if (*com == '<')
			++s;
		else if (*com == '>')
			--s;
		else if (*com == '+')
			++(*s);
		else if (*com == '-')
			--(*s);
		else if (*com == '.')
			write(1, s, 1);
		else if (*com == '[' && !(*s) && ++tmp)
			while (*com != ']' || tmp)
			{
				++com;
				tmp += (*com == 91) - (*com == 93);
			}
		else if (*com == ']' && *s && --tmp)
			while (*com != '[' || tmp)
			{
				--com;
				tmp += (*com == 91) - (*com == 93);
			}
		++com;
	}
}

int main(int ac, char **av)
{
	if (ac == 2 && len(av[1]) <= 4096)
		fuck(set((char *)malloc(sizeof(char) * 2048), 2048), av[1], 0);
	else
		write(1, "\n", 1);
	return (0);
}

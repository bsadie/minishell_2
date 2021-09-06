/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 14:25:20 by eghis             #+#    #+#             */
/*   Updated: 2021/09/06 12:25:52 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_arrsize(char **args)
{
	int	i;

	i = 0;
	if (args[i])
	{
		while (args[i] != 0)
			i++;
	}
	return (i);
}

void	ft_putstr_sp(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int	ft_echo(char **args)
{
	int	i;
	int	count;
	int	flag;

	i = 1;
	flag = 0;
	count = ft_arrsize(args);
	if (args[1][0] == '-' && args[1][1] == 'n' && args[1][2] == '\0')
	{
		flag = 1;
		i++;
	}
	while (i < count)
	{
		ft_putstr_sp(args[i++]);
		if (i < count)
			ft_putchar(' ');
	}
	if (flag == 0)
		ft_putchar('\n');
	return (0);
}
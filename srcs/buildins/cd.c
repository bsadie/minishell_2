/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsadie <bsadie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:28:15 by bsadie            #+#    #+#             */
/*   Updated: 2021/09/06 13:34:01 by bsadie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_cd(t_all *all, t_list *node)
{
	char	**args;

	args = node->args;
	if (ft_arrsize(args) > 2)
	{
		printf("minishell: cd: %s\n", strerror(E2BIG));
		return (2);
	}
	if (chdir(args[1]))
	{
		printf("minishell: cd: %s\n", strerror(errno));
		return (1);
	}
//	ft_pwd();
	return (0);
}
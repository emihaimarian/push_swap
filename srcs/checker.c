/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mienache <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 20:15:40 by mienache          #+#    #+#             */
/*   Updated: 2018/02/18 20:15:43 by mienache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_env	env;
	int		len_arg;

	len_arg = argc - 1;
	i = len_arg;
	env.spe.flg_shell = 0;
	if (argc == 1)
		return (0);
	if (ft_strcmp(argv[1], "-s") == 0 || ft_strcmp(argv[1], "-shell") == 0)
		env.spe.flg_shell = 1;
	if (ft_parsing_input(argc, argv, env.spe.flg_shell) == -1)
		return (-1);
	env.stack_a = NULL;
	env.stack_b = NULL;
	while (i > env.spe.flg_shell)
		if (!(ft_push_front(&env.stack_a, ft_atoi(argv[i--]))))
			return (-1);
	if (env.spe.flg_shell == 1)
		ft_shell(&env);
	else
		ft_checker(&env);
	return (0);
}

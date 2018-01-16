/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 02:06:38 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/16 02:37:56 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

 int main(int argc, const char *argv[])
{
	int i = 1;
	while (i < argc)
	{
		ft_putnbr_endl(ft_atoi_base(argv[i], HEXA));
		NL;
		i++;
	}
	return 0;
}

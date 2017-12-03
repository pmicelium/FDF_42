/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:45:42 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/13 22:34:02 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wc(char const *str, char c)
{
	int		wc;
	int		i;

	wc = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && str[i] != c)
		{
			wc++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (wc);
}

static int		ft_cc(char const *str, char c)
{
	int		charcount;

	charcount = 0;
	while (str[charcount] && str[charcount] != c)
		charcount++;
	return (charcount);
}

static char		**ft_malloc_columns(char const *str, char **tab, char c)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = -1;
	while (str[++i])
	{
		if ((str[i - 1] == c || i == 0) && str[i] != c)
		{
			k = 0;
			tab[++j] = (char *)malloc(sizeof(char) * (ft_cc(str + i, c) + 1));
			if (tab[j] == NULL)
				return (NULL);
			while (str[i + k] && str[i + k] != c)
			{
				tab[j][k] = str[i + k];
				k++;
			}
			tab[j][k] = '\0';
		}
	}
	tab[j + 1] = (NULL);
	return (tab);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**tab;

	if (str == NULL)
		return (0);
	tab = (char **)malloc(sizeof(char *) * (ft_wc(str, c) + 1));
	if (tab == NULL)
		return (NULL);
	tab = ft_malloc_columns(str, tab, c);
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_bonus_fr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:26:53 by pmiceli           #+#    #+#             */
/*   Updated: 2017/12/23 16:39:40 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_display_bonus_fr(void)
{
	ft_putendl("Liste des bonus :");
	NL;
	ft_putendl("-Gestion du deplacement et de la re-intialisation de l'image.");
	ft_putendl("-Affichage des couleurs en fonctions de l'elevation de la piece.");
	ft_putendl("-Affichage du degradee entre un point en hauteur et un point neutre.");
	ft_putendl("-Gestion dynamique de l'elevation.");
	ft_putendl("-Gestion dynamique du zoom.");
	ft_putendl("-Affichage des FPS / IPS.");
	ft_putendl("-Gestion dynamique des couleurs (sourie ou mollette)");
}

void		ft_display_bonus_en(void)
{
	ft_putendl("Bonus list :");
	NL;
	ft_putendl("-Possibility to move the image and to reinitialize it.");
	ft_putendl("-Display colors according to the elevation of the point.");
	ft_putendl("-Display a color gradient between a point in height and a neutral point.");
	ft_putendl("-Dynamic management of elevation.");
	ft_putendl("-Dynamic zoom management.");
	ft_putendl("-Display of the FPS.");
	ft_putendl("-Dynamic color management (with the mouse or mouse wheel).");
}

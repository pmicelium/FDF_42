/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_bonus_fr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 16:26:53 by pmiceli           #+#    #+#             */
/*   Updated: 2018/01/18 20:41:48 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_display_bonus_fr(void)
{
	ft_putendl("Liste des bonus :");
	ft_putchar('\n');
	ft_putendl(
"-Gestion du deplacement, de la rotation et de la reintialisation de l'image.");
	ft_putendl(
		"-Affichage des couleurs en fonctions de l'elevation de la piece.");
	ft_putstr(
			"-Possibilite de changer la couleur directement dans le fichier");
	ft_putendl(" de cette facon : <hauteur>,0xRRGGBB");
	ft_putendl(
		"-Affichage du degradee entre un point en hauteur et un point neutre.");
	ft_putendl("-Gestion dynamique de l'elevation.");
	ft_putendl("-Gestion dynamique du zoom.");
	ft_putendl("-Affichage des FPS / IPS.");
	ft_putendl("-Gestion dynamique des couleurs (sourie ou mollette)");
	ft_putendl("-Clipping des lignes");
	ft_putendl("-Gestion du 'bouton reste appuye'");
	ft_putendl("-Normalisation de la carte");
	ft_putchar('\n');
}

void		ft_display_bonus_en(void)
{
	ft_putendl("Bonus list :");
	ft_putchar('\n');
	ft_putendl(
			"-Possibility to move, rotate the image and to reinitialize it.");
	ft_putendl("-Display colors according to the elevation of the point.");
	ft_putstr("-Possibility to change the color directly in the file ");
	ft_putendl("in this way: <height>,0xRRGGBB");
	ft_putendl(
	"-Display a color gradient between a point in height and a neutral point.");
	ft_putendl("-Dynamic management of elevation.");
	ft_putendl("-Dynamic zoom management.");
	ft_putendl("-Display of the FPS.");
	ft_putendl("-Dynamic color management (with the mouse or mouse wheel).");
	ft_putendl("-Line clipping");
	ft_putendl("-Management of the 'button stayed pressed' utility");
	ft_putendl("-Normalizaion of the map");
	ft_putchar('\n');
}

void		ft_print_usage(void)
{
	ft_putendl("usage : ");
	ft_putendl("./fdf [-bonus.en] [-bonus.fr] [-leaks] \
[-lcolor <hex color>] [-ucolor <hex color>] map");
	ft_putendl("-bonus.fr and -bonus.en display the bonus list respectively in \
french and english");
	ft_putendl("-leaks activates an infinite loop before the end of the \
program");
	ft_putendl("-lcolor and -ucolor allows to choose the default color for \
respectively the lowest and highest point, by default it's FFFFFF and FF0000");
	exit(1);
}

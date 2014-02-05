/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/05 13:13:52 by avannest          #+#    #+#             */
/*   Updated: 2014/02/05 14:47:02 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Testing the concept where we use a string as an img,
** and fill the holes with /0
**
** For it to work, we need to add 2 * 11 chars for each character,
** for the foreground and background color.
** Hence the size of an image would be dim_x * dim_y * 23 ;
** For an image of the size of the header : 20240B = env. 2kB
** For an image 5 times bigger : 50kB env.
*/

#include <libc.h> /* strlen */

int				main(void)
{
	// Let's use an image of 5 tpixels wide and 1 tpixel high.
	char		img[5 * 1 * 23 + 1];

	bzero(img, 5*1*23+1);
	strcpy(img, "\E[48;5;199m\E[38;5;19ma");
	strcpy(img + 22, "\E[48;5;19m\E[38;5;119mb");
	strcpy(img + 44, "\E[48;5;199m\E[38;5;19mc");
	strcpy(img + 87, "d");
	strcpy(img + 99, "\E[38;5;240me");
	write(1, img, 5*1*23+1);
	return (0);
}


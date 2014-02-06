/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlt_image_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 11:54:06 by avannest          #+#    #+#             */
/*   Updated: 2014/02/04 12:30:55 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__mlt_image.h"
#include <stdlib.h>

/*
**  The created image will be so that : img[x_coord][y_coord]
**  An extra line containing NULL is added for convenience.
*/
t_tpixel		**mlt_new_image(int dim_x, int dim_y)
{
	t_tpixel	**new_img;
	int			i;

	new_img = (t_tpixel **)malloc(sizeof(t_tpixel *) * (dim_y + 1));
	if (new_img == NULL)
		return (NULL);
	i = 0;
	while (i < dim_y)
	{
		new_img[i] = (t_tpixel *)malloc(sizeof(t_tpixel) * dim_x);
		if (new_img[i] == NULL)
			return (NULL);
		++i;
	}
	new_img[i] = NULL;
	return (new_img);
}

void		mlt_free_image(t_tpixel **img)
{
	int			i;

	i = 0;
	while (img[i] != NULL)
	{
		free(img[i]);
		++i;
	}
	free(img);
	img = NULL;
}


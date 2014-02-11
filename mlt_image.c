/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlt_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 14:37:52 by avannest          #+#    #+#             */
/*   Updated: 2014/02/11 16:27:00 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>		/* malloc */
#include <libc.h>		/* sprintf */
#include "__mlt.h"

/*
**  If we ever implement image size.
*/
t_mlt_img	*mlt_new_img(int dim_x, int dim_y)
{
	t_mlt_img	*new_img;

	if (!(new_img = (t_mlt_img *)malloc(sizeof(t_mlt_img))))
		return (NULL);
	if (!(new_img->img = (char *)calloc(dim_x * dim_y, 23)))
	{
		free(new_img);
		return (NULL);
	}
	new_img->co = dim_x;
	new_img->li = dim_y;
	return (new_img);
}

void		mlt_free_img(t_mlt_img **img)
{
	free((*img)->img);
	free(*img);
	(*img) = NULL;
}

void		mlt_char_put_img(t_mlt_img *img, int x, int y, int fg, int bg, char c)
{
	char	*pos;

	pos = img->img + (y * img->co + x) * 23;
	bzero(pos, 23);
	sprintf(pos, "\E[48;5;%im\E[38;5;%im%c", bg, fg, c);
}


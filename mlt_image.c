/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlt_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 14:37:52 by avannest          #+#    #+#             */
/*   Updated: 2014/02/12 16:09:34 by avannest         ###   ########.fr       */
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
	int			i;

	if (!(new_img = (t_mlt_img *)malloc(sizeof(t_mlt_img))))
		return (NULL);
	if (!(new_img->img = (char *)calloc(dim_x * dim_y, 23)))
	{
		free(new_img);
		return (NULL);
	}
	i = 0;
	while (i < dim_x * dim_y)
	{
	puts("coucou");
		mlt_char_put_img(new_img, i % dim_x, i / dim_x, 231, 0, ' ');
		++i;
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


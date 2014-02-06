/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __mlt_image.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 11:44:46 by avannest          #+#    #+#             */
/*   Updated: 2014/02/04 12:31:09 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MLT_IMAGE_H
# define __MLT_IMAGE_H

typedef struct		s_tpixel
{
	char			c;
	int				fg_color;
	int				bg_color;
}					t_tpixel;

/*
** mlt_image_init.c
*/
t_tpixel	**mlt_new_image(int dim_x, int dim_y);
void		mlt_free_image(t_tpixel **img);

/*
** mlt_image_put.c
*/
int			mlt_img_read(t_tpixel** img, &buf);
void		mlt_img_put(t_tpixel** img);

#endif /* !__MLT_IMAGE.H */


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_basics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 12:05:27 by avannest          #+#    #+#             */
/*   Updated: 2014/02/12 11:52:25 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__mlt.h"

int				main(void)
{
	t_mlt_img	*img;

	img = mlt_new_img(5, 1);
	mlt_char_put_img(img, 0, 0, 155, 32, 'c');
	mlt_char_put_img(img, 3, 0, 245, 89, 'c');
	mlt_img_put(img);
	mlt_free_img(&img);
	return (0);
}


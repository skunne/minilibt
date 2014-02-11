/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_basics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/04 12:05:27 by avannest          #+#    #+#             */
/*   Updated: 2014/02/11 16:30:05 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "__mlt.h"

int				main(void)
{
	t_mlt_img	*img;

	img = mlt_new_img(5, 5);
	mlt_free_img(&img);
	return (0);
}


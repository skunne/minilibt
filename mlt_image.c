/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlt_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannest <avannest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 14:37:52 by avannest          #+#    #+#             */
/*   Updated: 2014/02/06 14:58:40 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*mlt_new_img(int dim_x, int dim_y)
{
	char	*new_img;
	int		size;

	size = dim_x * dim_y * 23;
	new_img = (char *)malloc(size);
	if (!new_img)
		return (NULL);
	while (size > 0)
		new_img[--size];
	return (new_img);
}

void	mlt_char_put(int x, int y, int fg, int bg, char c)
{
}


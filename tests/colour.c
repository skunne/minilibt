/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunne <skunne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 15:41:28 by skunne            #+#    #+#             */
/*   Updated: 2014/01/19 14:15:58 by skunne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlt.h>

int			main(void)
{
	int		i;
	int		y;
	void	*mlt_ptr;

	mlt_ptr = mlt_init();
	y = 0;
	i = 0;
	while (i < 16)
	{
		mlt_char_put(i, y, 0, 7, '0' + i % 8);
		mlt_char_put(i, y + 1, i, i, ' ');
		++i;
	}
	y += 3;
	i = 0;
	while (i < 36)
	{
		mlt_char_put(1 + i, y, 0, 7, '0' + i % 6);
		++i;
	}
	++y;
	i = 0;
	while (i < 6)
	{
		mlt_char_put(0, y + i, 0, 7, '0' + i);
		++i;
	}
	i = 0;
	while (i < 216)
	{
		mlt_char_put(1 + i % 36, y + i / 36, 16 + i, 16 + i, ' ');
		++i;
	}
	y += i / 36 + 1;
	i = 0;
	while (i < 24)
	{
		mlt_char_put(i, y, 0, 7, '0' + i % 10);
		mlt_char_put(i, y + 1, 16 + 216 + i, 16 + 216 + i, ' ');
		++i;
	}
	while (42)
		;
	return (-2);
}


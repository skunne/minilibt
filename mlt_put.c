/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlt_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunne <skunne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 15:11:36 by skunne            #+#    #+#             */
/*   Updated: 2014/01/17 20:05:48 by skunne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "__mlt.h"

void			mlt_char_put(int x, int y, int fg, int bg, char c)
{
	MLT_TGOTO(x, y);
	MLTTGOTO("AF", 0, fg);
	MLTTGOTO("AB", 0, bg);
	write(SPE_OUT, &c, 1);
}

void			mlt_string_put(int x, int y, int fg, int bg, char *str)
{
	MLT_TGOTO(x, y);
	MLTTGOTO("AF", 0, fg);
	MLTTGOTO("AB", 0, bg);
	write(SPE_OUT, str, strlen(str));
}

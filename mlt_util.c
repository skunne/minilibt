/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlt_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunne <skunne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 19:58:56 by skunne            #+#    #+#             */
/*   Updated: 2014/01/15 12:25:19 by skunne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "__mlt.h"

void			f_do_nothing(void)
{
}

int				mlt_spe_out(void)
{
	static int	fd = -1;

	if (fd == -1)
		fd = open("/dev/tty", O_WRONLY);
	return (fd);
}

int				mlt_tputs_putchar(int c)
{
	write(SPE_OUT, &c, 1);
	return (1);
}


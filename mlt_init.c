/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlt_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunne <skunne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 14:46:09 by skunne            #+#    #+#             */
/*   Updated: 2014/01/19 22:07:14 by skunne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "__mlt.h"

t_mlt			*mlt_init(void)
{
	t_mlt		*mlt_ptr;
	char		buff[2048];

	mlt_ptr = (t_mlt *) malloc(sizeof(t_mlt));
	tgetent(buff, getenv("TERM"));
	tcgetattr(STDIN, &mlt_ptr->original_thermos);
	memcpy(&mlt_ptr->thermos,
		   &mlt_ptr->original_thermos,
		   sizeof(struct termios));
	FLAG_UNSET(mlt_ptr->thermos.c_lflag, ICANON);
	FLAG_UNSET(mlt_ptr->thermos.c_lflag, ECHO);
	mlt_ptr->thermos.c_cc[VMIN] = 1;
	mlt_ptr->thermos.c_cc[VTIME] = 0;
	MLT_TPUTS("ti");
//	MLT_TPUTS("vi");
	tcsetattr(STDIN, TCSANOW, &mlt_ptr->thermos);
	mlt_recalc_win(mlt_ptr);
	mlt_init_signal(mlt_ptr);
	return (mlt_ptr);
}

void			mlt_clear_window(t_mlt *mlt_ptr)
{
	(void) mlt_ptr;
	MLT_TPUTS("cl");
}

void			mlt_restore_term(struct termios *original_thermos)
{
	MLT_TPUTS("te");
	MLT_TPUTS("ve");
	tcsetattr(STDIN, TCSANOW, original_thermos);
}

void			mlt_recalc_win(t_mlt *mlt_ptr)
{
	ioctl(STDIN, TIOCGWINSZ, &mlt_ptr->w);
}

void			mlt_exit(t_mlt *mlt_ptr)
{
	mlt_restore_term(&mlt_ptr->original_thermos);
	free(mlt_ptr);
	exit(0);
}


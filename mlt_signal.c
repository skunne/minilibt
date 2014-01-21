/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlt_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunne <skunne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/15 12:14:16 by skunne            #+#    #+#             */
/*   Updated: 2014/01/19 22:51:42 by skunne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <signal.h>
#include "__mlt.h"


extern void			(*f_expose_hook)(int x, int y, void *p);
extern void			*p_expose_hook;

static t_mlt		*mlt_get_param(t_mlt *mlt)
{
	static t_mlt	*p;

	if (mlt != NULL)
		p = mlt;
	return (p);
}

static void			mlt_sig_pause(int x)
{
	t_mlt			*mlt;

	(void) x;
	mlt = mlt_get_param(NULL);
	mlt_restore_term(&mlt->original_thermos);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDIN, TIOCSTI, &mlt->thermos.c_cc[VSUSP]);
}

static void			mlt_sig_cont(int x)
{
	t_mlt			*mlt;

	(void) x;
	mlt = mlt_get_param(NULL);
	signal(SIGTSTP, &mlt_sig_pause);
	MLT_TPUTS("ti");
	MLT_TPUTS("vi");
	tcsetattr(STDIN, TCSANOW, &mlt->thermos);
	(*f_expose_hook)(mlt->w.ws_col, mlt->w.ws_row, p_expose_hook);
}

static void			mlt_sig_int(int x)
{
	t_mlt			*mlt;

	(void) x;
	mlt = mlt_get_param(NULL);
	mlt_exit(mlt);
}

void				mlt_init_signal(t_mlt *mlt_ptr)
{
	mlt_get_param(mlt_ptr);
	signal(SIGTSTP, &mlt_sig_pause);
	signal(SIGCONT, &mlt_sig_cont);
	signal(SIGINT, &mlt_sig_int);
}


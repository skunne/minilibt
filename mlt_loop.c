/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlt_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunne <skunne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 19:15:58 by skunne            #+#    #+#             */
/*   Updated: 2014/01/19 22:43:26 by skunne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <strings.h>
#include "__mlt.h"

static void		(*f_key_hook)() = &f_do_nothing;
void			(*f_expose_hook)() = &f_do_nothing;
static void		(*f_loop_hook)() = &f_do_nothing;

static void		*p_key_hook = NULL;
void			*p_expose_hook = NULL;
static void		*p_loop_hook = NULL;

static t_mlt	*p_mlt;

static void		f_expose_int(int x)
{
	(void) x;
	mlt_recalc_win(p_mlt);
	(*f_expose_hook)(p_mlt->w.ws_col, p_mlt->w.ws_row, p_expose_hook);
}

void			mlt_loop(t_mlt *mlt_ptr)
{
	char		buff[5];

	(*f_expose_hook)(mlt_ptr->w.ws_col, mlt_ptr->w.ws_row, p_expose_hook);
	p_mlt = mlt_ptr;
	signal(SIGWINCH, &f_expose_int);
			(*f_loop_hook)(p_loop_hook);
	while (42)
	{
		(*f_loop_hook)(p_loop_hook);
		bzero(buff, 5);
		if (read(STDIN, buff, 4) > 0)
			(*f_key_hook)(*(int *) buff, p_key_hook);
		else
			(*f_loop_hook)(p_loop_hook);
	}
}

void			mlt_key_hook(t_mlt *mlt_ptr, void (*f)(int, void *), void *p)
{
	(void) mlt_ptr;
	f_key_hook = f;
	p_key_hook = p;
}

void			mlt_expose_hook(t_mlt *mlt_ptr,
								void (*f)(int x, int y, void *),
								void *p)
{
	(void) mlt_ptr;
	f_expose_hook = f;
	p_expose_hook = p;
}

void			mlt_loop_hook(t_mlt *mlt_ptr, void (*f)(void *), void *p)
{
	(void) mlt_ptr;
	f_loop_hook = f;
	p_loop_hook = p;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __mlt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunne <skunne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 15:53:19 by skunne            #+#    #+#             */
/*   Updated: 2014/02/11 12:52:48 by avannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MLT_H
# define __MLT_H

# include <sys/ioctl.h>
# include <termios.h>
# include <termcap.h>

# define STDIN				0
# define STDOUT				1
# define SPE_OUT			mlt_spe_out()

# define FLAG_SET(V, F)		((V) = (V) | (F))
# define FLAG_UNSET(V, F)	((V) = (V) & ~(F))
# define FLAG_TOGGLE(V, F)	((V) = (V) ^ (F))
# define FLAG_ISSET(V, F)	(((V) & (F)) == (F))

# define MLTTPUTS(STR)		tputs((STR), 1, &mlt_tputs_putchar)
# define MLT_TPUTS(STR)		MLTTPUTS(tgetstr((STR), NULL))
# define MLTTGOTO(S, X, Y)	MLTTPUTS(tgoto(tgetstr((S), NULL), (X), (Y)))
# define MLT_TGOTO(X, Y)	MLTTGOTO("cm", X, Y)

typedef struct				s_mlt
{
	struct termios			thermos;
	struct termios			original_thermos;
	struct winsize			w;
}							t_mlt;

typedef struct				s_mlt_img
{
	char					*img;
	int						co;
	int						li;
}							t_mlt_img;

/*
** mlt_util.c
*/
void	f_do_nothing(void);
int		mlt_spe_out(void);
int		mlt_tputs_putchar(int c);

/*
** mlt_signal.c
*/
void	mlt_init_signal(t_mlt *mlt_ptr);

/*
** mlt_init.c
*/
t_mlt	*mlt_init(void);
void	mlt_clear_window(t_mlt *mlt_ptr);
void	mlt_restore_term(struct termios *original_thermos);
void	mlt_recalc_win(t_mlt *mlt_ptr);
void	mlt_exit(t_mlt *mlt_ptr);

/*
** mlt_put
*/
void	mlt_char_put(int x, int y, int fg, int bg, char c);
void	mlt_string_put(int x, int y, int fg, int bg, char *str);
void	mlt_img_put(t_mlt_img *str);

/*
** mlt_loop and hooks
*/
void	mlt_loop(t_mlt *mlt_ptr);
void	mlt_key_hook(t_mlt *mlt_ptr, void (*f)(int, void *), void *param);
void	mlt_expose_hook(t_mlt *mlt_ptr,
						void (*f)(int x, int y, void *),
						void *param);
void	mlt_loop_hook(t_mlt *mlt_ptr, void (*f)(void *), void *param);

/*
** mlt_image.c
*/
t_mlt_img	*mlt_new_img(int dim_x, int dim_y);
void	mlt_free_img(t_mlt_img *img);
void	mlt_char_put_img(t_mlt_img *img, int x, int y, int fg, int bg, char c);

#endif /* !__MLT_H */


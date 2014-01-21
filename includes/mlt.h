/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skunne <skunne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 20:03:53 by skunne            #+#    #+#             */
/*   Updated: 2014/01/19 18:11:52 by skunne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLT_H
# define MLT_H

# define MLT_BLACK				0
# define MLT_RED				1
# define MLT_GREEN				2
# define MLT_YELLOW				3
# define MLT_BLUE				4
# define MLT_MAGENTA			5
# define MLT_CYAN				6
# define MLT_LIGHTGREY			7
# define MLT_DARKGREY			8
# define MLT_LIGHTRED			9
# define MLT_LIGHTGREEN			10
# define MLT_LIGHTYELLOW		11
# define MLT_LIGHTBLUE			12
# define MLT_LIGHTMAGENTA		13
# define MLT_LIGHTCYAN			14
# define MLT_WHITE				15
# define MLT_COLOUR(R, G, B)	(16 + ((R) * 36) + ((G) * 6) + (B))
# define MLT_GREY(X)			(216 + (X))

/*
** mlt_init.c
*/
void	*mlt_init(void);
void	mlt_clear_window(void *mlt_ptr);
void	mlt_recalc_win(void *mlt_ptr);
void	mlt_exit(void *mlt_ptr);

/*
** mlt_put
*/
void	mlt_char_put(int x, int y, int fg, int bg, char c);
void	mlt_string_put(int x, int y, int fg, int bg, char *str);

/*
** mlt_loop and hooks
*/
void	mlt_loop(void *mlt_ptr);
void	mlt_key_hook(void *mlt_ptr, void (*f)(int, void *), void *param);
void	mlt_expose_hook(void *mlt_ptr,
						void (*f)(int x, int y, void *),
						void *param);
void	mlt_loop_hook(void *mlt_ptr, void (*f)(void *), void *param);

#endif /* !MLT_H */


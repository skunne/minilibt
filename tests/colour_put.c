#include <term.h>
#include <curses.h>
#include <libc.h>
#include <unistd.h>

/*
**  Testing how we use colors in termcaps.
*/

int				main(void)
{
	char		buff[1024];
	char		*b;

	tgetent(NULL, getenv("TERM"));
	b = buff;
	// On cherche a reproduire :
	//write(1, tgoto(tgetstr("AB", NULL), 0, 169), 100);

	strcpy(buff, tgoto(tgetstr("AB", NULL), 0, 17));
	write(1, buff + 1, 100);
	write(1, buff, 200);

	write(1, "attention on rechange!", 20);
	write(1, "\E[48;5;177mbleuh", 20);

	write(1, "bouh", 4);
	return (0);
}

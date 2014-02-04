#include <term.h>
#include <curses.h>
#include <libc.h>
#include <unistd.h>

/*
**  Testing how we use colors in termcaps.
**
** Results :
** - tgoto : is actually a function to parse arguments
**           to a capability.
** - how we change background color : send a string like
**           \E[48;5;COLOR_INDEXm //for 256 color mode
** - " " " " " " " foreground color : " " " " " " " " "
**           \E[38;5;COLOR_INDEXm //for 256 color mode
*/

int				main(void)
{
	char		buff[1024];
	char		buff2[1024];

	tgetent(NULL, getenv("TERM"));

	// On cherche a reproduire :
	//write(1, tgoto(tgetstr("AB", NULL), 0, 169), 100);

	strcpy(buff, tgoto(tgetstr("AB", NULL), 0, 17));
	write(1, buff + 1, 10);
	write(1, buff, 20);

	write(1, "\nattention on rechange!\n", 20);
	write(1, "\E[48;5;199mbleuh\n", 20);

	strcpy(buff2, tgoto(tgetstr("AF", NULL), 0, 45));
	write(1, buff2 + 1, 20);
	write(1, buff2, 20);

	write(1, "\nattention on rechange!\n", 20);
	write(1, "\E[38;5;100mbleuh\n", 20);

	write(1, "bouh\n", 4);
	return (0);
}

#include <term.h>
#include <curses.h>
#include <unistd.h>
#include <libc.h>
#include <__mlt.h>

int				main(void)
{
	char		buff[1024];
	char		*s1;
	char		*s2;

	tgetent(NULL, getenv("TERM"));
	strcpy(buff, "abcdefghijklmnopqrstuvwxyz");
	s2 = buff;
	s1 = tgetstr("mr", &s2);
	s2 -= 1;
	tgetstr("us", &s2);
	strcpy(s2, "coucou");
	s2 += 6;
	tgetstr("do", &s2);
	s2 -= 1;
	tgetstr("me", &s2);
	write(1, s1, 199);		// <---- Un seul write !
	//tgetstr("us", &(s2 - 1));
	//tgetstr("us", &(*&s2 - 1));
	//tputs(s1, 1, &mlt_tputs_putchar);
	//printf("s1[%s] s2[%s] buff[%s]\n", s1, s2, buff);
	//MLTTPUTS(s1);
	//MLTTPUTS("COUCOU");
	//write(1, "coucou", 6);
	return (0);
}

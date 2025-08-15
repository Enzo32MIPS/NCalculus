#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

void draw_button(WINDOW *win, int y, int x, const char *lable, int is_selected);

int main(){

	int destaque = 1;
	int linha, coluna, meiolinha,meiocoluna,iniciolinha,iniciocoluna;
	char temp[20];

	initscr();
	getmaxyx(stdscr,linha,coluna);

	meiolinha = linha/2;
	meiocoluna = coluna/2;
	iniciolinha = linha/4;
	iniciocoluna = coluna/4;

	WINDOW* win = newwin(meiolinha,meiocoluna,iniciolinha,iniciocoluna);
	if (win == NULL){
		system("clear");
		endwin();
		printf("Erro na renderizacao!\n");
	}
	keypad(win,TRUE);

	box(win, 0, 0);
	mvwprintw(win,1,(iniciocoluna-(strlen("Deu certo!"))/2), "Deu certo!");

	draw_button(win,4,2,"1", (destaque == 1));
	draw_button(win,4,5,"2",(destaque == 2));
	draw_button(win,4,8,"3", (destaque == 2));
	draw_button(win,4,11,"+", (destaque == 2));
	draw_button(win,5,2,"4",(destaque == 2));
	draw_button(win,5,5,"5", (destaque == 2));
	draw_button(win,5,8,"6",(destaque == 2));
	draw_button(win,5,11,"-",(destaque == 2));
	draw_button(win,6,2,"7", (destaque == 2));
	draw_button(win,6,5,"8",(destaque == 2));
	draw_button(win,6,8,"9", (destaque == 2));
	draw_button(win,6,11,"X", (destaque == 2));
	draw_button(win,7,2,"C",(destaque == 2));
	draw_button(win,7,5,"0",(destaque == 2));
	draw_button(win,7,8,"=",(destaque == 2));
	draw_button(win,7,11,"/",(destaque == 2)); 
	wrefresh(win);

	setbuf(stdin, NULL);
	mvwscanw(win, 16, iniciocoluna, "%s", temp);
	wrefresh(win);

	endwin();

	return 0;


}

void draw_button(WINDOW *win, int y, int x, const char *lable, int is_selected){
    if(is_selected == 1) wattron(win, A_REVERSE);

    mvwprintw(win, y, x, "[%s]", lable);
    wattroff(win, A_REVERSE);
    wrefresh(win);
}
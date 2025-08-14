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

	draw_button(win,4,iniciocoluna-(strlen("1. Step")/2),"1. Step", (destaque == 1));
	draw_button(win,5,iniciocoluna-(strlen("2. Show data memory")/2),"2. Show data memory",(destaque == 2));
	draw_button(win,6,iniciocoluna-(strlen("3. Show registers")/2),"3. Show Registers",(destaque == 3));
	draw_button(win,7,iniciocoluna-(strlen("4. Mostrar simais de controle")/2),"4. Mostrar sinais de controle", (destaque == 4));
	draw_button(win,8,iniciocoluna-(strlen("5. Show all instructions")/2),"5. Show all instructions", (destaque == 5));
	draw_button(win,9,iniciocoluna-(strlen("6. Show instruction to run")/2),"6. Show instruction to run", (destaque == 6));
	draw_button(win,10,iniciocoluna-(strlen("7. Make .asm")/2),"7. Make .asm", (destaque == 7));
	draw_button(win,11,iniciocoluna-(strlen("8. Load data memory")/2),"8. Load data memory", (destaque == 8));
	draw_button(win,12,iniciocoluna-(strlen("9. Store data memory")/2),"9. Store data memory", (destaque == 9));
	draw_button(win,13,iniciocoluna-(strlen("10. Load instruction memory")/2),"10. Load instruction memory", (destaque == 10));
	draw_button(win,14,iniciocoluna-(strlen("11. Run")/2),"11. Run", (destaque == 11));
	draw_button(win,15,iniciocoluna-(strlen("12. Back")/2),"12. Back", (destaque == 12));
	draw_button(win,16,iniciocoluna-(strlen("13. Exit")/2),"13. Exit", (destaque == 13));

	wrefresh(win);
	//system("clear");
	endwin();

	return 0;


}

void draw_button(WINDOW *win, int y, int x, const char *lable, int is_selected){
    if(is_selected == 1) wattron(win, A_REVERSE);

    mvwprintw(win, y, x, "[%s]", lable);
    wattroff(win, A_REVERSE);
    wrefresh(win);
}
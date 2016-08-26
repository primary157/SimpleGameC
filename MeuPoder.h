#ifndef MEU_PODER_H_INCLUDED
#define MEU_PODER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef struct {	
	int x, y;	
} Position;

void print_frame(Position player);
void init_Position(Position* position);
int save_pos(FILE* save,char mode, int* x, int* y);
int game_loop(Position* position);
#endif

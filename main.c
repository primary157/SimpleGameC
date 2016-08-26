#include "MeuPoder.h"
int main(){
	Position position;
	FILE *save = NULL;
	
	if(!save_pos(save, 'r',&position.x,&position.y)){
		init_Position(&position);
	}
	printf("Press Q to close and save the program, or E to close without saving.\n Press W,S,A,D to move the position!\n");

	if(game_loop(&position) == 'q'){
		save_pos(save,'w',&position.x,&position.y);
	}
	return 0;
}

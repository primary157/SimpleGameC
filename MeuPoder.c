#include <stdio.h>
#include <stdlib.h>
typedef struct {	
	int x, y;	
} Position;

void print_frame(Position player){
        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j < 7; j++){
                if(player.x == i && player.y == j){
                    printf("o\t");
		}
                else{
                    printf("x\t");
		}
            }
            printf("\n");
        }	
}
void init_Position(Position* position){
	position->x = position->y = 5;
}
int save_pos(FILE* save,char mode, int* x, int* y){
	if((save = fopen("save.dat",&mode)) == NULL){
		return 0;
	}
	else{
		switch(mode){
			case 'r':
				fscanf(save,"%d %d", x, y);
				break;
			case 'w':
				fprintf(save,"%d %d", *x, *y);
		}
		fclose(save);
		return 1;
	}
}
int game_loop(Position* position){
	char key;
	do{
		print_frame(*position);
		scanf("%c",&key);
		getchar();          //n sei pq isso existe!!
		if((key == 'a') && (position->y > 0))
		    position->y = position->y - 1;
		else
		    if((key == 'd')  && (position->y < 6))
			position->y = position->y + 1;
		    else
			if((key == 'w')  && (position->x > 0))
			    position->x = position->x - 1;
			else
			    if((key == 's')  && (position->x < 6))
				position->x = position->x + 1;
	}while ((key != 'q') && (key != 'e'));
	return key;
}
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

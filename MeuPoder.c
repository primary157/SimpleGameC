#include <stdio.h>
#include <stdlib.h>
#define pi 3.14
struct 
{	
	int x, y;	
} position;

void print_frame()
{
        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j < 7; j++){
                if(position.x == i && position.y == j)
                    printf("o\t");
                else
                    printf("x\t");
            }
            printf("\n");
        }	
}

int main()
{
	printf("pi");
	FILE *save;
	char key;

	if((save = fopen("save.dat","r")) == NULL)
		position.x = position.y = 5;
	else
	{
		fscanf(save,"%d %d", &position.x, &position.y );
		fclose(save);
	}
	printf("Press Q to close and save the program, or E to close without saving.\n Press W,S,A,D to move the position!\n");
	do{
		print_frame();
		scanf("%c",&key);
		getchar();          //n sei pq isso existe!!
		if((key == 'a') && (position.y > 0))
		    position.y = position.y - 1;
		else
		    if((key == 'd')  && (position.y < 6))
			position.y = position.y + 1;
		    else
			if((key == 'w')  && (position.x > 0))
			    position.x = position.x - 1;
			else
			    if((key == 's')  && (position.x < 6))
				position.x = position.x + 1;
	}while ((key != 'q') && (key != 'e'));
	if(key == 'q')
	{
		if((save = fopen("save.dat","w+")) == NULL)
			printf("Failed during game save.");
		else
			fprintf(save, "%d %d", position.x, position.y);
		fclose(save);
	}
	return 0;
}

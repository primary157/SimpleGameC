#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *save;
    char key;
    int position[2];
    if((save = fopen("save.dat","r")) == NULL)
    {
        position[0] = position[1] = 5;
    }
    else
    {
        fscanf(save,"%d %d", &position[0], &position[1] );
    	fclose(save);
    }

    printf("Press Q to close the program\n Press W,S,A,D to move the position!\n");
    do{

        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j < 7; j++){
                if(position[0] == i && position[1] == j)
                    printf("o\t");
                else
                    printf("x\t");
            }
            printf("\n");
        }
        scanf("%c",&key);
        getchar();          //n sei pq isso existe!!


        if((key == 'a') && (position[1] > 0))
            position[1] = position[1] - 1;
        else
        {
            if((key == 'd')  && (position[1] < 6))
                position[1] = position[1] + 1;
            else
            {
                if((key == 'w')  && (position[0] > 0))
                    position[0] = position[0] - 1;
                else
                {
                    if((key == 's')  && (position[0] < 6))
                        position[0] = position[0] + 1;
                }
            }
        }
    }while (key != 'q');

    if((save = fopen("save.dat","w+")) == NULL)
    {
	    printf("Failed during game save.");
    }
    else
    {
	    fprintf(save, "%d %d", position[0], position[1]);
    }
    fclose(save);
    return 0;
}


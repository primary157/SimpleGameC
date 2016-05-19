#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *save;
    char key;
    int character[2];
    if((save = fopen("save.dat","r")) == NULL)
    {
        character[0] = character[1] = 5;
    }
    else
    {
        fscanf(save,"%d %d", &character[0], &character[1] );
    	fclose(save);
    }

    printf("Press Q to close the program\n Press W,S,A,D to move the character!\n");
    do{

        for(int i = 0; i < 7; i++)
        {
            for(int j = 0; j < 7; j++){
                if(character[0] == i && character[1] == j)
                    printf("o\t");
                else
                    printf("x\t");
            }
            printf("\n");
        }
        scanf("%c",&key);
        getchar();          //n sei pq isso existe!!


        if((key == 'a') && (character[1] > 0))
            character[1] = character[1] - 1;
        else
        {
            if((key == 'd')  && (character[1] < 6))
                character[1] = character[1] + 1;
            else
            {
                if((key == 'w')  && (character[0] > 0))
                    character[0] = character[0] - 1;
                else
                {
                    if((key == 's')  && (character[0] < 6))
                        character[0] = character[0] + 1;
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
	    fprintf(save, "%d %d", character[0], character[1]);
    }
    fclose(save);
    return 0;
}


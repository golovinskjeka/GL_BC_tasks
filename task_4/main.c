#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int moveRow = 1;
int moveCol = 0;
int direction = 0;

int row = 0; //start point
int col = 5; //start point

int finishRow = 11;
int finishCol = 5;

char labyrinth[12][11] = {
    {'-','-','-','-','-','-','-','-','-','-','-'},
    {'-','-','-','-','-',' ','-','-','-','-','-'},
    {'|',' ',' ',' ',' ',' ','|',' ',' ',' ','|'},
    {'|','-','-','-','-',' ','-','-','-',' ','|'},
    {'|',' ',' ',' ','|',' ',' ',' ',' ',' ','|'},
    {'|',' ','|',' ','-','-','-','-','-',' ','|'},
    {'|',' ','|',' ',' ',' ',' ',' ',' ',' ','|'},
    {'|','-','-',' ','-','-','-',' ','|',' ','|'},
    {'|',' ',' ',' ','|',' ',' ',' ','|',' ','|'},
    {'|',' ','-','-','-','-','-','-','-',' ','|'},   
    {'|',' ',' ',' ',' ',' ','|',' ',' ',' ','|'},
    {'-','-','-','-','-',' ','-','-','-','-','-'},
};



int stepForward(){
    if(!(row == finishRow && col == finishCol)){
        if(labyrinth[row+moveRow][col+moveCol] == '0')labyrinth[row][col] = ' ';
        row += moveRow;
        col += moveCol;
        labyrinth[row][col] = '0';
        setDir(90);
        if(checkWall()) stepForward();
        else{
            setDir(-90);
            if(checkWall()) stepForward();
            else{
                setDir(-90);
                if(checkWall()) stepForward();
                else{
                    setDir(-90);
                    stepForward();
                }
            }
        }
    }
 }

void setDir(int change){
    direction += change;
    if(direction < 0) direction += 360;
    if(direction > 359) direction -= 360;
    switch(direction){
        case 0:
            moveRow = 1;
            moveCol = 0;
            break;
        case 90:
            moveRow = 0;
            moveCol = -1;
            break;
        case 180:
            moveRow = -1;
            moveCol = 0;
            break;
        case 270:
            moveRow = 0;
            moveCol = 1;
            break;
    }
}

int checkWall(){
    return (labyrinth[row+moveRow][col+moveCol] != '-' && labyrinth[row+moveRow][col+moveCol] != '|' );
}

void printLab(){
    for(int i = 0; i < sizeof(labyrinth)/sizeof(labyrinth[0]); i++){
        for(int j = 0; j < sizeof(labyrinth[0])/sizeof(labyrinth[0][0]) ; j++){
            printf("%c", labyrinth[i][j]);
        }
        printf("\r\n");
    }
    printf("\r\n");
}

int main()
{   
    printf("Labyrinth is created:\r\n");
    printLab();
    stepForward();
    printf("Labyrinth is completed:\r\n");
    printLab();
    return 0;
}
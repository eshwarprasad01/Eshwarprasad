#include<stdio.h>
#include<stdlib.h>		 // to use rand and srand functions
#include<conio.h>		 // to use kbhit function
#include<time.h>		 // to use the function time();
#include<windows.h>		 // to use the function gotoxy
#define rows 30
#define colomns 60
int fruit_x,fruit_y;	// coordinates of fruit generated
int snake_x,snake_y;	// coordinates of snake
int i,j,score;
int key;				// Key pressed - up,down,left,righ...
void delay(float number_of_seconds)		// To control the speed of the snake
{
    // Converting time into milli_seconds
    float milli_seconds = 1000 * number_of_seconds;
	// Storing start time
    clock_t start_time = clock();
	// looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}
void gotoxy(short x,short y)	// To place the cursor at required position
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void boundary();		//  for drawing boundary in which the snake moves
void printfruit();		// for printing the randomly generated fruit
void clearsnake();		// to remove the snake from its previous position
void movesnake();		// for printing the snake at the new position
void input();			// taking intput keys - up , down , right , left and x(to exit the game).
void game();			// for implementing logic of the game
int main(){
	boundary();
	snake_x=colomns/2;		// Initializing x and y coordinates...
    	snake_y=rows/2;			// of the snake
    	gotoxy(snake_x,snake_y);
    	printf("0");
    	srand(time(0));		// a library function which generates different random numbers with respect to time in seconds
	printfruit();
	while(1){
		input();
		game();
	}
}
void boundary(){
    for(i=0;i<rows;i++){
        for(j=0;j<colomns;j++){
            if(i==0 || j==0 || i==rows-1 || j==colomns-1)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
    printf("\n\n");
    printf("Enter x to stop the game.");
}
void printfruit()
{
	fruit_x=(rand()%(colomns-2))+1;		// Generating random x , y coordinates...
    	fruit_y=(rand()%(rows-2))+1;		    // for the fruit
    	gotoxy(fruit_x,fruit_y);
	printf("+");
	gotoxy(0,0);
}
void clearsnake()
{
	gotoxy(snake_x,snake_y);		// Generating random x , y coordinates...
	printf(" ");					// for the snake
	gotoxy(0,0);
}
void movesnake()
{
	gotoxy(snake_x,snake_y);		// Placing the cursor at required position
	printf("0");
	gotoxy(0,0);
}
void input(){
    if(kbhit()){				// kbhit() a library function which returns a non zero value on pressing any key 	
        switch(getch()){	
            case 72:		// up	
		key=1;
                break;
            case 80:		// down
                key=2;
                break;
            case 75:		// left
                key=3;
                break;
            case 77:		// right
                key=4;
                break;
            case 'x':		// for exit
            	gotoxy(0,rows+3);
                exit(0);
        }
    }
}
void game(){
    delay(0.09);	// To contol the speed of the snake
    switch(key){
        case 1:
        	clearsnake();
            	snake_y--;
            	if(snake_y==0)
			snake_y=rows-2;		// To generate snake at opposite side of the boundary
	    	movesnake();
            	break;
        case 2:
        	clearsnake();
            	snake_y++;
            	if(snake_y==rows-1)
            		snake_y=1;			// To generate snake at opposite side of the boundary
            	movesnake();
            	break;
        case 3:
        	clearsnake();
        	snake_x--;
        	if(snake_x==0)
        		snake_x=colomns-2;  // To generate snake at opposite side of the boundary
            	movesnake();
            	break;
        case 4:
        	clearsnake();
            	snake_x++;
            	if(snake_x==colomns-1)
            		snake_x=1;			// To generate snake at opposite side of the boundary
            	movesnake();
            	break;
    }
    if(snake_x==fruit_x && snake_y==fruit_y){  // if both snake and fruit coordinates becomes equal
        score++;
        gotoxy(0,rows+1);
		printf("Score : %d",score);
		if(score==20)
			exit(1);
		printfruit();		// generating a new fruit
    }
}


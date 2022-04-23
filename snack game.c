#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <unistd.h>
#define rows1 30
#define rows2 60
int r1,r2,i,j;
int x,y,gameover,flag;
int score;
void setup(){
	gameover=0;
	x=rows1/2;
    y=rows2/2;
    srand(time(0));
    r1=(rand()%(rows1-2))+2;
    r2=(rand()%(rows2-2))+2;
    score=0;
}
void boundary(){
	system("cls");
    for(i=1;i<=rows1;i++){
        for(j=1;j<=rows2;j++){
            if(i==1 || j==1 || i==rows1 || j==rows2)
                printf("#");
            else if(r1==i && r2==j)
                    printf("*");
            else if(i==x && j==y)
                    printf("0");
            else
                printf(" ");
        
        }
        printf("\n");
    }
    printf("score = %d\n", score);
    printf("Press X to exit the game: ");
}
void input(){
    if(kbhit()){  	
        switch(getch()){	
            case 72:	
				flag=1;
                break;
            case 80:
                flag=2;
                break;
            case 75:
                flag=3;
                break;
            case 77:
                flag=4;
                break;
            case 'x':
                gameover=1;
                break;
        }
    }
}
void game(){
//    sleep(0);
    switch(flag){
        case 1:
            x--;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        case 4:
            y++;
            break;
    }
    if(x<=1 || x>=rows1 || y<=1 || y>=rows2){
        gameover=1;
    }
    if(x==r1 && y==r2){
        score+=1;
        r1=(rand()%(rows1-2))+2;
        r2=(rand()%(rows2-2))+2;
    }
}
int main(){
    setup();
    while(!gameover){
        boundary();
        input();
        game();
    }
    
    
}


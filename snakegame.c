#include<stdio.h>
#include<stdlib.h>		 
#include<conio.h>		 
#include<time.h>		 
#include<windows.h>		 
#define rows 30
#define colomns 60
int fruit_x,fruit_y;	
int snake_x,snake_y;	
int i,j,score;
int key;
struct node
{
	int co_x;
	int co_y;
	struct node *next;
};
struct node * head=NULL,*tail=NULL;
int lastnodex,lastnodey;				
void delay(float number_of_seconds)		
{
    // Converting time into milli_seconds
    float milli_seconds = 1000 * number_of_seconds;
	// Storing start time
    clock_t start_time = clock();
	// looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}
void gotoxy(short x,short y)	
{
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void boundary();		
void printfruit();		
void clearsnake();		
void movesnake();		
void input();			
void game();
void check();
void createnode();			
int main(){
	boundary();
	snake_x=colomns/2;		
    snake_y=rows/2;			
    gotoxy(snake_x,snake_y);
    printf("0");
    srand(time(0));		
	printfruit();
	createnode();
	while(1){
		input();
		game();
		check();
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
	fruit_x=(rand()%(colomns-2))+1;		
    fruit_y=(rand()%(rows-2))+1;		
    gotoxy(fruit_x,fruit_y);
	printf("+");
	gotoxy(0,0);
}
void createnode()
{
	struct node *temp;
	
	if(head==NULL)
	{
		temp=(struct node *)malloc(sizeof(struct node));
		head=temp;
		temp->next=NULL;
		temp->co_x=snake_x;
		temp->co_y=snake_y;
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}

	if(head!=NULL)
	{
		temp->next=(struct node *)malloc(sizeof(struct node));
		temp=temp->next;
		temp->co_x=lastnodex;
		temp->co_y=lastnodey;
		temp->next=NULL;
	}
}
void input(){
    if(kbhit()){			
        switch(getch()){	
            case 72:	
		key=1;
                break;
            case 80:	
                key=2;
                break;
            case 75:	
                key=3;
                break;
            case 77:	
                key=4;
                break;
            case 'x':	
            	gotoxy(0,rows+3);
                exit(0);
        }
    }
}
void game(){
	int a1=snake_x;
	int b1=snake_y;
	int found;
	delay(0.09);
    switch(key){
        case 1:
            b1--;
            if(b1==0)
		b1=rows-2;	
            break;
        case 2:
            b1++;
            if(b1==rows-1)
            	b1=1;		
            break;
        case 3:
        	a1--;
        	if(a1==0)
			a1=colomns-2; 
            break;
        case 4:
            a1++;
            if(a1==colomns-1)
            	a1=1;		
            break;
    }
    if(snake_x==fruit_x && snake_y==fruit_y){ 
        score++;
        createnode();
        gotoxy(0,rows+1);
		printf("Score : %d",score);
		if(score==30)
			exit(1);
		printfruit();	
    }
	struct node*temp=head;
	while(temp){
		found=0;
		if(temp->co_x==a1&&temp->co_y==b1){
			found=1;
			if(a1==head->next->co_x||b1==head->next->co_y){
				break;
			}
		break;
		}
		temp=temp->next;
	}
	if(found==0){
		clearsnake();
		snake_x=a1;
		snake_y=b1;
		changecoordinates(snake_x,snake_y);
		printsnake();
	}
	gotoxy(0,0);
	
}
void check(){
	int win=0;
	struct node *temp=head->next;
	while(temp){
		if(head->co_x == temp->co_x && head->co_y==temp->co_y)
			exit(0);
		temp=temp->next;
	}
}
void printsnake(){
	struct node*temp=head;
	while(temp){
		gotoxy(temp->co_x,temp->co_y);
		if(temp==head)
			printf("0");
		else 
			printf("O");
		temp=temp->next;
	}
}
void clearsnake(){
	struct node*temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	gotoxy(temp->co_x,temp->co_y);
    printf(" ");
}
void changecoordinates(int new_x,int new_y){
	struct node*temp=head;
	int temp1,temp2;
	while(temp){
		temp1=temp->co_x;
		temp2=temp->co_y;
		temp->co_x=new_x;
		temp->co_y=new_y;
		new_x=temp1;
		new_y=temp2;
		temp=temp->next;
	}
	lastnodex=temp1;
	lastnodey=temp2;
}

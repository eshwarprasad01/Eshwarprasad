#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	srand(time(0));
	int a,b;
	while(1){
		a=rand()%3+1;
		printf("Select rock(1) , paper(2) or scissors(3) : ");
		scanf("%d",&b);
		switch(a){
			case 1:printf("AI selected rock\n");
					break;
			case 2:printf("AI selected paper\n");
					break;
			case 3:printf("AI selected scissors\n");
					break;
		}
		if( a==1&&b==2 || a==2&&b==3 || a==3&&b==1){
			printf("You win.");
			break;
		}
		else if(b==1&&a==2 || b==2&&a==3 || b==3&&a==1){
			printf("AI wins.");
			break;
		}
	}
}


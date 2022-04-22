#include<stdio.h>
#include<stdlib.h>
void print(char a[3][3]){
    int j,i;
    printf("\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(j==2)
                printf("  %c  ",a[i][j]);
            else
                printf("  %c  |",a[i][j]);
        }
        if(i==2);
        else
            printf("\n ---------------\n");
    }
}
int g=1;
void replace(char a[3][3],char b){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(a[i][j]==b){
                if(g%2==1)
                    a[i][j]='X';
                else
                    a[i][j]='O';
            }
        }
    }
    g++;
}
void winner(char a[3][3],char*p1,char*p2){
    int i,j;
    for(i=0;i<3;i++){
        int r1=0,r2=0,c1=0,c2=0,r3=0,c3=0,d1=0,d2=0;
        for(j=0;j<3;j++){
            if(a[i][j]=='X')
                r1++;
            if(a[i][j]=='O')
                c1++;
            if(a[j][i]=='X')
                r2++;
            if(a[j][i]=='O')
                c2++;
            if(a[j][j]=='X')
                r3++;
            if(a[j][j]=='O')
                c3++;
            if(i==1 && j==1){
                if(a[i][j]=='X'  &&  a[i+1][j-1]=='X'  &&  a[i-1][j+1]=='X'){
                    d1++;
                    break;
                }
                if(a[i][j]=='O'  &&  a[i+1][j-1]=='O'  &&  a[i-1][j+1]=='O'){
                    d2++;
                    break;
                }
                   
            }
        }
        if(r1==3 || r2==3 || r3==3 || d1==1){
            printf("\n\nWinner = %s.",p1);
            exit(0);
        }
        else if(c1==3 || c2==3 || c3==3 || d2==1){
            printf("\n\nWinner = %s.",p2);
            exit(1);
        }
    }
}
int main(){
    char a[3][3]={'1','2','3','4','5','6','7','8','9'};
    char p1[100],p2[100];
    printf("Enter Player 1 name: ");
    scanf("%s",p1);
    printf("Enter Player 2 name: ");
    scanf("%s",p2);
    print(a);
    int i,j;
    char p,q;
    int turns=0;
    printf("\n\nselect any place:-\n");
    while(1){
        printf("\n\n %s: ",p1);
        scanf(" %c",&p);
        turns++;
        replace(a,p);
        print(a);
        winner(a,p1,p2);
        if(turns==9){
        	printf("\n\n Draw Match.");
        	break;
		}
        printf("\n\n %s: ",p2);
        scanf(" %c",&q);
        turns++;
        replace(a,q);
        print(a);
        winner(a,p1,p2);
    }
}


#include <stdio.h>
#include<stdlib.h>
int main()
{
    char ch;
    int i;
    char password[100];
    int j=0;
    // while typing your password it will be appearing as stars 
    printf("Type the password correctly at one go: ");
    for (i = 0; i < 50; i++){
    	ch = getch();
    	if (ch != 13){
    		password[i] = ch;
    		ch = '*';
    		printf("%c", ch);
		}
		else
			break;
		j++;
    }
    printf("\n");
    // printing the typed pasaword
    printf("Your Password is : ");
	for(i=0;i<j;i++)
		printf("%c",password[i]);
	return 0;
}


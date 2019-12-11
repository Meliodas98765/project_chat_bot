#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define MAX 255
    int i=0;
void addQ(char quet[],char Ans[]);
struct all{

	int ptr=0;
	char q[MAX];
	char ans[MAX];

};struct all root[MAX];

void teach(){

    char temp[150];
    char temp1[150];
    char check[10];
	printf("Anything for me to learn(yes/no): \n");
    scanf("%s",&check);
    while(strcmp("yes",check)== 0){
        if(root[i].ptr == 0){

			printf("What do you want to teach: \n");
            gets(root[i].q);
			gets(root[i].q);
			printf("What's it's ans: \n");

			gets(root[i].ans);


            root[i].ptr=1;
		}
		strcpy(temp,root[i].q);
		strcpy(temp1,root[i].ans);
		addQ(temp,temp1);
        i++;
        printf("Anything else for me to learn(yes/no): \n");
        scanf("%s",&check);
    }
}
void addQ(char quet[],char Ans[]){

    char temp[150];
    char temp1[150];
    int id=1,id1=1;
    FILE *fptr,*aptr;
    fptr = fopen("questions.txt","r+");
    aptr = fopen("answer.txt","r+");
    while(!feof(fptr)){
        fscanf(fptr,"%s",temp);
        if(atoi(temp)!=0){
            id=atoi(temp);
            id++;
        }
    }
    while(!feof(aptr)){
        fscanf(aptr,"%s",temp1);
        if(atoi(temp1)!=0){
            id1=atoi(temp1);
            id1++;
        }
    }

    fprintf(fptr,"\n%d ",id);
    fprintf(aptr,"\n%d ",id1);
    fputs(quet,fptr);
    fputs(Ans,aptr);
    fclose(fptr);
    printf("done\n");
    fclose(aptr);
    printf("and remembered\n");


}
void display(){

    int c=0;
	if(root[c].ptr == 0)
        printf("Empty");
	else{
        while(root[c].ptr!= 0){
            printf("Q%d ",c);
            printf("%s\n",root[c].q);
            printf("(ans)\t");
            printf("%s\n",root[c].ans);
            c++;
        }
    }
}
/*void allComDisplay(){

    int c=0;
    char temp[150];
    FILE *fptr,*aptr;
    fptr=fopen("questions.txt","r");
    aptr=fopen("answer.txt","r");
    while(){
        fprintf(fptr,"Q%d\n",c);
        fgets(temp,150,fptr);
        fputs(temp,fptr);
        fprintf(aptr,"(ans)%d\n",c);
        fgets(temp,150,aptr);
        fputs(temp,aptr);
        c++;
    }
    printf("buu\n");
    fclose(fptr);
    fclose(aptr);
}*/
int main(){
	int op;
	do{

		printf("1.teach\n2.display\n3.All data display\n\n");
		scanf("%d",&op);
		switch(op){
			case 1:teach();
				break;
			case 2:display();
				break;
			//case 3:allComDisplay();
              //  break;
			default:printf("try between 1-3\n");
                break;
		}
	}while(op!=-1);
	getch();
	return 0;
}

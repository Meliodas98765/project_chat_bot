#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>

char temp[150];
char temp1[150];
char ans[150];
char quet[255];
int id=1,id1=1,cmp=0,ran,blank;


void compare();
void chat();
void conti_loop();
int memChan();
void rand_gen();


void rand_gen(){

    srand(time(0));
    for(int r=0;r<3;r++){
        ran+=rand();
    }
    ran%=4;
}
/*void chat_exten(){
    int i=0;
    FILE *inptr;
    inptr= fopen("words.txt","r+");
    while(quet[]){}
}*/
void conti_loop(){

    int i=0,j=0,l=0;
    rand_gen();
    while(quet[i]=='\0'){
        if(l==strlen(quet)){
            break;
        }
        l++;
        i++;
    }
    compare();
    chat();
    if(l==strlen(quet)){
            switch(ran/2){
                case 0:printf("hey, anyone there....\n");
                case 1:printf("i am waiting....\n");
            }
    }
    else if(cmp==0){
        printf("<bot>\t%s",temp);
    }
    else{
        switch(ran){
                case 0:printf("let me think......sorry i don't know. you should possibly find your answer from sensei.\n");
                break;
                case 1:printf("i asked to my family, even they had no answer for it.\n");
                break;
                case 2:printf("let me check online,\n\n\tLoading");
                        for(i=0;i<2;i++){
                            for(j=0;j<3;j++){
                                Sleep(600);
                                printf(".");
                                Sleep(600);
                                printf(".");
                                Sleep(600);
                                printf(".");
                            }

                        }
                        printf("\nohh!!!...No internet connection\n");
                break;
                case 3:printf("Language\n");
                break;
            }
    }
}
void compare(){

    int i=0,cp=0,len=strlen(quet);
    //printf("len%d\n",len);
    for(i=0;i<len;i++){

            if(temp[i]==quet[i]){
               // printf(" %d %c\t%c\n  match\n",i,temp[i],quet[i]);
                continue;
            }
            cp++;
            //printf(" %d %c\t%c\n  NO match!!!\n",i,temp[i],quet[i]);
    }
    //printf("(%d)\t(%d)",cp,cmp);
    cmp=cp;
    //printf("(%d)\t(%d)",cp,cmp);
    //printf("%s\t%s\n",temp,quet);
}
int memChan(){

    int len,j=0;

    len=strlen(temp);
    //printf("LEN%d\n",len);
    //printf("%d\n",len);
    /*for(j=0;j<len;j++){
        printf("%d\t%c\n",j+1,ans[j]);
    }
    j=0;*/
    //printf("(%s) \n",temp);
    for(int i=0;i<len;i++){
        temp[j]=temp[i+2];
        j++;
    }
    len=strlen(temp);
    //printf("\naaaaaa\t(%s)\t(%d)\n",temp,len);
}
void chat(){

    FILE *fptr,*aptr;
    fptr = fopen("questions.txt","r+");
    aptr = fopen("answer.txt","r+");
    fseek(fptr,0,SEEK_SET);
    fseek(aptr,0,SEEK_SET);

    while(!feof(fptr)){
        fgets(temp,150,fptr);
        id=atoi(temp);

        //fscanf(fptr,"%s",temp);
        //printf("%d\n",atoi(temp));
        memChan();
        //puts(temp);
        compare();
        //printf("------(%d)-------",cmp);
        if(cmp==0){
            //printf("\n\t\t\tmatch\n");
            //printf("%s",temp);
            break;
        }
        //printf("pass%d\n",id);
    }
    while(!feof(aptr)){

        fgets(temp1,150,aptr);
        id1=atoi(temp1);
        //printf("state%d\n",id1);
        if(id==id1){
            //printf("%d\n",id1);
            //printf("%d\n",id);
            //printf("%s\n",temp1);
            //printf("     %d\n",id1);
            //printf("found match!!\n");
            break;
        }

    }
    fclose(fptr);
    fclose(aptr);
    //printf("\n(%s)\t%d\n",temp,id);
    //printf("\n(%s)\t%d\n",temp1,id1);
    strcpy(temp,temp1);
    memChan();

}
int main(){

    int c;
    printf("<bot>\they\n<user>");
    while(1){
        c++;
        gets(quet);

        conti_loop();
        if(c%7==0||c%5==0){//SURPRISE
            switch(c%3){
                case 0:printf(">>>i do think you have a lot time to pass... \n");
                break;
                case 1:printf(">>>my creator said girls talk a lot..\n");
                break;
                case 2:printf(">>>you don't get tired...do you?  \n");
                break;
            }
        }
        printf("<user> ");
    }
    getch();
    return 0;

}

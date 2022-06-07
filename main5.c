/**********************************
project: county library management
author: Daniel Mukenya Nyongesa
date : 01/08/2021
license: MIT
compiler: C99
---------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

//adding user
//name:
//ID_number
//contact
//is_staff

struct user{
        int ID_number;
        char name[100];
        char tel[13];
        int is_staff;
};

//function prototype
void execute_action(int action);
void close();
int menu();
void add_user();
void view_user();
void add_book();
void view_books();
void user_delete_books();
void delete_user();


int main()
{
    int action;
    while(1){
        action = menu();
        execute_action(action);
        printf("press any key to continue");
        getchar();
        getch();
        system("cls");
    }
    return 0;
}

void execute_action(int action){
    switch(action) {
case 1:
    add_user();
    break;
case 2:
    view_user();
    break;
case 3:
    printf("adding book\n");
    break;
case 4:
    view_books();
    break;
case 5:
	user_delete_books();
	break;
case 6:
	delete_user();
	break;
case 7:
	close();
default:
    printf("sorry . i don't know how to execute that\n");
    }
}
void close(){
    printf("thank you for using the system\n");
    sleep(5000);
    exit(0);
}
    int menu(){
        int action;
do {
        printf("\tlibrary management system\n");
        printf("welcome Daniel Mukenya\n ");
        printf("1. Add user\n");
        printf("2. view user\n");
        printf("3. Add book\n");
        printf("4. View books\n");
        printf("5. User delete book\n");
        printf("6. Delete user\n");
        printf("7. Exit\n");
        printf("select action(1-7): ");
        scanf("%d",&action);
        ///validate input
        if (action < 1 || action > 7){
            printf("invalid action. Try again\n");
            sleep(2000);
            system("cls");
        }
    } while(action < 1 || action > 7);

    return action;
}
void add_user(){
    struct user u;
    FILE *fp;
     fp = fopen("user","ab");
     if (!fp){
        printf("unable to open file\n");
        exit(0);
    }

    printf("name: ");
    getchar();
    gets(u.name);
    printf("ID_number: ");
    scanf("%d",&u.ID_number);
    printf("phone number: ");
    scanf("%s",&u.tel);
    printf("user type(1 for staff,0 for ordinary user:");
    scanf("%d",&u.is_staff);

    fwrite(&u, sizeof(struct user), 1, fp);
    printf("user added successfully\n");
    fclose(fp);
}
void view_user(){
    struct user u;
    FILE *fp;

    fp = fopen("users","ab");
    if(!fp){
            printf("unable to open file");
            exit (0);
    }
    printf("ID_number\t\tname\t\t\t\tphone number is staff\n");
    while(!feof(fp)){
            fread(&u,sizeof(struct user), 1, fp);
            printf("%8d %20s %13s %1d\n",u.ID_number,u.name,u.tel,u.is_staff);
    }
    fclose(fp);
}
void view_books(){
    struct user u;
    FILE *fp;

    fp = fopen("users","ab");
    if(!fp){
            printf("unable to open file");
            exit (0);
    }
    printf("ID_number\t\tname\t\t\t\tphone number is staff\n");
    while(!feof(fp)){
            fread(&u,sizeof(struct user), 1, fp);
            printf("%8d %20s %13s %1d\n",u.ID_number,u.name,u.tel,u.is_staff);
    }
    fclose(fp);
}
void user_delete_books(){
    struct user u;
    FILE *fp;

    fp = fopen("users","ab");
    if(!fp){
            printf("unable to open file");
            exit (0);
    }
    printf("ID_number\t\tname\t\t\t\tphone number is staff\n");
    while(!feof(fp)){
            fread(&u,sizeof(struct user), 1, fp);
            printf("%8d %20s %13s %1d\n",u.ID_number,u.name,u.tel,u.is_staff);
    }
    fclose(fp);
}
void delete_user(){
    struct user u;
    FILE *fp;

    fp = fopen("users","ab");
    if(!fp){
            printf("unable to open file");
            exit (0);
    }
    printf("ID_number\t\tname\t\t\t\tphone number is staff\n");
    while(!feof(fp)){
            fread(&u,sizeof(struct user), 1, fp);
            printf("%8d %20s %13s %1d\n",u.ID_number,u.name,u.tel,u.is_staff);
    }
    fclose(fp);
}

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct 
{
    char first_name[20];
    char last_name[20];
    char user_name[20];
    char password[20];
    char active[20];
}User;



typedef union
{
 struct{
   char  flag[20] ;
     }operation ;
}Active;

User users[100];
int numUsers = 0;

int opt ;

//Registration
void registerUser()
{

        if (numUsers >= 100) {
        printf("Maximum number of users reached. Cannot register more users.\n");
        return;
    }

    User user ;

   Active active ;

    printf("\nRegistration:\n");


        printf("\nChoice Active: \n");
        printf("\n 1- Active :  \n");
        printf("\n 2- Not Active :  \n");
        printf("\n Your Operation : ");
        scanf("%d", &opt);

        if(opt == 1){
        strcpy(active.operation.flag,"true");
        strcpy(user.active,active.operation.flag);
        }
        else if(opt == 2){
        strcpy(active.operation.flag,"false");
        strcpy(user.active,active.operation.flag);
        }
        else{printf("Your Operation not match :(");}

        
        printf("\nEnter First Name:-  ");
        
        scanf("%s",user.first_name);

        
        printf("\nEnter last name:-  ");
        
        scanf("%s",user.last_name);

        
        printf("\nEnter Username:-  ");
        
        scanf("%s",user.user_name);

        
        printf("\nEnter Password:-  ");
        
        scanf("%s",user.password);


        
        users[numUsers++] = user;
        
        printf("\nRegistration successful!\n\n");
}


//Login
bool loginUser(){

Active active ;


    char user_name[20];
    char password[20];

    printf("\nLogin:\n\n");

    printf("Username:- ");
    scanf("%s", user_name);
    printf("\nPassword:- ");
    scanf("%s", password);

     for (int i = 0; i < numUsers; i++) {
        if (strcmp(user_name, users[i].user_name) == 0 && strcmp(password,users[i].password) == 0) {
             strcpy( active.operation.flag , "false");
           if (!strcmp(users[i].active , active.operation.flag) ){

            printf("\n\nSorry Sir your Account Is Not Actives :(");
         
            return 0;
           }
            return true;
        }
    }
    return false;
}



int main()
{
    int choice;
    bool loggedIn = false;


   while (choice != 0){
        printf("1. Register\n");
        printf("2. Login\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

           if(choice== 1)
        {
            
            registerUser();
        }

    else if(choice== 2)
        {   
            loggedIn = loginUser();
                if (loggedIn) {
                    printf("Login successful!\n");
                    break;
                } else {
                    printf("Invalid Process. Please try again.\n\n");

                }
        }
}

    return 0;
}

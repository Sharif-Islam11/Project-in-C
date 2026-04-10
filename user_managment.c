#include<stdio.h>
#include<string.h>
#include<conio.h>

#define max_user 10
int user_count= 0;

typedef struct{
    char name[30];
    char pass[30];
}user;

user users[max_user];

void register_user();
int login_user();
void input_name(char*);
void input_password(char*);
void input_fixed(char*);
void save_user();
void lode_user();

int main(){
    lode_user();
    int choice;
    int user_index;
    
    while(1){
    printf("\nwelcome to user managment...\n");
    printf("1. Registration...\n");
    printf("2. Login...\n");
    printf("3. Exit...\n");
    printf("enter your choice: ");
    scanf("%d", &choice);
    while(getchar() != '\n');

    switch (choice)
    {
    case 1:
        register_user();
        save_user();
        break;
    
    case 2:
        user_index= login_user();
        if(user_index>=0) printf("login succesful %s!\n", users[user_index].name);
        else printf("login faild!\n");
        break;

    case 3:
        printf("exiting program\n");
        return 0;
    
    default:
        printf("invalid choice try again..\n");
        break;
    }

    }

    return 0;
}

void register_user(){
    if(user_count >= max_user){
        printf("maximum %d user are allowed..\n", max_user);
    }
    int new_idx= user_count;
    input_name(users[new_idx].name);
    input_password(users[new_idx].pass);
    user_count++;
    printf("registration succesful\n\n");
    return;
}

int login_user(){
    char username[30];
    char password[30];
    input_name(username);
    input_password(password);
    for(int i=0; i<user_count; i++){
        if(strcmp(username, users[i].name)==0 && strcmp(password, users[i].pass)==0)return i;
    }
    return -1;
}

void input_name(char* username){
    printf("enter your username: ");
    fgets(username, 30, stdin);
    input_fixed(username);
    return;
}

void input_password(char* password){
    printf("enter your password : ");
    char ch;
    int i=0;
    while(1){
        ch=getch();
        if(ch==13){
            password[i]='\0';
            printf("\n");
            break;
        }
        else if(ch==8){
            if(i>0){
                i--;
                printf("\b \b");
            }
        }
        else{
            password[i] =ch;
            printf("*");
            i++;
        }
    }
}

void input_fixed(char* username){
    int idx= strcspn(username, "\n");
    username[idx]= '\0';
    return;
}

void save_user(){
    FILE* file=fopen("user.txt", "a");
    if(file==NULL){
        printf("file not opend!\n");
        return;
    }
    
    int i= user_count-1;
    fputs(users[i].name, file);
    fputs("\n", file);
    fputs(users[i].pass, file);
    fputs("\n", file);
    
    fclose(file);
    return;
}

void lode_user(){
    FILE* file=fopen("user.txt", "r");
    if(file==NULL){
        
        return ;
    }
    while(fgets(users[user_count].name, 30, file)!=NULL){
        input_fixed(users[user_count].name);
        if(fgets(users[user_count].pass, 30, file)==NULL) break;
        input_fixed(users[user_count].pass);
        user_count++;
        if(user_count>= max_user) break;
        
    }
    fclose(file);
    return;
}

// this project made by Sharif Islam.
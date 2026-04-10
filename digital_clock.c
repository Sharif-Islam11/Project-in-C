#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>

void get_Date(char*);
void get_time(char*, int);
int get_format();
void clear_screen();

int main(){

    
    char buffer[50];
    char date[50];
    int format = get_format();
    
    while(1){
    get_time(buffer, format);

    if(format<1 || format>2) {
        printf("Invalid format\n");
        break;
    }
    get_Date(date);
    clear_screen();
    printf("\n\n Time: %s", buffer);
    printf("\n Date: %s", date);


    printf("\n\n Developed by Sharif\n");
    sleep(1);
    }

    return 0;
}

    void clear_screen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


    int get_format(){
        int x;
        printf("\nChose your format");
        printf("\n1. 24h");
        printf("\n2. 12h");
        printf("\nchose 1 or 2 : ");
        scanf("%d",&x);
        return x;
}

    void get_time(char* buffer, int format){
        time_t raw_time;
        time(&raw_time);
        struct tm *current_time;
        current_time = localtime(&raw_time);
        if(format ==1){
            strftime(buffer, 50, "%H:%M:%S ", current_time);
        }
        else if(format == 2){
            strftime(buffer, 50, "%I:%M:%S %p", current_time);
        }
        
    }

    void get_Date(char* date){
        
            time_t raw_date;
            time(&raw_date);
            struct tm *curent_date;
            curent_date = localtime(&raw_date);
            strftime(date, 50, "%A, %B %d", curent_date);
        
        
    }


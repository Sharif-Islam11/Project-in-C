#include<stdio.h>
#include<math.h>

void print_manu();
double division(double, double);
int modulus(int, int);

int main(){
    printf("Welcome to simple calculator\n");
    int choice = 0;
    float first, second, result;
    while(choice != 7){
        printf("\n------------------------------\n");
       
        print_manu();

        printf("\n enter your choice : ");
        scanf("%d", &choice);
        if(choice == 7){
            printf("thanks for useing the simple calculator\n");
            break;
        }
        else if (choice<1 || choice>7)
        {
            fprintf(stderr,"Invalide manue choice\n");
        }
        
        
        printf("enter the first number : ");
        scanf("%f", &first);
        printf("enter the second number : ");
        scanf("%f", &second);
        
        switch(choice){
            case 1:
                result = first + second;
                break;
            case 2:
                result = first - second;
                break;
            case 3:
                result = first * second;
                break;
            case 4:
                result = division(first, second);
                break;
            case 5:
                result = modulus((int)first, (int)second);
                break;
            case 6:
                result = pow(first, second);
                break;
        }

        if(result != NAN){
            printf("result : %.2f", result);
        } 
    }
    return 0;
}
double division(double a, double b){
    if(b==0){
        fprintf(stderr, "Invalide argument for Division\n");
        return NAN;
    }
    else
        return a / b;
}

int modulus(int a, int b){
    if(b==0){
        fprintf(stderr, "Invalide argument for Modulus\n");
        return NAN;
    }
    else
        return a % b;
}


void print_manu(){
    printf("\n 1. Add");
        printf("\n 2. sub");
        printf("\n 3. mul");
        printf("\n 4. div");
        printf("\n 5. mod");
        printf("\n 6. pow");
        printf("\n 7. Exit");
}
//
// Created by Vlad on 22/02/2021.
//
#include <stdio.h>

void main_menu(){
    // Prints the menu for the application
    printf("\n");
    printf("1. Read a vector \n");
    printf("2. Compute the power \n");
    printf("3. Longest subsequence ex.8 \n");
    printf("4. Longest subsequence ex.7 \n");
    printf("0. Exit \n");
    printf("\n");
}

int power(int x, int n){
    // Knowing the values of the base x and of the exponent n, computes the power r.
    int i, r=1;
    for (i=0; i<n; i++){
        r = r*x;
    }
    return r;
}

int read_vector(int l, int a[]){
    // Knowing the length l of the vector [], read all the values of it.
    int i;
    printf("The length of the vector: \n");
    scanf("%d", &l);
    for (i=0; i<l; i++){
        printf("The value of a[%d]: \n", i);
        scanf("%u", &a[i]);
    }
    return l;
}

void subsequence_ex8(int a[], int l, int max_length, int *start_position, int *end_position){
    // Finds how many elements of a vector a[] respect the subsequence rule (adjacent elements have contrary signs) starting from position i and returns the length len.
    int i;
    for (i = 0; i < l - 1; i++) {
        int j = i;
        int len = 1;
        while ((a[j] >= 0 && a[j+1]<0 || a[j]<0 && a[j+1]>=0) && (j < l-1)){
            j++;
            len++;
        }
        if (len > max_length) {
            max_length = len;
            *start_position = i;
            *end_position = i + max_length;
        }
    }
}

void subsequence_ex7(int a[], int l, int min_value, int max_value, int *max_length, int *start_position, int *end_position){
    // Finds how many element of the vector a[] respect the subsequence rule (they are in a given interval) starting from position i and returns the length len.
    int i;
    for (i=0; i<l; i++) {
        int len = 0;
        int j = i;
        while (a[j] >= min_value && a[j] <= max_value && j < l) {
            j++;
            len++;
        }
        if (len > *max_length) {
            *max_length = len;
            *start_position = i;
            *end_position = i + *max_length;
        }
    }
}

void command_2(){
    int x, n;
    printf("Read the value of the base: \n");
    scanf("%d", &x);
    printf("Read the value of the power: \n");
    scanf("%d", &n);
    x = power(x, n);
    printf("The result is: %d\n", x);
}

void command_3(int l, int a[]){
    int start_position = 0, end_position = 0, max_length = -1;
    if (l == 0){
        printf("No vector was read before\n");
    }
    else{
        if (l == 1){
            printf("%d\n", a[0]);
        }
        else {
            int i;
            subsequence_ex8(a, l, max_length, &start_position, &end_position);
            printf("The longest subsequence (if there are more with the same length this will be the first one): \n");
            for (i = start_position; i < end_position; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
    }
}

void command_4(int l, int a[]){
    int min_element, max_element, start_position, end_position, max_length = -1, condition = 0;
    if (l == 0){
        printf("No vector was read before\n");
    }
    else{
        while (condition == 0){
            printf("Read the value of the minimum value of the interval: \n");
            scanf("%d", &min_element);
            printf("Read the value of the maximum value of the interval: \n");
            scanf("%d", &max_element);
            if (min_element <= max_element){
                condition = 1;
            }
            else{
                printf("Not a valid interval\n");
            }
        }
        if (l == 1){
            if ( min_element <= a[0] && a[0] <= max_element){
                printf("%d\n", a[0]);
            }
            else{
                printf("No subsequence in this interval\n");
            }
        }
        int i;
        subsequence_ex7(a, l, min_element, max_element, &max_length, &start_position, &end_position);
        if (max_length == 0){
            printf("No subsequence in this interval\n");
        }
        else{
            printf("The longest subsequence (if there are more with the same length this will be the first one): \n");
            for (i = start_position; i < end_position; i++) {
                printf("%d ", a[i]);
            }
        }
        printf("\n");
    }
}

int main(){
    // The main function of the application, with all the options one can choose.
    int ok = 1, l = 0, a[100], command;
    while (ok == 1) {
        main_menu();
        printf("Enter number of command: \n");
        scanf("%d", &command);

        if (command == 1){
            l = read_vector(l, a);
        }
        if (command == 2){
            command_2();
        }
        if(command == 3){
            command_3(l, a);
        }
        if (command == 4){
            command_4(l, a);
        }
        if (command == 0){
            ok = 0;
        }
        if (command != 1 && command != 2 && command != 3 && command != 4 && command != 0){
            printf("Not a valid command\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char user_name[20];
    char password[20];
} data_set;

int main(void) {
    //array of struct 
    data_set data[3] = {
        {"adam", "1234"},
        {"hani", "4356"},
        {"mohamed", "6667"}
    };
    int size = sizeof(data) / sizeof(data[0]);
    data_set active_users[1]; 
    
    char user[20], pass[20];
    int success = 0; // Flag to track login state
    int active_count =0 ;
    printf("Plz enter the user name and password: ");
    scanf("%s %s", user, pass);
    
    for(int i = 0; i < size; i++) {
        // strcmp returns 0 if strings match
        if(strcmp(user, data[i].user_name) == 0 && strcmp(pass, data[i].password) == 0) {
            printf("Successful login\n");
            // active_users[0].user_name == user;
            // active_users[0].password == pass;
            strcpy(active_users[active_count].user_name, data[i].user_name);
            strcpy(active_users[active_count].password , data[i].password);
            success = 1;
            break; // Stop checking once match is found
        }
        active_count++;
    }
    
    if(!success) {
        printf("Failed to login\n");
    }
    
    return 0;
}

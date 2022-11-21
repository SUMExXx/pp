#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int low;
int high;
int ranum;
int mode;
int tries;
int win;

// This function initialises the 'high' and 'mode' variables
// It takes no parameter and returns nothing.

void init(){
    low = 10;
    high = 60;
}

// This function prints the details of the three game modes and asks the user to input 1 for 1st game mode, 2 for 2nd game mode and 3 for
// 3rd game mode.    It takes no parameter and returns the value of tries variable

int chooseGameMode(){

    printf("\nChoose game mode:\n1 :  Range: 1 - 10  Tries : 2\n2 :  Range: 0 - 20  Tries : 3\n3 :  Range: 0 - 50  Tries : 5\nMode:\t");
    scanf("%d", &mode);

    if(mode == 1){
        tries = 2;
        low = 1;
        high = 11;
        return 2;
    }else if(mode == 2){
        tries = 3;
        low = 1;
        high = 21;
        return 3;
    }else if(mode == 3){
        tries = 5;
        low = 1;
        high = 51;
        return 5;
    }else {
        printf("\nWrong input");
        chooseGameMode();
    }
}

// This function picks a random number between the range [low, high] and assigns it to the variable 'ranum'

void choose(){
    srand(time(0));
    ranum = (rand() % (high - low)) + low;
    printf("\nA number between %d and %d was chosen",low, high-1);
}

// This function verifies whether the supplied string 'raw' is numeric or not and then it checks whether the numeric value of raw is in between
// low and high.     It takes three parameter : raw and returns 1 or 0

int isVerified(char raw[]){

    int value = atoi(raw);
    if((value>= low) && (value<high)){
        return 1;
    }else{
        return 0;
    }
}

// This function checks whether the raw_input (the numeric value) supplied by user is equal to the random number (ranum)
// or less or greater than ranum and also checks whether the number of tries left or not prints the message accordingly
// ("Correct!", "UP" and "DOWN").    It takes three parameter : raw_input, randum, tries and returns nothing.

void decide(char raw_input[], int randum, int triess) {
    char stat[10];
    win = 0;
    if (atoi(raw_input) == randum) {
        strcpy(stat, "CORRECT!");
        win = 1;

    } else if (atoi(raw_input) < randum) {
        strcpy(stat, "UP");
    } else {
        strcpy(stat, "DOWN");
    }

    if ((triess > 1) && (win == 0)) {
        printf("\n%s Tries: %d", stat, tries - 1);
    }

    if (win == 1){
        printf("\n%s You won the game!", stat);
    }
}

// This function is the entry point for the program. It contains init(), chooseGameMode(), choose() in order and then it takes input from
// user and runs isVerified() and decide() in a loop till the tries variable become 0. Then it exits out of the loop
// and asks the user whether to replay or not. Finally it prints "Have a good day :)"

void play(){
    init();
    tries = chooseGameMode();
    choose();
    printf("\nTries : %d", tries);
    while((tries != 0) && (win == 0)){
        char raw_input[3];
        printf("\nEnter the number:\t");
        scanf("%s", raw_input);

        if(isVerified(raw_input)){
            decide(raw_input, ranum, tries);
            tries -= 1;
        }else{
            printf("\nWrong input, try again");
        }
    }
    printf("\nThe number was %d", ranum);

    char inp;
    printf("\n\nDo you want to play again? (Y/N) : ");
    fflush(stdin);
    scanf("%c", &inp);

    if ((inp == 'Y') || (inp == 'y')){
        play();
    }else{
        printf("\nHave a good day :)");
    }
}

int main() {
    play();
    return 0;
}


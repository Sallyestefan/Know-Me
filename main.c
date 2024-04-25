#include <stdio.h>
#include <stdlib.h>
#include "gameFunctions.h" // Include the header file

int main(void) {
    char startOrEndGame;
    char userName[15];
    int totalPoints = 0;

    // Display welcome message and prompt to start or quit
    displayWelcomeMessage();
    scanf(" %c", &startOrEndGame);

    if (startOrEndGame != 'q' && startOrEndGame != 'Q' && startOrEndGame != 'S' && startOrEndGame != 's') {
        while (startOrEndGame != 'q' && startOrEndGame != 'Q' && startOrEndGame != 'S' && startOrEndGame != 's') {
            printf("Invalid entry, Try again: ");
            scanf(" %c", &startOrEndGame);
        }
    }

    if (startOrEndGame =='q' || startOrEndGame == 'Q') {
        exit(1);
    } else if (startOrEndGame == 's' || startOrEndGame == 'S') {
        printf("\t\tWELCOME!\n");
        printf("Please enter your first name: ");
        scanf("%s", userName);
        printf("\n\n");

        printf("\tLet the games begin %s!\n\n", userName);

        // Questions and answers
        const char *questions[] = {
            "What country was I born in?",
            "What is my favourite reality TV show?",
            "What is my favourite go-to drinks restaurant?",
            "When is my birthday?",
            "What is my favourite thing to do in my spare time?"
        };

        const char *options[][4] = {
            {"Iraq", "Canada", "Greece", "USA"},
            {"The Challenge", "Big Brother", "Too Hot To Handle", "Love is Blind"},
            {"Salute", "Winology", "Bourbon", "Ortona"},
            {"January 28, 1998", "January 27, 1997", "January 29, 1998", "January 28, 1997"},
            {"Shopping", "Relax", "Watch shows", "Code"}
        };

        const int answers[] = {2, 1, 2, 3, 4};

        // Loop through questions
        for (int i = 0; i < 5; i++) {
            displayQuestion(questions[i], options[i], 4);
            int userAnswer = submitAnswer();
            evaluateAnswer(userAnswer, answers[i], &totalPoints);
        }
    }
    
    printSummary(5, totalPoints);

    return 0;
}

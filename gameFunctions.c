#include <stdio.h>
#include "gameFunctions.h"

// Function to start or quit the game and display welcome message
void displayWelcomeMessage() {
    printf("\tHOW WELL DO YOU KNOW SALLY!\n\n");
    printf(">>press S to start game\n");
    printf(">>press Q to quit game\n");
}

//Function to display questions
void displayQuestion(const char *question, const char *options[], int numOptions) {
    printf("%s\n", question);
    for (int i = 0; i < numOptions; i++) {
        printf("%d) %s\n", i + 1, options[i]);
    }
    printf("Enter numbers 1-%d to submit answer: ", numOptions);
}

// Function to analyze and submit users answer to avoid errors
int submitAnswer() {
    int answer;
    while (1) {
        if (scanf("%d", &answer) != 1 || answer < 1 || answer > 4) {
            printf("Invalid input! Please enter a number from 1 to 4: ");
            // Clear the input buffer
            while (getchar() != '\n');
        } else {
            break; // Valid input received, exit the loop
        }
    }
    return answer;
}

// Function to evalute users
void evaluateAnswer(int userAnswer, int correctAnswer, int *totalPoints) {
    if (userAnswer == correctAnswer) {
        printf("You are correct!\n\n");
        (*totalPoints)++;
    } else {
        printf("You are wrong!\n\n");
    }
}

// Function to print summary with final results
void printSummary(int totalQuestions, int totalCorrect) {
    printf("\nResults:\n");
    printf("Total questions answered: %d\n", totalQuestions);
    printf("Total correct answers: %d\n", totalCorrect);
    printf("Total incorrect answers: %d\n", totalQuestions - totalCorrect);
    printf("Final score: %d/%d\n", totalCorrect, totalQuestions);
    
if (totalCorrect == totalQuestions) {
        printf("You know me very well!\n");
    } else if (totalCorrect == 4) {
        printf("You know me a good amount!\n");
    } else if (totalCorrect == 3) {
        printf("You know me a little.\n");
    } else if (totalCorrect == 2) {
        printf("You don't really know me that well.\n");
    } else {
        printf("You don't know me at all.\n");
    }
}
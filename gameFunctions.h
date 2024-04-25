#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H

// Function Prototypes
void displayWelcomeMessage();
void displayQuestion(const char *question, const char *options[], int numOptions);
int submitAnswer();
void evaluateAnswer(int userAnswer, int correctAnswer, int *totalPoints);
void printSummary(int totalQuestions, int totalCorrect);
#endif
#include <stdio.h>
#include <string.h>

#define MAX_TRIES 3

void display_word(char word[], char guessed_word[]) {
    printf("Word: ");
    for (int i = 0; i < strlen(word); i++) {
        if (guessed_word[i] == '_') {
            printf("_ ");
        } else {
            printf("%c ", guessed_word[i]);
        }
    }
    printf("\n");
}

int main() {
    char word[] = "programming";  // Word to be guessed
    int length = strlen(word);
    char guessed_word[length];

    // Initialize guessed_word with '_'
    for (int i = 0; i < length; i++) {
        guessed_word[i] = '_';
    }

    int tries = 0;
    int correct_guesses = 0;
    char guess;
    int is_correct;

    printf("Welcome to Hangman Game!\n");

    while (tries < MAX_TRIES && correct_guesses < length) {
        printf("\nAttempt %d of %d\n", tries + 1, MAX_TRIES);
        display_word(word, guessed_word);
        printf("Guess a letter: ");
        scanf(" %c", &guess);

        is_correct = 0;

        // Check if the guessed letter is in the word
        for (int i = 0; i < length; i++) {
            if (word[i] == guess && guessed_word[i] == '_') {
                guessed_word[i] = guess;  // Correct guess, update guessed_word
                correct_guesses++;
                is_correct = 1;
            }
        }

        if (is_correct) {
            printf("Good guess! '%c' is in the word.\n", guess);
        } else {
            printf("Wrong guess! '%c' is not in the word.\n", guess);
            tries++;
        }
    }

    if (correct_guesses == length) {
        printf("\nCongratulations! You have guessed the word correctly: ");
        display_word(word, guessed_word);
        printf("You won the game!\n");
    } else {
        printf("\nSorry! You have been hanged. The correct word was: %s\n", word);
    }

    return 0;
}

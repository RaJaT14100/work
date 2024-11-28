#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to determine the winner
void determine_winner(int user_choice, int computer_choice) {
    if (user_choice == computer_choice) {
        printf("It's a draw!\n");
    }
    else if ((user_choice == 0 && computer_choice == 1) || 
             (user_choice == 1 && computer_choice == 2) ||
             (user_choice == 2 && computer_choice == 0)) {
        printf("Computer wins!\n");
    }
    else {
        printf("You win!\n");
    }
}

int main() {
    int user_choice, computer_choice;
    
    // Initialize random number generator
    srand(time(0));

    // Display the game options
    printf("Rock, Paper, Scissors Game\n");
    printf("Enter your choice:\n");
    printf("0 for Rock\n");
    printf("1 for Paper\n");
    printf("2 for Scissors\n");
    printf("Your choice: ");
    scanf("%d", &user_choice);

    // Ensure user input is valid
    if (user_choice < 0 || user_choice > 2) {
        printf("Invalid choice! Please choose 0 for Rock, 1 for Paper, or 2 for Scissors.\n");
        return 1;  // Exit the program if the input is invalid
    }

    // Generate the computer's choice
    int random_choice = rand() % 100;

    if (random_choice >= 0 && random_choice <= 33) {
        computer_choice = 0;  // Rock
    } else if (random_choice >= 34 && random_choice <= 66) {
        computer_choice = 1;  // Paper
    } else {
        computer_choice = 2;  // Scissors
    }

    // Display the choices of both the user and the computer
    printf("You chose: ");
    if (user_choice == 0) printf("Rock\n");
    else if (user_choice == 1) printf("Paper\n");
    else printf("Scissors\n");

    printf("Computer chose: ");
    if (computer_choice == 0) printf("Rock\n");
    else if (computer_choice == 1) printf("Paper\n");
    else printf("Scissors\n");

    // Determine and display the winner
    determine_winner(user_choice, computer_choice);

    return 0;
}

#include <stdio.h>

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_player = 'X'; // Player 1 (user) starts
int choice;
int row, col;
int turn_count = 0;

void draw_board() {
    printf("\nTic Tac Toe Board:\n\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int check_win() {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    
    return 0;
}

int check_draw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0; // Not a draw yet
    return 1; // It's a draw if all spaces are filled
}

void player_move() {
    printf("Player %c, Enter your move (1-9): ", current_player);
    scanf("%d", &choice);
    
    row = (choice - 1) / 3;
    col = (choice - 1) % 3;
    
    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        printf("Invalid move! Try again.\n");
        player_move();
    } else {
        board[row][col] = current_player;
    }
}

void computer_move() {
    printf("Computer's turn (O):\n");
    
    // Simple AI for computer: make a random move (can be enhanced for better AI)
    int valid_move = 0;
    while (!valid_move) {
        choice = rand() % 9 + 1; // Random number between 1 and 9
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;
        
        if (board[row][col] != 'X' && board[row][col] != 'O') {
            valid_move = 1;
            board[row][col] = 'O';
        }
    }
}

int main() {
    srand(time(0)); // Seed for random number generation
    
    while (1) {
        draw_board();
        
        if (turn_count % 2 == 0) {
            // Player's turn (X)
            current_player = 'X';
            player_move();
        } else {
            // Computer's turn (O)
            current_player = 'O';
            computer_move();
        }
        
        turn_count++;
        
        // Check for win
        if (check_win()) {
            draw_board();
            printf("Player %c wins!\n", current_player);
            break;
        }
        
        // Check for draw
        if (check_draw()) {
            draw_board();
            printf("It's a draw!\n");
            break;
        }
    }
    
    return 0;
}

/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : Tom Kwok Kei
 * Student ID    : 1155172220
 * Class/Section : C
 * Date          : 03/11/2021
 */

#include <stdio.h>
/* NO other header files are allowed */

/* NO global variables are allowed */

/* Macros used to represent the state of each square */
#define EMPTY 0
#define CIRCLE 1
#define CROSS 2



/* Initialize the game board by setting all squares to EMPTY */
void initGameBoard(int gameBoard[6][7]) {

    // TODO : Complete this part
    int i = 0;
    int j = 0;
    for (i = 0; i < 6; i++){
        for (j = 0; j < 7; j++){
            gameBoard[i][j] = EMPTY;
        }
    }

}



/* Display the game board on the screen.
   You are required to exactly follow the output format stated in the project specification.
   IMPORTANT: Using other output format will result in mark deduction. */
void printGameBoard(int gameBoard[6][7]) {

    // TODO : Complete this part
    int i = 0;
    int j = 0;
    for (i = 0; i < 6; i++){
      printf("|");
      for (j = 0; j < 7; j++){
        if (gameBoard[i][j] == EMPTY)
            printf(" |");
        else if (gameBoard[i][j] == CIRCLE)
            printf("O|");
        else if (gameBoard[i][j] == CROSS)
            printf("X|");
      }
      printf("\n");
    }

}



/* Ask the human player to place the mark.
   You can assume that the user input must be an integer. */
void placeMarkByHumanPlayer(int gameBoard[6][7], int mark) {

    // TODO : Complete this part
    int p;
    scanf("%d", &p);
    int OutofBound = -1;

    if ( p < 1 || p > 7)
    {
     OutofBound = 1;
    }
    else if ( p > 0 && p < 8)
    {
     OutofBound = 0;
    }


    int row = 6;
    int level;
    for (level = row - 1; level >= 0; level--){
        if (OutofBound == 1){
            printf("Input out of range. Please input again:");
            scanf("%d", &p);
        }
        else if (OutofBound == 0){
            while (gameBoard[0][p-1] != EMPTY){
                printf("Column is full. Please input again: ");
                scanf("%d", &p);
            }

            if (gameBoard[level][p-1] == EMPTY){
                gameBoard[level][p-1] = mark;
                break;
            }
        }
    }

}



/* Return 1 if there is a winner in the game, otherwise return 0.
   Note: the winner is the current player indicated in main(). */
int hasWinner(int gameBoard[6][7]){

    // TODO : Complete this part


    int rows = 6;
    int cols = 7;
    int i, j;

    //horizontal
    for (i = 0; i < cols - 3; i++){
        for (j = 0; j < rows; j++){
            if (gameBoard[j][i] == CIRCLE && gameBoard[j][i+1] == CIRCLE && gameBoard[j][i+2] == CIRCLE && gameBoard[j][i+3] == CIRCLE){
                return 1;
            }

            if (gameBoard[j][i] == CROSS && gameBoard[j][i+1] == CROSS && gameBoard[j][i+2] == CROSS && gameBoard[j][i+3] == CROSS){
                return 1;
            }
        }
    }

    //vertical
    for (i = 0; i < cols; i++){
        for (j = 0; j < rows - 3; j++){
            if (gameBoard[j][i] == CIRCLE && gameBoard[j+1][i] == CIRCLE && gameBoard[j+2][i] == CIRCLE && gameBoard[j+3][i] == CIRCLE){
                return 1;
            }

            if (gameBoard[j][i] == CROSS && gameBoard[j+1][i] == CROSS && gameBoard[j+2][i] == CROSS && gameBoard[j+3][i] == CROSS){
                return 1;
            }
        }
    }

    //positive slope
    for (i = 0; i < cols - 3; i++){
        for (j = 3; j < rows; j++){
            if (gameBoard[j][i] == CIRCLE && gameBoard[j-1][i+1] == CIRCLE && gameBoard[j-2][i+2] == CIRCLE && gameBoard[j-3][i+3] == CIRCLE){
                return 1;
            }

            if (gameBoard[j][i] == CROSS && gameBoard[j-1][i+1] == CROSS && gameBoard[j-2][i+2] == CROSS && gameBoard[j-3][i+3] == CROSS){
                return 1;
            }
        }
    }


    //negative slope
    for (i = 0; i < cols - 3; i++){
        for (j = 0; j < rows - 3; j++){
            if (gameBoard[j][i] == CIRCLE && gameBoard[j+1][i+1] == CIRCLE && gameBoard[j+2][i+2] == CIRCLE && gameBoard[j+3][i+3] == CIRCLE){
                return 1;
            }

            if (gameBoard[j][i] == CROSS && gameBoard[j+1][i+1] == CROSS && gameBoard[j+2][i+2] == CROSS && gameBoard[j+3][i+3] == CROSS){
                return 1;
            }
        }
    }

    return 0;


}



/* Return 1 if the game board is full, otherwise return 0. */
int isFull(int gameBoard[6][7]) {

    // TODO : Complete this part
    int i = 0;
    int j = 0;
    for (i = 0; i < 6; i++){
      for (j = 0; j < 7; j++){
        if(gameBoard[i][j] == EMPTY)
            return 0;
      }
    }

    return 1;



}



/* Determine the next move of the computer player.
   You are required to exactly follow the strategy mentioned in the project specification.
   Using other strategies will result in mark deduction. */

// TODO : Write the placeMarkByComputerPlayer(...) function here
void placeMarkByComputerPlayer(int gameBoard[6][7], int mark) {
    int i;
    int j;
    int rows = 6;
    int cols = 7;
    //horizontal
    for (i = 0; i < cols - 3; i++){
        for (j = 0; j < rows; j++){
            if (gameBoard[j][i] == mark && gameBoard[j][i+1] == mark && gameBoard[j][i+2] == mark && gameBoard[j][i+3] == EMPTY){
                gameBoard[j][i+3] = mark;
                return;
            }
            else if (gameBoard[j][i] == mark && gameBoard[j][i+1] == mark && gameBoard[j][i+2] == EMPTY && gameBoard[j][i+3] == mark){
                gameBoard[j][i+2] = mark;
                return;
            }
            else if (gameBoard[j][i] == mark && gameBoard[j][i+1] == EMPTY && gameBoard[j][i+2] == mark && gameBoard[j][i+3] == mark){
                gameBoard[j][i+1] = mark;
                return;
            }
            else if (gameBoard[j][i] == EMPTY && gameBoard[j][i+1] == mark && gameBoard[j][i+2] == mark && gameBoard[j][i+3] == mark){
                gameBoard[j][i+1] = mark;
                return;
            }

            if (gameBoard[j][i] == CIRCLE && gameBoard[j][i+1] == CIRCLE && gameBoard[j][i+2] == CIRCLE && gameBoard[j][i+3] == EMPTY){
                gameBoard[j][i+3] = mark;
                return;
            }
            else if (gameBoard[j][i] == CIRCLE && gameBoard[j][i+1] == CIRCLE && gameBoard[j][i+2] == EMPTY && gameBoard[j][i+3] == CIRCLE){
                gameBoard[j][i+2] = mark;
                return;
            }
            else if (gameBoard[j][i] == CIRCLE && gameBoard[j][i+1] == EMPTY && gameBoard[j][i+2] == CIRCLE && gameBoard[j][i+3] == CIRCLE){
                gameBoard[j][i+1] = mark;
                return;
            }
            else if (gameBoard[j][i] == EMPTY && gameBoard[j][i+1] == CIRCLE && gameBoard[j][i+2] == CIRCLE && gameBoard[j][i+3] == CIRCLE){
                gameBoard[j][i] = mark;
                return;
            }
        }
    }

    //vertical
    for (i = 0; i < cols; i++){
        for (j = 0; j < rows - 3; j++){
            if (gameBoard[j][i] == mark && gameBoard[j+1][i] == mark && gameBoard[j+2][i] == mark && gameBoard[j+3][i] == EMPTY){
                gameBoard[j+3][i] = mark;
                return;
            }
            else if (gameBoard[j][i] == mark && gameBoard[j+1][i] == mark && gameBoard[j+2][i] == EMPTY && gameBoard[j+3][i] == mark){
                gameBoard[j+2][i] = mark;
                return;
            }
            else if (gameBoard[j][i] == mark && gameBoard[j+1][i] == EMPTY && gameBoard[j+2][i] == mark && gameBoard[j+3][i] == mark){
                gameBoard[j+1][i] = mark;
                return;
            }
            else if (gameBoard[j][i] == mark && gameBoard[j+1][i] == mark && gameBoard[j+2][i] == mark && gameBoard[j+3][i] == EMPTY){
                gameBoard[j][i] = mark;
                return;
            }

            if (gameBoard[j][i] == CIRCLE && gameBoard[j+1][i] == CIRCLE && gameBoard[j+2][i] == CIRCLE && gameBoard[j+3][i] == EMPTY){
                gameBoard[j+3][i] = mark;
                return;
            }
            else if (gameBoard[j][i] == CIRCLE && gameBoard[j+1][i] == CIRCLE && gameBoard[j+2][i] == EMPTY && gameBoard[j+3][i] == CIRCLE){
                gameBoard[j+2][i] = mark;
                return;
            }
            else if (gameBoard[j][i] == CIRCLE && gameBoard[j+1][i] == EMPTY && gameBoard[j+2][i] == CIRCLE && gameBoard[j+3][i] == CIRCLE){
                gameBoard[j+1][i] = mark;
                return;
            }
            else if (gameBoard[j][i] == EMPTY && gameBoard[j+1][i] == CIRCLE && gameBoard[j+2][i] == CIRCLE && gameBoard[j+3][i] == CIRCLE){
                gameBoard[j][i] = mark;
                return;
            }
        }
    }

    //positive slope
    for (i = 0; i < cols - 3; i++){
        for (j = 3; j < rows; j++){
            if (gameBoard[j][i] == mark && gameBoard[j-1][i+1] == mark && gameBoard[j-2][i+2] == mark && gameBoard[j-3][i+3] == EMPTY){
                gameBoard[j-3][i+3] = mark;
                return;
            }
            else if (gameBoard[j][i] == mark && gameBoard[j-1][i+1] == mark && gameBoard[j-2][i+2] == EMPTY && gameBoard[j-3][i+3] == mark){
                gameBoard[j-2][i+3] = mark;
                return;
            }
            else if (gameBoard[j][i] == mark && gameBoard[j-1][i+1] == EMPTY && gameBoard[j-2][i+2] == mark && gameBoard[j-3][i+3] == mark){
                gameBoard[j-1][i+3] = mark;
                return;
            }
            else if (gameBoard[j][i] == EMPTY && gameBoard[j-1][i+1] == mark && gameBoard[j-2][i+2] == mark && gameBoard[j-3][i+3] == mark){
                gameBoard[j][i+3] = mark;
                return;
            }

            if (gameBoard[j][i] == CIRCLE && gameBoard[j-1][i+1] == CIRCLE && gameBoard[j-2][i+2] == CIRCLE && gameBoard[j-3][i+3] == EMPTY){
                gameBoard[j-3][i+3] = mark;
                return;
            }
            else if (gameBoard[j][i] == CIRCLE && gameBoard[j-1][i+1] == CIRCLE && gameBoard[j-2][i+2] == EMPTY && gameBoard[j-3][i+3] == CIRCLE){
                gameBoard[j-2][i+3] = mark;
                return;
            }
            else if (gameBoard[j][i] == CIRCLE && gameBoard[j-1][i+1] == EMPTY && gameBoard[j-2][i+2] == CIRCLE && gameBoard[j-3][i+3] == CIRCLE){
                gameBoard[j-1][i+3] = mark;
                return;
            }
            else if (gameBoard[j][i] == EMPTY && gameBoard[j-1][i+1] == CIRCLE && gameBoard[j-2][i+2] == CIRCLE && gameBoard[j-3][i+3] == CIRCLE){
                gameBoard[j][i+3] = mark;
                return;
            }
        }
    }


    //negative slope
    for (i = 0; i < cols - 3; i++){
        for (j = 0; j < rows - 3; j++){
            if (gameBoard[j][i] == mark && gameBoard[j+1][i+1] == mark && gameBoard[j+2][i+2] == mark && gameBoard[j+3][i+3] == EMPTY){
                gameBoard[j+3][i+3] = mark;
                return;
            }
            else if (gameBoard[j][i] == mark && gameBoard[j+1][i+1] == mark && gameBoard[j+2][i+2] == EMPTY && gameBoard[j+3][i+3] == mark){
                gameBoard[j+2][i+2] = mark;
                return;
            }
            else if (gameBoard[j][i] == mark && gameBoard[j+1][i+1] == EMPTY && gameBoard[j+2][i+2] == mark && gameBoard[j+3][i+3] == mark){
                gameBoard[j+1][i+1] = mark;
                return;
            }
            else if (gameBoard[j][i] == EMPTY && gameBoard[j+1][i+1] == mark && gameBoard[j+2][i+2] == mark && gameBoard[j+3][i+3] == mark){
                gameBoard[j][i] = mark;
                return;
            }

            if (gameBoard[j][i] == CIRCLE && gameBoard[j+1][i+1] == CIRCLE && gameBoard[j+2][i+2] == CIRCLE && gameBoard[j+3][i+3] == EMPTY){
                gameBoard[j+3][i+3] = mark;
                return;
            }
            else if (gameBoard[j][i] == CIRCLE && gameBoard[j+1][i+1] == CIRCLE && gameBoard[j+2][i+2] == EMPTY && gameBoard[j+3][i+3] == CIRCLE){
                gameBoard[j+2][i+2] = mark;
                return;
            }
            else if (gameBoard[j][i] == CIRCLE && gameBoard[j+1][i+1] == EMPTY && gameBoard[j+2][i+2] == CIRCLE && gameBoard[j+3][i+3] == CIRCLE){
                gameBoard[j+1][i+1] = mark;
                return;
            }
            else if (gameBoard[j][i] == EMPTY && gameBoard[j+1][i+1] == CIRCLE && gameBoard[j+2][i+2] == CIRCLE && gameBoard[j+3][i+3] == CIRCLE){
                gameBoard[j][i] = mark;
                return;
            }
        }
    }

    for (i = 5; i > 0; i--){
      for (j = 6; j > 0; j--){
          if(gameBoard[i][j] == EMPTY){
              gameBoard[i][j] = mark;
              return;
        }
      }
    }

}


/* The main function */
int main()
{
    /* Local variables */
    int gameBoard[6][7];    // Each element stores 0 (EMPTY), 1 (CIRCLE), or 2 (CROSS)
    int currentPlayer;      // 1: Player 1             2: Player 2
    int gameContinue;       // 1: The game continues   0: The game ends
    int numOfHumanPlayers;  // 1 or 2

    /* Initialize the local variables */
    initGameBoard(gameBoard);
    currentPlayer = 1;
    gameContinue = 1;
    printf("Enter the number of human players [1-2]:\n");
    scanf("%d", &numOfHumanPlayers);    // You can assume that the user input must be valid



    /* Game start
       If there are two human players, they are Player 1 and Player 2
       If there is only one human player, he/she is Player 1 and another player is the computer player
       For both cases, Player 1 moves first and places the CIRCLE mark; while Player 2 (or the computer player) places the CROSS mark
       Hint: use a while loop */

    // TODO : Complete this part
    int turn;
    if (numOfHumanPlayers == 1){
        while (gameContinue == 1){
            turn = 0;
            isFull(gameBoard);
            if (turn % 2 == 0){
                printGameBoard(gameBoard);
                printf("Player 1's turn:\n");
                placeMarkByHumanPlayer(gameBoard, CIRCLE);
                if (hasWinner(gameBoard) == 1){
                    printGameBoard(gameBoard);
                    printf("Congratulations! Player 1 wins!");
                    break;
                }
                turn++;
            }

            if (turn % 2 == 1){
                printGameBoard(gameBoard);
                printf("Computer's turn:\n");
                placeMarkByComputerPlayer(gameBoard, CROSS);
                if (hasWinner(gameBoard) == 1){
                    printGameBoard(gameBoard);
                    printf("Computer wins!");
                    break;
                }
                turn++;
            }

            if (isFull(gameBoard) == 1){
                printGameBoard(gameBoard);
                printf("Draw game.");
                gameContinue = 0;
            }
        }
    }

    if (numOfHumanPlayers == 2){
        while (gameContinue == 1){
            turn = 0;
            isFull(gameBoard);
            if (turn % 2 == 0){
                printGameBoard(gameBoard);
                printf("Player 1's turn:\n");
                placeMarkByHumanPlayer(gameBoard, CIRCLE);
                if (hasWinner(gameBoard) == 1){
                    printGameBoard(gameBoard);
                    printf("Congratulations! Player 1 wins!");
                    break;
                }
                turn++;
            }

            if (turn % 2 == 1){
                printGameBoard(gameBoard);
                printf("Player 2's turn:\n");
                placeMarkByHumanPlayer(gameBoard, CROSS);
                if (hasWinner(gameBoard) == 1){
                    printGameBoard(gameBoard);
                    printf("Congratulations! Player 2 wins!");
                    break;
                }
                turn++;
            }

            if (isFull(gameBoard) == 1){
                printGameBoard(gameBoard);
                printf("Draw game.");
                gameContinue = 0;
            }
        }
    }

    return 0;
}

/* Uncomment the following statements to test whether the printGameBoard() and the placeMarkByHumanPlayer() functions
       are implemented correctly.
       You can add more if you wish.
       After testing, you can delete them or move them elsewhere. */
    //printGameBoard(gameBoard);
    //printf("Player 1's turn:\n");
    //placeMarkByHumanPlayer(gameBoard, CIRCLE);
    //printGameBoard(gameBoard);
    //printf("Player 2's turn:\n");
    //placeMarkByHumanPlayer(gameBoard, CROSS);
    //printGameBoard(gameBoard);

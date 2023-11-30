#include <stdio.h>
#include <stdlib.h>

void drawBoard(char square[]);
int checkWin(char square[]);
int isBoardFull(char square[]);

int main()
{
    char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int player = 1, choice, result;

    do
    {
        drawBoard(square);
        player = (player % 2) ? 1 : 2;
        printf("\t\t\t\t\tPlayer %d, enter a number: ", player);
        scanf("%d", &choice);

        char mark = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice)
        {
            square[choice] = mark;
            result = checkWin(square);

            if (result == 1)
            {
                drawBoard(square);
                printf("\t\t\t\t\t==>Player %d won!\n", player);
                break;
            }
            else if (result == 0)
            {
                drawBoard(square);
                printf("\t\t\t\t\t==>Game draw!\n");
                break;
            }
        }
        else
        {
            printf("Invalid option! Try again.\n");
            continue;
        }

        player++;
    } while (1);

    return 0;
}

int checkWin(char square[])
{
    int winPatterns[8][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 4, 7}, {2, 5, 8}, {3, 6, 9}, {1, 5, 9}, {3, 5, 7}};

    for (int i = 0; i < 8; i++)
    {
        int a = winPatterns[i][0];
        int b = winPatterns[i][1];
        int c = winPatterns[i][2];

        if (square[a] == square[b] && square[b] == square[c])
            return 1;
    }

    if (isBoardFull(square))
        return 0;

    return -1;
}

int isBoardFull(char square[])
{
    for (int i = 1; i <= 9; i++)
    {
        if (square[i] != 'X' && square[i] != 'O')
            return 0;
    }
    return 1;
}

void drawBoard(char square[])
{
    system("clear"); // Use "clear" for Unix-based systems, "cls" for Windows

    printf("\n\n\t\t\t\t\t-------Tic Tac Toe-------\n\n");
    printf("\t\t\t\t\tPlayer1 (X) - Player2 (O)\n\n\n");
    printf("\t\t\t\t\t ________ _______ _______\n\n");
    printf("\t\t\t\t\t|        |       |       |\n");
    printf("\t\t\t\t\t|   %c    |  %c    |   %c   |\n", square[1], square[2],
           square[3]);
    printf("\t\t\t\t\t|________|_______|_______|\n");
    printf("\t\t\t\t\t|        |       |       |\n");
    printf("\t\t\t\t\t|   %c    |  %c    |   %c   |\n", square[4], square[5],
           square[6]);
    printf("\t\t\t\t\t|________|_______|_______|\n");
    printf("\t\t\t\t\t|        |       |       |\n");
    printf("\t\t\t\t\t|   %c    |  %c    |   %c   |\n", square[7], square[8],
           square[9]);
    printf("\t\t\t\t\t|________|_______|_______|\n\n");
}

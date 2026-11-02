#include <stdio.h>
#include <stdbool.h>
//The mark is for vs code, has no other meaning.

//I discovered that the first one is strings vs the second one of a character list.
//char *table[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
char table[] = {"123456789"};

//Functions used in the program
void printBoard(void);
void xTurn(void);
void yTurn(void);
bool checkWin(void);

//MARK: Main Method
int main(void)
{
    int turns = 0;
        printBoard();
        //runs the game loop until a player wins, stops loop via break statements. 
        while (!checkWin())
        {
            turns++;

            xTurn();

            if (turns == 9)
            {
                printf("It's a tie!");
                break;
            }

            if (checkWin())
            {
                printf("Player X Wins!");
                break;
            }

            turns++;

            yTurn();

            if (turns == 9)
            {
                printf("It's a tie!");
                break;
            }

            if (checkWin())
            {
                printf("Player Y Wins!");
                break;
            }
        }

    return 0;
}
    //MARK: Print Board Method
    void printBoard(void)
    {
        printf("\n");
        for (int i = 0; i < 9; i++)
       {
            //prints the board via running through the array and putting a new line every 3 characters.
            printf("%c ", table[i]);
            if(i != 0 && (i+1) % 3 == 0)
            {
                printf("\n");
            }
       }
       printf("");
    }

    //MARK: XTurn
    void xTurn(void)
    {
        //ticker tracks if the player has picked a valid spot.
        int ticker1 = 0;
        while (ticker1 == 0)
        {
            //Takes player input on which position they want to take
            printf("\nPlayer X:\nWhich Spot do you want: ");
            int num1;
            scanf("%d", &num1);
            char targetChar = num1 + '0';
            
            for (int i = 0; i< 9; i++)
            {
                if (table[i] == targetChar)
                {
                    //Chances the number in the array to an x if the spot is open
                    table[i] = 'X';
                    ticker1 = 1;
                    break;
                }
                else
                {
                    ticker1 = 0;
                }
            }
            if(ticker1 == 0)
            {
                printf("The spot you have not picked is not avaliable, pick again");
            }
        }
        printBoard();
    }   


    //MARK: YTurn
    //exact same as the xturn method, just with a y instead.
    void yTurn(void)
    {
        int ticker2 = 0;
        while (ticker2 == 0)
        {
            int num2;
            printf("\nPlayer Y:\nWhich Spot do you want: ");
            scanf("%d", &num2);
            char targetChar = num2 + '0';
            
            
            
            for (int i = 0; i<9; i++)
            {
                if (table[i] == targetChar)
                {
                    table[i] = 'Y';
                    ticker2 = 1;
                    break;
                }
                else
                {
                    ticker2 = 0;
                }
            }
            if(ticker2 == 0)
            {
                printf("The spot you have not picked is not avaliable, pick again");
            }
        }  
        printBoard();
    }


    //MARK: Check Win
    //Looks at the array position to see if the board has a win, and tells main to end the game if there is a win. 
    bool checkWin(void)
    {
        if (table[0] == table[3] && table[3] == table[6])
        {
            return true;
        }
        else if (table[1] == table[4] && table[4] == table[7])
        {
            return true;
        }
        else if (table[2] == table[5] && table[5] == table[8])
        {
            return true;
        }
        else if (table[0] == table[1] && table[1] == table[2])
        {
            return true;
        }
        else if (table[3] == table[4] && table[4] == table[5])
        {
            return true;
        }
        else if (table[6] == table[7] && table[7] == table[8])
        {
            return true;
        }
        else if (table[0] == table[4] && table[4] == table[8])
        {
            return true;
        }
        else if (table[2] == table[4] && table[4] == table[6])
        {
            return true;
        }
        else
        {
            return false;
        }
    }




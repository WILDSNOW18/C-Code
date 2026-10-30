#include <stdio.h>


public void Main()
{
    public char[] table = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
   
        printBoard();
        while (!checkWin())
        {
            xTurn();
            if (checkWin())
            {
                printf("Player X Wins!");
                break;
            }
            yTurn();
            if (checkWin())
            {
                printf("Player Y Wins!");
                break;
            }
        }

    
}

    void printBoard()
    {
        printf();
        for (int i = 0; i < 9; i++)
       {
            System.out.print(table[i] + " ");
            if(i != 0 && (i+1) % 3 ==0)
            {
                System.out.print("\n");
            }
       }
       printf("");
    }

    void xTurn()
    {
        int ticker = 0;
        while (ticker == 0)
        {
            printf("Player X:\nWhich Spot do you want: ");
            int num1;
            scanf("%d", &num1)
            char targetChar = num1 + '0';
            
            for (int i = 0; i< 9; i++)
            {
                if (table[i] == targetChar)
                {
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

    void yTurn()
    {
        int ticker2 = 0;
        while (ticker2 == 0)
        {
            int num2;
            scanf("%d", &num2)
            char targetChar = num2 + '0';
            printf("Player Y:\nWhich Spot do you want: ");
            
            
            for (int i = 0; i<9; i++)
            {
                if (table[i] == targetChar)
                {
                    table[i] = 'Y';
                    ticker = 1;
                    break;
                }
                else
                {
                    ticker2 = 0;
                }
            }
            if(ticke2r == 0)
            {
                printf("The spot you have not picked is not avaliable, pick again");
            }
        }  
        printBoard();
    }

    boolean checkWin()
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
}



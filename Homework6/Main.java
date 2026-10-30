import java.util.Scanner;
public class Main {
    public static char[] table = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    public static Scanner input = new Scanner(System.in);

    public static void main(String[] args)
    {
        printBoard();
        while (!checkWin())
        {
            xTurn();
            if (checkWin())
            {
                System.out.println("Player X Wins!");
                break;
            }
            yTurn();
            if (checkWin())
            {
                System.out.println("Player Y Wins!");
                break;
            }
        }

    

       input.close();
    }

    public static void printBoard()
    {
        System.out.println();
        for (int i = 0; i < table.length; i++)
       {
            System.out.print(table[i] + " ");
            if(i != 0 && (i+1) % 3 ==0)
            {
                System.out.print("\n");
            }
       }
       System.out.println("");
    }

    public static void xTurn()
    {
        int ticker = 0;
        while (ticker == 0)
        {
            System.out.println("Player X:\nWhich Spot do you want: ");
            int num = input.nextInt();
            char targetChar = Character.forDigit(num, 10);
            
            for (int i = 0; i< table.length; i++)
            {
                if (table[i] == targetChar)
                {
                    table[i] = 'X';
                    ticker = 1;
                    break;
                }
                else
                {
                    ticker = 0;
                }
            }
            if(ticker == 0)
            {
                System.out.println("The spot you have not picked is not avaliable, pick again");
            }
        }
        printBoard();
    }   
    
    public static void yTurn()
    {
          int ticker = 0;
        while (ticker == 0)
        {
            System.out.println("Player Y:\nWhich Spot do you want: ");
            int num = input.nextInt();
             char targetChar = Character.forDigit(num, 10);
            
            for (int i = 0; i<table.length; i++)
            {
                if (table[i] == targetChar)
                {
                    table[i] = 'Y';
                    ticker = 1;
                    break;
                }
                else
                {
                    ticker = 0;
                }
            }
            if(ticker == 0)
            {
                System.out.println("The spot you have not picked is not avaliable, pick again");
            }
        }  
        printBoard();
    }

    public static boolean checkWin()
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

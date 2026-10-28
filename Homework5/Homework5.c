#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int shuffle(char *cards[]);
dealCards(char *cards[], int numPlayers, int numCards);


int main()
{
    srand((unsigned int)time(NULL));
    // Card array and integers used
    char *cards[] = {"Ace of Hearts", "2 of Hearts", "3 of Hearts", "4 of Hearts", "5 of Hearts", "6 of Hearts", "7 of Hearts", "8 of Hearts", "9 of Hearts", "10 of Hearts", "Jack of Hearts", "Queen of Hearts", "King of Hearts",
                     "Ace of Diamonds", "2 of Diamonds", "3 of Diamonds", "4 of Diamonds", "5 of Diamonds", "6 of Diamonds", "7 of Diamonds", "8 of Diamonds", "9 of Diamonds", "10 of Diamonds", "Jack of Diamonds", "Queen of Diamonds", "King of Diamonds",
                     "Ace of Clubs", "2 of Clubs", "3 of Clubs", "4 of Clubs", "5 of Clubs", "6 of Clubs", "7 of Clubs", "8 of Clubs", "9 of Clubs", "10 of Clubs", "Jack of Clubs", "Queen of Clubs", "King of Clubs",
                     "Ace of Spades", "2 of Spades", "3 of Spades", "4 of Spades", "5 of Spades", "6 of Spades", "7 of Spades", "8 of Spades", "9 of Spades", "10 of Spades", "Jack of Spades","Queen of Spades","King of Spades"};
    int numPlayers, numCards;

    //asks how many players and how many cards
    printf("How many players today? ");
    scanf("%d", &numPlayers);
    printf("How many cards will each player have? ");
    scanf("%d", &numCards);

    //shuffles, then deals the cards
    shuffle(cards);
    printf("\n\n\n");
    dealCards(cards, numPlayers, numCards);
}

//shuffles the cards
int shuffle(char *cards[])
{
    //Variables
    int randIndex;
    char *temp[52];
    int i, j, k;

    //This sets the array to be all 0's
    memset(temp, 0, sizeof(temp));
    
    //generates a random number for each cards, checks of the spot is open, then places the card there
    for (j = 0; j < 52; j++)
    {
        randIndex = rand() % 52;
        if (temp[randIndex] == 0)
        {
            //printf("test: %2d\n", randIndex);
            temp[randIndex] = cards[j];
        }
        else
        {
            j--;
        }    
    
    }
       
    //sets the original array to the shuffled array
    for (i = 0; i < 52; i++)
    {
        cards[i] = temp[i];
        printf("%s\n", cards[i]);
    }
    
    return 0;
}

//deals the cards
int dealCards (char *cards[], int numPlayers, int numCards)
{
    //If the number of players * the number of cards per player is greater than the deck size, this returns an error.
    if(numPlayers * numCards > 52)
    {
        printf("Not enough cards for all players!\n");
        return -1;
    }

    //deals the cards in order to the players
    for (int i = 0; i < numPlayers; i++)
    {
        printf("Player %d's cards:\n", i + 1);
        for (int j = 0; j < numCards; j++)
        {
            printf("%s\n", cards[i * numCards + j]);
        }
        printf("\n");
    }
    return 0;

}
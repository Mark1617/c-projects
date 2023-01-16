// Takes two words as inputs and calculates the score of each words based on the scrabble points system, then prints a winner message.

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    printf("%i\n", score1);
    printf("%i\n", score2);

    // Print scores
    if (score1 < score2)
    {
        printf("Player 2 wins with %i points!\n", score2);
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins with %i points!\n", score1);
    }
    else
    {
            printf("It's a tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;

    // Loop over each character in string
    for (int i = 0; i < strlen(word); i++ )
    {
        // Make all letters uppercase and initialize ASCII values from 0 - 25
        int character = toupper(word[i]) - 65;

        // Make sure character is a letter
        if (character >= 0 && character < 26)
        {
            int letterscore = POINTS[character];
            // Add letter score to total score for word
            score += letterscore;
        }
    }
    return score;
}


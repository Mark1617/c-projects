#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{

    // Make sure key is correct length and used correctly
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must be 26 characters\n");
        return 1;
    }
    else
    {

        // Check the key for duplicate values with brute force
        for (int i = 0; i < 25; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    printf("Your key has duplicate values.\n");
                    return 1;
                }
            }
        }

        // Start casing check for key for efficiency
        int cases[26] = {};
        for (int i = 0; i < 26; i++ )
        {
            if (argv[1][i] >= 65 && argv[1][i] <= 90)
            {
                cases[i] = 2;
            }
            else if (argv[1][i] >= 97 && argv[1][i] <= 122)
            {
                cases[i] = 1;
            }
            else
            {
                // If key contains non-alphebetic characters exit
                printf("Key contains invalid characters\n");
                return 1;
            }
        }

        string pltext = get_string("plaintext: ");
        printf("ciphertext: ");

        // Loop over each character in string
        for (int i = 0; i < strlen(pltext); i++ )
        {
            // Initialize ASCII values from 0 - 25 for lowercase and uppercase letters only
            int upper = pltext[i] - 65;
            int lower = pltext[i] - 97;

            // If char is uppercase letter
            if (upper >= 0 && upper <= 25)
            {

                // Print associated key char with same casing as input char
                if (cases[upper] == 1)
                {
                    printf("%c", argv[1][upper] - 32);
                }
                else
                {
                    printf("%c", argv[1][upper]);
                }
            }

            else if (lower >= 0 && lower <= 25)
            {

                if (cases[lower] == 2)
                {
                    printf("%c", argv[1][lower] + 32);
                }
                else
                {
                    printf("%c", argv[1][lower]);
                }
            }

            // If not a letter, just return the symbol
            else
            {
                printf("%c", pltext[i]);
            }
        }
        printf("\n");
        return 0;
    }
}


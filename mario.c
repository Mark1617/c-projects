// Program to create the pyramid from mario with a user defined height

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for the height of the stack
    int height = get_int("Height: ");
    while (height < 1 || 8 < height)
    {
        printf("Please input a number between 1 and 8 inclusive.\n");
        height = get_int("Height: ");
    }
    // Initialize the middle gap and the counter
    string middle = "#  #";
    int counter = 1;
    // Begin the stack build
    while (counter < height + 1)
    {
        // Uphill Side
        for (int x = 0; x < height - counter; x++)
        {
            printf(" ");
        }
        for (int x = 1; x < counter; x++)
        {
            printf("#");
        }
        // Print Middle
        printf("%s", middle);
        // Downhill Side
        for (int x = 1; x < counter; x++)
        {
            printf("#");
        }
        printf("\n");
        counter += 1;
    }
}

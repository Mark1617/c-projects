#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long int number = get_long("Enter your card number?: ");
    long int remainder = 0;
    int i = 0;
    int digits = 0;
    int first = 0;
    int second = 0;

    // Loop through the card number, dividing by 10 each time

    while (number > 0)
    {
        remainder = number % 10;
        // Grab every other digit from the first and add to digits

        if (i % 2 == 0)
        {
            digits += remainder;
            second = remainder;
        }

        // Multiply the others and add the resulting digits

        else
        {
            int twos = remainder * 2;
            first = remainder;
            while (twos > 0)
            {
                digits += twos % 10;
                twos = twos / 10;
            }
        }

        // Increment counter and reduce number by factor
        number = number / 10;
        i++;
    }

    // Check the digits to give validity answer

    if (digits % 10 == 0)
    {

    // Check the card length and type

        // Check for AMEX length and characters
        if (i == 15 && second == 3)
        {
            // First and second will switch because AMEX has odd card length number
            if ((first == 4) || (first == 7))
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // Check for MASTERCARD length and characters
        else if (i == 16 && first == 5)
        {
            if (second <= 5)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }

        // Check for VISA length and characters
        else if ((i == 13) || (i == 16))
        {
            if (first == 4 && i == 16)
            {
                printf("VISA\n");
            }
            else if (second == 4 && i == 13)
            {
                printf("VISA\n");
            }
        }

        else
        {
            printf("INVALID\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}



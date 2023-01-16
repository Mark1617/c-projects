#include <cs50.h>
#include <stdio.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Need one or more values typecast as float so we don't just get 0
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Round the float using a math module, don't want truncation
    int grade = round(index);

    // State the reading level if it is between 1-16
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    // Cycles through string counting all alphebetic ranges until a null value is returned
    int i = 0;
    int lettercount = 0;
    for (i = 0; text[i] != 0; i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            lettercount += 1;
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            lettercount += 1;
        }
    }

    return lettercount;
}

int count_words(string text)
{
    int i = 0;
    // Start at one because starting word won't have space before.
    int wordcount = 1;
    for (i = 0; text[i] != 0; i++)
    {
        if (text[i] == 32)
        {
            wordcount += 1;
        }
    }
    return wordcount;
}

int count_sentences(string text)
{
    // Count the number of sentence-ending characters eg. . ? !
    int i = 0;
    int sentencecount = 0;
    for (i = 0; text[i] != 0; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentencecount += 1;
        }
    }

    return sentencecount;
}

// This program is about to do readability test based on
// Coleman-Liau index. Which calculated by:
// index = 0.0588 * L - 0.296 * S - 15.8
// where L is the average number of letters per 100 words
// in the text, and S is the average number of sentences
// per 100 words in the text.


#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int len_text = strlen(text);
    int num_letter = 0;

    // The final word should count
    int num_word = 1;
    int num_sentence = 0;

    for (int i = 0; i < len_text; i++)
    {
        // Count letters
        if (((text[i] <= 'z') & (text[i] >= 'a')) | ((text[i] <= 'Z') & (text[i] >= 'A')))
        {
            num_letter++;
        }

        // Count sentences
        if ((text[i] == '.') | (text[i] == '!') | (text[i] == '?'))
        {
            num_sentence++;
        }

        // Count words
        if (text[i] == ' ')
        {
            num_word++;
        }
    }

    // Coleman-Liau index.
    float L = 0;
    float S = 0;
    int index = 0;
    L = 100 * (float)num_letter / (float)num_word;
    S = 100 * (float)num_sentence / (float)num_word;
    index = round(0.0588 * L - 0.296 * S - 15.8);


    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

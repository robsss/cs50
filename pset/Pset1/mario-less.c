#include <cs50.h>
#include <stdio.h>

void draw_space(int number);
void draw_brick(int number);

int main(void)
{
    // Prompt user input hieght of pyramid
    int height;
    do
    {
        height = get_int("Height(Between 1 and 8): ");
    }
    while ((height < 1) || (height > 8));

    // Draw
    for (int i = 0; i < height; i++)
    {

        draw_space(height - i - 1);
        draw_brick(i + 1);
        printf("\n");
    }
}

// Draw some amount of spaces
void draw_space(int number)
{
    for (int i = 0; i < number; i++)
    {
        printf(" ");
    }
}
// Draw some amount of hashes
void draw_brick(int number)
{
    for (int i = 0; i < number; i++)
    {
        printf("#");
    }
}
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get the user name
    string name = get_string("What's your name ? ");
    // Welcome
    printf("hello %s!\n", name);
}
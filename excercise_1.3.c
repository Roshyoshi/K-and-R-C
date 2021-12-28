#include <stdio.h>
#define IN 1
#define OUT 0

int c;

int main(void)
{
    int x = IN;
    while ((c = getchar()) != EOF)
    {
        if (x == IN)
        {
            if (c == ' ' || c == '\t')
            {
                x = OUT;
                putchar('\n');
            }
            else
            {
                putchar(c);
            }
            if (c=='\n'){
                putchar('\b');
            }
        }
        else
        {
            if (c == ' ' || c == '\t')
            {
                ;
            }
            else
            {
                putchar(c);
                x = IN;
            }
            if (c=='\n'){
                putchar('\b');
            }
        }
    }
}
#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
    int c, wl;
    int wlen[15];
    for (int x = 0; x < 15; ++x)
    {
        wlen[x] = 0;
    }
    int x = OUT;
    while ((c = getchar()) != EOF)
    {
        if (x == IN)
        {
            if (c >= 'a' && c <= 'z')
            {
                ++wl;
            }
            else if (c >= 'A' && c <= 'Z')
            {
                ++wl;
            }
            else
            {
                ++wlen[wl];
                wl = 0;
            }
        }
        else
        {
            if (c >= 'a' && c <= 'z')
            {
                ++wl;
                x = IN;
            }
            else if (c >= 'A' && c <= 'Z')
            {
                ++wl;
                x = IN;
            }
            else
            {
                ;
            }
        }
    }
    printf("\n Lengths of Words\n\n");
    for (int x = 1; x < 15; ++x)
    {
        printf(" %2d ", x);
        for (int y = 0; y < wlen[x]; ++y)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("    123456789~\n\n");
}

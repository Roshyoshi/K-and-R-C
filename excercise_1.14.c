#include <stdio.h>

int main(void)
{
    int c, k;
    int ch[27];
    for (int x = 0; x < 27; ++x)
    {
        ch[x] = 0;
    }
    while ((c = getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            k = c - 96;
            ++ch[k];
        }
        else
        {
            ;
        }
    }
  printf("\n       Character frequency\n\n");
    for (int x = 122; x > 96; --x)
    {
        printf(" %c ", x);
        k=x-96;
        printf(" %2d ", ch[k]);
        for (int y = 0; y < ch[k]; ++y)
        {
            printf("|");
        }
        printf("\n");
    }
    printf("\n");
}

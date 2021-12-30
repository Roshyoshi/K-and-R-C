#include <stdio.h>

int celsius(int f);
int main(void)
{
    int fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    for (fahr = lower; fahr <= upper; fahr = fahr + step)
    {
        printf("%d\t%d\n", fahr, celsius(fahr));
    }
}

int celsius(int f)
{
    int c = 5 * (f - 32) / 9;
    return c;
}

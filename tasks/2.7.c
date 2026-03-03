#include <stdio.h>

void print_binary(unsigned int n)
{
    printf("0b ");

    int i;
    for (i = 31; i >= 0; i--)
    {
        putchar( (n >> i) & 1 ? '1' : '0' );

        if (i % 8 == 0 && i != 0)
            putchar(' ');
    }
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned mask = ((1u << n) - 1) << p;
    return x ^ mask;
}

int main(void)
{
    unsigned x = 12;
    printf("Later: ");
    print_binary(x);
    printf("\nNow: ");
    print_binary(invert(x, 2, 5));

    return 0;
}
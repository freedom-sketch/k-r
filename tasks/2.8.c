#include <stdio.h>

void print_binary(unsigned int n)
{
    int i;
    for (i = 31; i >= 0; i--)
    {
        putchar( (n >> i) & 1 ? '1' : '0' );

        if (i % 8 == 0 && i != 0)
            putchar(' ');
    }
}

unsigned rightrot(unsigned x, int n)
{
    return (x >> n) | (x << (sizeof(unsigned) * 8 - n));
}

int main(void)
{
    printf("R:");
    print_binary(rightrot(15, 3));

    return 0;
}
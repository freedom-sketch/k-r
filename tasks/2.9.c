#include <stdio.h>

int bitcount(unsigned x)
{
    /* Подсчитывает единицы в двоичной записи x */
    for (int b = 0; x != 0; x &= (x-1)) {
        if (x & 01)
            b++;
    }
}

int main(void)
{
    unsigned i = 15;
    printf("i: %b\n", i);
    printf("in i: %d\n", bitcount(i));
}
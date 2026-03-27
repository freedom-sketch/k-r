#include <stdio.h>
#include <string.h>

void itob(int n, char *s, int b)
{
    int sign = n;

    int i = 0;
    do {
        int rem = n % b;
        if (rem < 0) rem = -rem;

        if (b > 10) {
            if (rem > 9) s[i++] = rem - 10 + 'A';
            else s[i++] = '0' + rem;
        } else {
            s[i++] = '0' + rem;
        }

        n /= b;
    } while (n != 0);

    if (sign < 0) s[i++] = '-';
    s[i] = '\0';

    int j = i - 1;
    i = 0;
    while (i < j) {
        char temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
}

int main(void)
{
    int n = 2426;
    char buffer[50];

    itob(n, buffer, 16);
    printf("%s\n", buffer);
}
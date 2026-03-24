#include <stdio.h>
#include <string.h>

void reverse(char *s, int start) {
    int i = start, j = strlen(s) - 1;
    while (i < j) {
        char temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
}

void itoa(int n, char *s)
{
    int i = 0;
    int sign = n;

    do {
        int digit = n % 10;
        s[i++] = '0' + ((digit < 0) ? -digit : digit);
    } while ((n /= 10 ) != 0);

    if (sign < 0) {
        s[i++] = '-';
        s[i] = '\0';
        reverse(s, 1);
    } else {
        s[i] = '\0';
        reverse(s, 0);
    }
}

int main(void)
{
    int n = 2856;
    char s[20];

    itoa(n, s);

    printf("%s\n", s);
}
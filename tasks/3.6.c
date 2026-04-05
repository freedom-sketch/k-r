#include <string.h>
#include <stdio.h>

void itoa(int n, char *s, int min_w)
{
    int i = 0;
    int sign = n;

    do {
        int digit = n % 10;
        s[i++] = '0' + ((digit < 0) ? -digit : digit);
    } while ((n /= 10 ) != 0);

    if (sign < 0) {
        s[i++] = '-';
        while (i < min_w) s[i++] = ' ';
        s[i] = '\0';
        i = 1;
        int j = strlen(s) - 1;
        while (i < j) {
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
    } else {
        while (i < min_w) s[i++] = ' ';
        s[i] = '\0';
        i = 0;
        int j = strlen(s) - 1;
        while (i < j) {
            char temp = s[i];
            s[i++] = s[j];
            s[j--] = temp;
        }
    }
}

int main()
{
    int n = 123456;
    char buffer[10];
    itoa(n, buffer, 9);
    printf("%s", buffer);
}
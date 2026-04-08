#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

int main()
{
    double sum, atof(char []);
    char line[MAXLINE];
    int _getline(char line[], int max);

    sum = 0;
    while (_getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));
    return 0;
}

/* atof: преобразование строки s в число типа double */
double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i=0; isspace(s[i]); i++) /* пропуск пробелов */

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.') i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    return sign * val / power;
}
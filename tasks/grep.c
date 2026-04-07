#include <stdio.h>
#define MAXLINE 1000 /* Максимальная длина входной строки */

int _getline(char line[], int max);
int strindex(char source[], char searchfor[]);
//char pattern[] = "ould"; /* Образец для поиска */

/* Поиск всех строк, содержащих заданный образец */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found;

    while (_getline(line, MAXLINE) > 0) {
        if (strindex(line, argv[1]) >= 0) {
            printf("%s", line);
            found++;
        }
    }
    return found;
}

/* getline: считывает строку в s, возвращает ее длину */
int _getline(char s[], int lim)
{
    int c, i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: возвращает индекс строки t в s, -1 при отсутствии */
int strindex(char s[], char t[])
{
    for (int i = 0; s[i] != '\0'; i++) {
        int j, k;
        for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++) ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

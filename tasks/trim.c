#include <string.h>
#include <stdio.h>

/* trim: удаляет символы пустого пространства из конца строки */
int trim(char *s)
{
    int n;
    for (n = strlen(s)-1; n >= 0; n--) {
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    }
    s[n+1] = '\0';
    return n;
}

int main()
{
    char test_str[] = "test string->             ";
    trim(test_str);
    printf("%s|", test_str);
}
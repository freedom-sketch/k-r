#include <stdio.h>

void expand(const char *s1, char *s2)
{
    unsigned i = 0, j = 0;
    while (s1[i] != '\0') {
        if (i > 0 && s1[i] == '-' && s1[i+1] > s1[i-1]) {
            char c = s1[i-1] + 1;
            while (c <= s1[i+1]) {
                s2[j++] = c++;
            }
            i += 2;
        } else {
            s2[j++] = s1[i++];
        }
}
    s2[j] = '\0';
}

int main(void)
{
    char *s1 = "a-z0-9";
    char s2[50];

    expand(s1, s2);

    printf("%s", s2);
    return 0;
}
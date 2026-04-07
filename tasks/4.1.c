int strindex(char *s, char *t)
{
    int res = -1;
    for (int i=0; s[i] != '\0';) {
        int k, j;
        for (j=i, k=0; t[k] != '\0' && s[j]==t[k]; k++, j++);
        if (k > 0 && t[k]=='\0') {
            res = i;
            i += k;
        }
        i++;
    }

    return res;
}
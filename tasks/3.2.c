void escape(char *s, const char *t)
{
    int i = 0, j = 0;
    for (;t[j] != '\0';) {
        switch (t[j])
        {
            case '\n':
                s[i++] = '\\';
                s[i++] = 'n';
                j++;
                break;
            case '\t':
                s[i++] = '\\';
                s[i++] = 't';
                j++;
                break;
            default:
                s[i++] = t[j++];
        }
    }
    s[i] = '\0';
}

void unescape(char *s, const char *t)
{
    int i = 0, j = 0;
    for (;t[j] != '\0';) {
        switch (t[j])
        {
            case '\\':
                j++;
                if (t[j] == 'n') {
                    s[i++] = '\n';
                } else if (t[j] == 't') {
                    s[i++] = '\t';
                } else {
                    s[i++] = '\\';
                    s[i++] = t[j];
                }
                j++;
                break;
            default:
                s[i++] = t[j++];
                break;
        }
    }
    s[i] = '\0';
}
#include <math.h>
#include <ctype.h>
#include <stdio.h>

/* atof: преобразование строки s в число типа double */
double atof(char s[])
{
    double val, power;
    int i, sign, exp_sign = 1, exp = 0;

    for (i=0; isspace(s[i]); i++) ; /* пропуск пробелов */

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') i++;

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if (s[i] == '.') {
        i++;
        for (power = 1.0; isdigit(s[i]); i++) {
            val = 10.0 * val + (s[i] - '0');
            power *= 10.0;
        }
    } else {
        power = 1.0;
    }

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-') i++;
        
        for (exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
    }

    val = sign * val / power;
    
    if (exp > 0)
        val *= pow(10.0, exp_sign * exp);
    
    return val;
}

int main(void)
{
    char f_str[] = "123.45e-6";
    printf("%g\n", atof(f_str));
}
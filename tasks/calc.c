#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP 100 /* максимальный размер операнда и знака */
#define NUMBER '0' /* сигнал, что обнаружено число */
#define SIN '1' /* сигнал, что обнаружена функция sin */
#define EXP '2' /* сигнал, что обнаружена функция exp */
#define POW '3' /* сигнал, что обнаружена функция pow */

int getop(char s[]);
void push(double);
double pop(void);

/* Калькулятор с обратной польской записью */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case SIN:
            push(sin(pop()));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case POW:
            push(pow(pop(), pop()));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case '~':
            push(-pop());
            break;
        case '\n':
            printf("answear: %.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

#define MAXVAL 100 /* максимальная глубина стека val */

int sp = 0; /* следующая свободная позиция в стеке */
double val[MAXVAL]; /* стек операндов */

/* помещает число f в стек операндов */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: извлекает и возвращает верхнее число из стека */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getnum: возвращает верхнее число из стека */
double getnum(void)
{
    if (sp > 0)
        return val[sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* copynum: создает в стеке дубликат последнего элемента */
void copynum(void)
{
    if (sp < MAXVAL)
        val[sp++] = val[sp];
    else
        printf("error: stack full, can't copy %g\n", val[sp]);
}

/* swap: меняет местами в стеке 2 последних числа */
double swap(void)
{
    if (sp > 0) {
        double tmp = val[sp];
        val[sp] = val[sp-1];
        val[sp-1] = tmp;
    }
    else {
        printf("error: stack empty\n");
    }
}

void clear_stack(void)
{
    sp = 0;
}

int getch(void);
void ungetch(int);

/* getop: извлекает следующий операнд или знак операции */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        switch (c) {
            case 's':
                getch();
                getch();
                return SIN;
            case 'e':
                getch();
                getch();
                return EXP;
            case 'p':
                getch();
                getch();
                return POW;
            default: return c;
        }
    i = 0;
    if (isdigit(c)) /* накопление целой части */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* накопление дробной части */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* буфер для ungetch */
int bufp = 0; /* следующая свободная позиция в buf */

int getch(void) /* ввод символа (возможно, возвращенного в поток) */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* возвращение символа в поток ввода */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

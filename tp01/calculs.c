#include <stdio.h>

void printres(long long res)
{
    printf("Résultat : %lld\n", res);
}

int main()
{
    char usr_inp[100];
    long long num1 = 0;
    long long num2 = 0;

    char op;

    printf("Veuillez entrer une opération:\n");
    fgets(usr_inp, sizeof(usr_inp), stdin);

    int usr_inp_val = sscanf(usr_inp, "%lld %c %lld", &num1, &op, &num2);

    if (usr_inp_val != 3)
    {
        printf("Le format attendu n'est pas respecté, ou une erreur est survenue.\n");
        return 1;
    }

    switch (op)
    {
    case '+':
    {
        long long res = num1 + num2;
        printres(res);
        break;
    }
    case '-':
    {
        long long res = num1 - num2;
        printres(res);
        break;
    }
    case '*':
    {
        long long res = num1 * num2;
        printres(res);
        break;
    }
    case '/':
    {
        if (num2 == 0)
        {
            printf("Impossible de diviser par 0\n");
            return 1;
        }
        double res = (double)num1 / num2;
        printf("Résultat : %f\n", res);
        break;
    }
    case '%':
    {
        if (num2 == 0)
        {
            printf("Impossible de diviser par 0\n");
            return 1;
        }
        long long res = num1 % num2;
        printres(res);
        break;
    }
    case '&':
    {
        long long res = num1 & num2;
        printres(res);
        break;
    }
    case '|':
    {
        long long res = num1 | num2;
        printres(res);
        break;
    }
    case '~':
    {
        long long res = ~num2;
        printres(res);
        break;
    }
    default:
        printf("Opérateur inconnu.\n");
        return 1;
    }

    return 0;
}
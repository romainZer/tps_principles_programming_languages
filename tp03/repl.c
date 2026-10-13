#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ARGS 12

afficher_aide()
{
    printf("Commandes :\n");
    printf("    echo [args]:    Affiche en console le texte saisi.\n");
    printf("    version :       Affiche la version de la console.\n");
    printf("    quit :          Quitte la console.\n");
}

void traiter_inconnu()
{
    printf("Unknown command.\n");
}

void afficher_version()
{
    printf("1.0.0\n");
}

void traiter_echo(char *argv[])
{
    for (int i = 1; argv[i] != NULL; i++)
    {
        printf("%s", argv[i]);
        if (argv[i + 1] != NULL)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void taiter_command(char *command, char *argv[])
{
    if (strcmp(command, "echo") == 0)
    {
        traiter_echo(argv);
    }
    else if (strcmp(command, "quit") == 0)
    {
        printf("Bye!\n");
        exit(0);
    }
    else if (strcmp(command, "version") == 0)
    {
        afficher_version();
    }
    else if (strcmp(command, "help") == 0)
    {
        afficher_aide();
    }
    else
    {
        traiter_inconnu();
    }
}

int main()
{
    char inpstr[256];
    char command[64];
    printf("**Type CTRL + D to exit the console**\n");

    while (true)
    {
        printf("> ");
        fflush(stdout);

        if (fgets(inpstr, sizeof inpstr, stdin) == NULL)
        {
            break;
        }

        char *argv[MAX_ARGS];
        int argc = 0;

        if (sscanf(inpstr, "%63s", command) == 1)
        {
            char *token = strtok(inpstr, " \t\n");
            while (token != NULL && argc < MAX_ARGS - 1)
            {
                argv[argc++] = token;
                token = strtok(NULL, " \t\n");
            }
            argv[argc] = NULL;

            taiter_command(command, argv);
        }
    }
    return 0;
}
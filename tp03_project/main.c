#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "evaluation.h"
#include "lexer.h"
#include "parseur.h"

#define MAX_ARGS 12
#define MAX_ALIASES 12
#define INPUT_SIZE 256

typedef void (*CommandCallback)(char **argv);

/**
 * Defines the structure of an interpreter command
 */
typedef struct {
    char command[64];
    const char *aliases[MAX_ALIASES];
    char args[MAX_ARGS];
    char doc_description[256];
    CommandCallback on_execute;
} Commande;

void afficher_aide(char *argv[]);

void afficher_version(char *argv[]);

void traiter_echo(char *argv[]);

void traiter_quit(char *argv[]);

void traiter_inconnu(const char *command);

void traiter_commande(const char *command, char *argv[]);

void traiter_math(const char *command, char *argv[]);

Commande commandes[] = {
    {
        .command = "echo",
        .aliases = {},
        .args = "",
        .doc_description = "[args]: Affiche le texte saisi.",
        .on_execute = traiter_echo
    },
    {
        .command = "version",
        .aliases = {},
        .args = "",
        .doc_description = ": Affiche la version de la console.",
        .on_execute = afficher_version
    },
    {
        .command = "help",
        .aliases = {"aide"},
        .args = "",
        .doc_description = ": Affiche la liste des commandes.",
        .on_execute = afficher_aide
    },
    {
        .command = "quit",
        .aliases = {"exit", "quitter"},
        .args = "",
        .doc_description = ": Quitte la console.",
        .on_execute = traiter_quit
    }
};

#define NB_COMMANDES (sizeof(commandes) / sizeof(commandes[0]))

/**
 * Displays the available commands
 */
void afficher_aide(char *argv[]) {
    (void) argv;

    printf("Commandes disponibles :\n");

    for (size_t i = 0; i < NB_COMMANDES; i++) {
        printf("    %s", commandes[i].command);

        if (commandes[i].aliases[0] != NULL) {
            printf(" (ou ");
            for (size_t j = 0; j < MAX_ALIASES && commandes[i].aliases[j] != NULL; j++) {
                printf("%s%s", j > 0 ? ", " : "", commandes[i].aliases[j]);
            }
            printf(")");
        }

        printf(" %s\n", commandes[i].doc_description);
    }
}

/**
 * Displays the current version of the app
 */
void afficher_version(char *argv[]) {
    (void) argv;
    printf("1.0.0\n");
}

/**
 * Executes the echo command.
 */
void traiter_echo(char *argv[]) {
    for (size_t i = 1; argv[i] != NULL; i++) {
        printf("%s", argv[i]);

        if (argv[i + 1] != NULL) {
            printf(" ");
        }
    }

    printf("\n");
}

/**
 * Exits the current program
 */
void traiter_quit(char *argv[]) {
    (void) argv;
    printf("Bye!\n");
    exit(EXIT_SUCCESS);
}

/**
 * Manages unknown commands
 */
void traiter_inconnu(const char *command) {
    printf("Commande inconnue : %s\n", command);
}

/**
 * Generic function that treats the command via the mapping table.
 * Falls into "traiter_inconnu" if unknown
 */
void traiter_commande(const char *command, char *argv[]) {
    for (size_t i = 0; i < NB_COMMANDES; i++) {
        bool match = strcmp(commandes[i].command, command) == 0;

        for (size_t j = 0; !match && j < MAX_ALIASES && commandes[i].aliases[j] != NULL; j++) {
            match = strcmp(commandes[i].aliases[j], command) == 0;
        }

        if (match) {
            commandes[i].on_execute(argv);
            return;
        }
    }

    traiter_inconnu(command);
}

/**
 * Normalizes a string by transforming it in lowercases
 * @param s - String to lower
 */
void en_minuscules(char *s) {
    for (; *s; s++) {
        *s = (char) tolower((unsigned char) *s);
    }
}

void traiter_operation(const char *usr_inp) {
    TokenPile *pile = tokenize(usr_inp);
    if (!pile) {
        return;
    }

    ParsedItems *items = parse(pile);
    if (!items) {
        free_token_pile(pile);
        return;
    }

    printf("%.1f\n", evaluate(items));

    free_token_pile(pile);
    free_all_parsed_inp(items);
}

int main() {
    char inp_str[INPUT_SIZE];

    printf("**Type CTRL + D to exit the console**\n");

    while (true) {
        printf("> ");
        fflush(stdout);

        if (fgets(inp_str, sizeof inp_str, stdin) == NULL) {
            break;
        }

        // If entry is math input
        if (isdigit((unsigned char) inp_str[0])) {
            traiter_operation(inp_str);
            continue;
        }

        char *argv[MAX_ARGS];
        size_t argc = 0;

        char *token = strtok(inp_str, " \t\n");

        while (token != NULL && argc < MAX_ARGS - 1) {
            argv[argc++] = token;
            token = strtok(nullptr, " \t\n");
        }

        argv[argc] = nullptr;

        if (argc > 0) {
            en_minuscules(argv[0]);
            traiter_commande(argv[0], argv);
        }
    }

    return EXIT_SUCCESS;
}

//
// Created by romainz on 04/11/2026.
//
#include "lexer.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Adds a token to the pile
 */
static void addToken(Token *token, TokenPile *list) {
    if (list->size == 0) {
        list->head = token;
        list->size++;
    } else {
        token->nextptr = list->head;
        list->head = token;
        list->size++;
    }
}

/**
 * Checks validity of the token (checks if the characters are valid numbers or math operation)
 */
static bool checkValidity(const TokenPile *pile) {
    if (pile->size == 0) return false;

    constexpr char authorized_ops[] = {'%', '/', '-', '*'};
    constexpr size_t authorized_ops_size = sizeof(authorized_ops);

    const Token *cur = pile->head;

    if (cur->nextptr == NULL) {
        for (size_t i = 0; i < authorized_ops_size; ++i) {
            if (cur->value == authorized_ops[i]) return true;
        }
        return isdigit((unsigned char)cur->value);
    }

    while (cur->nextptr != NULL) {
        for (size_t j = 0; j < authorized_ops_size; ++j) {
            if (cur->value == authorized_ops[j]) return false;
        }
        cur = cur->nextptr;
    }

    return true;
}

void free_all(TokenPile *list) {
    if (list->size == 0) {
        return;
    }

    while (list->size > 0) {
        Token *tmp = list->head->nextptr;
        free(list->head);
        list->head = tmp;
        list->size--;
    }
    free(list);
}

TokenPile *tokenize(const char *math_inp) {
    TokenPile *pile = malloc(sizeof(*pile));
    if (pile == NULL) {
        return nullptr;
    }

    pile->head = nullptr;
    pile->size = 0;

    const size_t input_size = strlen(math_inp);
    for (size_t i = 0; i < input_size; i++) {
        Token *token = malloc(sizeof *token);
        if (token == NULL) {
            free_all(pile);
        }

        token->value = math_inp[i];
        token->nextptr = nullptr;

        checkValidity(pile);
        addToken(token, pile);
    }

    return pile;
}

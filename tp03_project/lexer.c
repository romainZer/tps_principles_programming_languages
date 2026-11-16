//
// Created by romainz on 04/11/2026.
//
#include "lexer.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

static constexpr char authorized_ops[] = {'+', '/', '-', '*'};
static constexpr size_t authorized_ops_size = sizeof(authorized_ops);

static bool isOperator(const char c) {
    for (size_t i = 0; i < authorized_ops_size; ++i) {
        if (c == authorized_ops[i]) return true;
    }
    return false;
}

/**
 * Adds a token to the pile
 */
static void addToken(Token *token, TokenPile *list) {
    if (list->size == 0) {
        list->head = token;
        list->size++;
    } else {
        token->next_ptr = list->head;
        list->head = token;
        list->size++;
    }
}

/**
 * Checks validity of the last added token (pile->head):
 * an operator must follow a number, and two numbers cannot follow each other.
 */
static bool checkValidity(const TokenPile *pile) {
    if (pile->size == 0) return false;

    const Token *cur = pile->head;

    if (cur->type == TOKEN_OPERATOR) {
        // Operator at the start of the expression (it is the oldest token)
        if (cur->next_ptr == NULL) return false;
        // Two operators in a row
        if (cur->next_ptr->type == TOKEN_OPERATOR) return false;
        return true;
    }

    // Two numbers in a row ("1 2")
    if (cur->next_ptr != NULL && cur->next_ptr->type == TOKEN_NUMBER) return false;

    return true;
}

void free_token_pile(TokenPile *list) {
    if (list == NULL) {
        return;
    }

    while (list->size > 0) {
        Token *tmp = list->head->next_ptr;
        free(list->head);
        list->head = tmp;
        list->size--;
    }
    free(list);
}

TokenPile *tokenize(const char *math_inp) {
    if (math_inp == NULL) {
        return nullptr;
    }

    TokenPile *pile = malloc(sizeof(*pile));
    if (pile == NULL) {
        return nullptr;
    }

    pile->head = nullptr;
    pile->size = 0;

    const size_t input_size = strlen(math_inp);
    for (size_t inp = 0; inp < input_size; inp++) {
        if (isspace((unsigned char)math_inp[inp])) {
            continue;
        }

        Token *token = malloc(sizeof *token);
        if (token == NULL) {
            printf("[ERROR] - Memory allocation failed at position %zu.\n", inp);
            free_token_pile(pile);
            return nullptr;
        }

        token->value = 0.0;
        token->op = '\0';
        token->next_ptr = nullptr;

        if (isdigit((unsigned char)math_inp[inp]) || math_inp[inp] == '.') {
            const size_t start = inp;
            size_t digits = 0;
            size_t dots = 0;

            while (inp < input_size && (isdigit((unsigned char)math_inp[inp]) || math_inp[inp] == '.')) {
                if (math_inp[inp] == '.') {
                    dots++;
                } else {
                    digits++;
                }
                inp++;
            }

            if (digits == 0 || dots > 1) {
                printf("[ERROR] - Malformed number at position %zu.\n", start);
                free(token);
                free_token_pile(pile);
                return nullptr;
            }

            token->type = TOKEN_NUMBER;
            token->value = strtod(&math_inp[start], nullptr);
            inp--;
        } else if (isOperator(math_inp[inp])) {
            token->type = TOKEN_OPERATOR;
            token->op = math_inp[inp];
        } else {
            printf("[ERROR] - Illegal char '%c' at position %zu.\n", math_inp[inp], inp);
            free(token);
            free_token_pile(pile);
            return nullptr;
        }

        addToken(token, pile);

        if (!checkValidity(pile)) {
            printf("[ERROR] - Misplaced token at position %zu.\n", inp);
            free_token_pile(pile);
            return nullptr;
        }
    }

    if (pile->size == 0 || pile->head->type == TOKEN_OPERATOR) {
        printf("[ERROR] - Incomplete expression.\n");
        free_token_pile(pile);
        return nullptr;
    }

    return pile;
}

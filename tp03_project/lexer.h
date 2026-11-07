//
// Created by romainz on 04/11/2026.
//

#ifndef TP03_PROJECT_LEXER_H
#define TP03_PROJECT_LEXER_H
#include <stddef.h>

typedef struct Token {
    char value;
    struct Token *nextptr;
} Token;

typedef struct
{
    Token *head;
    size_t size;
} TokenPile;

/**
 * Tokenises a mathematical expression.
 * @param math_inp math expression input
 * @returns a list of tokens that represents the expression elements
 */
TokenPile *tokenize(const char *math_inp);

/**
 * Free all tokens in memory
 */
void free_all(TokenPile *list);

#endif //TP03_PROJECT_LEXER_H

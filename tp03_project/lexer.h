//
// Created by romainz on 04/11/2026.
//

#ifndef TP03_PROJECT_LEXER_H
#define TP03_PROJECT_LEXER_H
#include <stddef.h>

typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR
} TokenType;

typedef struct Token {
    TokenType type;

    union {
        char op;
        double value;
    };

    struct Token *next_ptr;
} Token;

typedef struct {
    Token *head;
    size_t size;
} TokenPile;

/**
 * Tokenizes a mathematical expression.
 * @param math_inp math expression input
 * @returns a list of tokens that represents the expression elements
 */
TokenPile *tokenize(const char *math_inp);

/**
 * Free all tokens in memory
 */
void free_token_pile(TokenPile *list);

#endif //TP03_PROJECT_LEXER_H

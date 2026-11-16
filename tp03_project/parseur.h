//
// Created by romainz on 16/11/2026.
//

#ifndef TP03_PROJECT_PARSER_H
#define TP03_PROJECT_PARSER_H
#include "lexer.h"

/**
 * Structured operation for the format <op1> <operation> <op2>.
 */
typedef struct {
    char operation;
    double operand1;
    double operand2;
} ParsedItems;

/**
 * Parses the tokens and creates a structured representation of the formula
 * @param pile Tokenized input
 * @return A structured representation of the tokenized formula
 */
ParsedItems *parse(const TokenPile *pile);

/**
 * Takes parsed items references and frees them
 * @param parsed_items All parsed items
 */
void free_all_parsed_inp(ParsedItems *parsed_items);

#endif //TP03_PROJECT_PARSER_H

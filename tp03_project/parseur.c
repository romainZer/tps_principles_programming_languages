//
// Created by romainz on 16/11/2026.
//

#include "lexer.h"
#include "parseur.h"

#include <assert.h>
#include <stdlib.h>

ParsedItems *parse(const TokenPile *pile) {
    ParsedItems *parsedInp = malloc(sizeof(ParsedItems));
    assert(parsedInp != NULL);

    const Token *cur = pile->head;
    parsedInp->operand1 = cur->value;
    cur = cur->next_ptr;
    parsedInp->operation = cur->op;
    cur = cur->next_ptr;
    parsedInp->operand2 = cur->value;
    return parsedInp;
}

void free_all_parsed_inp(ParsedItems *parsed_items) {
    free(parsed_items);
};

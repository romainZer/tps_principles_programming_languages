//
// Created by romainz on 16/11/2026.
//

#include "evaluation.h"

#include <assert.h>
#include <stdio.h>

double evaluate(const ParsedItems *p) {
    assert(p != NULL);

    //Division by 0
    if (p->operand2 == 0) {
        printf("[ERROR] - Fatal ! Division by zero\n");
        return -1;
    }

    switch (p->operation) {
        case '+':
            return p->operand1 + p->operand2;
        case '-':
            return p->operand1 - p->operand2;
        case '*':
            return p->operand1 * p->operand2;
        case '/':
            return p->operand1 / p->operand2;
        default: {
            printf("[ERROR] - Fatal ! Invalid operation\n");
            return -1;
        }
    }
}

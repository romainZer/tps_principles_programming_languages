//
// Created by romainz on 16/11/2026.
//

#ifndef TP03_PROJECT_EVALUATION_H
#define TP03_PROJECT_EVALUATION_H
#include "parseur.h"

/**
 * Evaluates if an operation is mathematically valid
 * Eliminates the division by 0
 * @param p Structured mathematical operation items
 */
double evaluate(const ParsedItems *p);

#endif //TP03_PROJECT_EVALUATION_H

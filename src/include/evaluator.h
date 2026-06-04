#ifndef EVALUATOR_H
#define EVALUATOR_H


#include "ast.h"
#include "parser.h"

double eval(ASTNode *node);

//Helper for eval
double evaluate_expression(const char *expr);

#endif

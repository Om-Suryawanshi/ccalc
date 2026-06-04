#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "ast.h"

typedef struct
{
	Lexer lexer;
	Token current;
}Parser;

void parser_init(Parser *parser, const char *source);

ASTNode *parser_expression(Parser *parser);

ASTNode *parse(Parser *parser);

#endif

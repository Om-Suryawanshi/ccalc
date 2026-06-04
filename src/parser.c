#include <stdio.h>
#include <stdlib.h>

#include "parser.h"

ASTNode *parse_expression(Parser *p);

static void advance(Parser *p)
{
	p->current = lexer_next_token(&p->lexer);
}

static void parser_error(const char *msg)
{
	fprintf(stderr, "Parse error: %s\n", msg);
	exit(EXIT_FAILURE);
}

static void expect(Parser *p, TokenType type)
{
	if(p->current.type != type)
		parser_error("Unexpected token!");

	advance(p);
}

void parser_init(Parser *p, const char *source)
{
	lexer_init(&p->lexer, source);
	advance(p);
}

static ASTNode *parse_factor(Parser *p)
{

	if(p->current.type == TOKEN_MINUS)
	{
		advance(p);

		return ast_unary(TOKEN_MINUS, parse_factor(p));
	}

	if (p->current.type == TOKEN_NUMBER)
	{
		double value = p->current.value;
		advance(p);
		return ast_number(value);
	}

	if(p->current.type == TOKEN_LPAREN)
	{
		advance(p);
		ASTNode *expr = parse_expression(p);
		expect(p, TOKEN_RPAREN);
		return expr;
	}

	parser_error("Expected number or '('");

	return NULL;
}

static ASTNode *parse_power(Parser *p)
{
	ASTNode *left = parse_factor(p);

	if(p->current.type == TOKEN_POW)
	{
		advance(p);

		ASTNode* right = parse_power(p);

		return ast_binary(TOKEN_POW, left, right);
	}

	return left;
}

static ASTNode *parse_term(Parser *p)
{
	ASTNode *left = parse_power(p);

	while(p->current.type == TOKEN_MUL || p->current.type == TOKEN_DIV)
	{
		TokenType op = p->current.type;

		advance(p);

		ASTNode *right = parse_power(p);

		left = ast_binary(op, left, right);
	}

	return left;
}

ASTNode *parse_expression(Parser *p)
{
	ASTNode *left = parse_term(p);

	while(p->current.type == TOKEN_PLUS || p->current.type == TOKEN_MINUS)
	{
		TokenType op = p->current.type;
		advance(p);
		ASTNode *right = parse_term(p);
		left = ast_binary(op, left, right);
	}
	return left;
}

ASTNode *parse(Parser *p)
{
	ASTNode *root = parse_expression(p);

	if(p->current.type != TOKEN_EOF)
		parser_error("Unexprected token after expression");

	return root;
}



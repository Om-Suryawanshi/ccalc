#include <ctype.h>
#include <stdlib.h>

#include "lexer.h"

static char current(Lexer *l)
{
	return l->src[l->pos];
}

static void advance(Lexer *l)
{
	l->pos++;
}

void lexer_init(Lexer *l, const char *src)
{
	l->src = src;
	l->pos = 0;
}

Token lexer_next_token(Lexer *l)
{
	while(isspace(current(l)))
		advance(l);
	
	char c = current(l);

	if (c == '\0')
		return (Token){TOKEN_EOF, 0};


	if (isdigit(c) || c == '.')
	{
		char *end;

		double value = strtod(&l->src[l->pos], &end);

		l->pos += (end - &l->src[l->pos]);

		return (Token){TOKEN_NUMBER, value};
	}

	advance(l);

	switch (c)
	{
		case '+':
			return (Token){TOKEN_PLUS, 0};
		case '-':
			return (Token){TOKEN_MINUS, 0};
		case '*':
			return (Token){TOKEN_MUL, 0};
		case '/':
			return (Token){TOKEN_DIV, 0};
		case '^':
			return (Token){TOKEN_POW, 0};
		case '(':
			return (Token){TOKEN_LPAREN, 0};
		case ')':
			return (Token){TOKEN_RPAREN, 0};
	}

	return (Token){TOKEN_EOF, 0};
}

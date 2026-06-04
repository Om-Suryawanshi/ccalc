#ifndef TOKEN_H
#define TOKEN_H

typedef enum
{
	TOKEN_NUMBER,

	TOKEN_PLUS,
	TOKEN_MINUS,

	TOKEN_DIV,
	TOKEN_MUL,

	TOKEN_POW,

	TOKEN_LPAREN,
	TOKEN_RPAREN,

	TOKEN_EOF
} TokenType;

typedef struct
{
	TokenType type;
	double value;
}Token;

#endif

#ifndef AST_H
#define AST_H

#include "token.h"

typedef enum
{
	AST_NUMBER,
	AST_BINARY,
	AST_UNARY
} ASTType;

typedef struct ASTNode ASTNode;

struct ASTNode
{
	ASTType type;

	union
	{
		double number;

		struct
		{
			ASTNode *left;
			ASTNode *right;
			TokenType op;
		} binary;

		struct
		{
			TokenType op;
			ASTNode *operand;
		} unary;
	};
};

ASTNode *ast_number(double value);

ASTNode *ast_binary(TokenType op, ASTNode *left, ASTNode *right);

ASTNode *ast_unary(TokenType op, ASTNode *operand);

void ast_print(ASTNode *node, int depth);

void ast_free(ASTNode *node);

#endif

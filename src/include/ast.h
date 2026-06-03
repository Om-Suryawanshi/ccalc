#ifndef AST_H
#define AST_H

#include "token.h"

typedef enum
{
	AST_NUMBER,
	AST_BINARY
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
	};
};

ASTNode *ast_number(double value);

ASTNode *ast_binary(TokenType op, ASTNode *left, ASTNode *right);

void ast_print(ASTNode *node, int depth);

void ast_free(ASTNode *node);

#endif

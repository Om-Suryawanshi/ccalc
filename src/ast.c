#include <stdlib.h>
#include <stdio.h>

#include "ast.h"

ASTNode *ast_number(double value)
{
	ASTNode *node = malloc(sizeof(ASTNode));

	node->type = AST_NUMBER;
	node->number = value;

	return node;
}

ASTNode *ast_binary(TokenType op, ASTNode* left, ASTNode *right)
{
	ASTNode *node = malloc(sizeof(ASTNode));

	node->type = AST_BINARY;

	node->binary.op = op;
	node->binary.left = left;
	node->binary.right = right;

	return node;
}

static void indent(int depth)
{
	while(depth--)
		printf("	");
}

void ast_print(ASTNode* node, int depth)
{
	if (!node)
		return;

	indent(depth);

	switch(node->type)
	{
		case AST_NUMBER:
			printf("%g\n", node->number);
			break;

		case AST_UNARY:
			printf("NEG\n");
			ast_print(node->unary.operand, depth + 1);
			break;

		case AST_BINARY:
			switch(node->binary.op)
			{
				case TOKEN_PLUS:
					printf("+\n");
					break;
				case TOKEN_MINUS:
					printf("-\n");
					break;
				case TOKEN_MUL:
					printf("*\n");
					break;
				case TOKEN_DIV:
					printf("/\n");
					break;

				default:
					printf("?\n");
			}

				
		ast_print(node->binary.left, depth + 1);
		ast_print(node->binary.right, depth + 1);

		break;
	}
}

void ast_free(ASTNode *node)
{
	if(!node)
		return;

	if (node->type == AST_BINARY)
	{
		ast_free(node->binary.left);
		ast_free(node->binary.right);
	}

	free(node);
}

ASTNode *ast_unary(TokenType op, ASTNode *operand)
{
	ASTNode *node = malloc(sizeof(ASTNode));
	node->type = AST_UNARY;
	node->unary.op = op;
	node->unary.operand = operand;

	return node;
}

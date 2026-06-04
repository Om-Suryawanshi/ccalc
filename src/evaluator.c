#include <stdio.h>
#include <stdlib.h>

#include "evaluator.h"

double eval(ASTNode *node)
{
	switch(node->type)
	{
		case AST_NUMBER:
			return node->number;

		case AST_BINARY:
		{
			double left = eval(node->binary.left);
			double right = eval(node->binary.right);

			switch(node->binary.op)
			{
				case TOKEN_PLUS:
					return left + right;
				case TOKEN_MINUS:
					return left - right;
				case TOKEN_MUL:
					return left * right;
				case TOKEN_DIV:
					if(right == 0)
					{
						fprintf(stderr, "Division by zero \n");
						exit(EXIT_FAILURE);
					}
					return left / right;

				default:
					fprintf(stderr, "Unknown operator\n");
					exit(EXIT_FAILURE);
			}
		}

		default:
			fprintf(stderr, "Unknown AST node\n");
			exit(EXIT_FAILURE);
				
	}
}

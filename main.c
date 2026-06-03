#include <stdio.h>
#include "ast.h"

int main(int argc, char* argv[])
{
	ASTNode* tree = ast_binary(TOKEN_PLUS, ast_number(3), ast_binary(TOKEN_MUL, ast_number(4), ast_number(2)));

	ast_print(tree, 0);
	//ast_free(tree);
	return 0;
}

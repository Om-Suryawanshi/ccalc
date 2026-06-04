#include <stdio.h>
#include "parser.h"

int main(int argc, char* argv[])
{
	Parser parser;

	parser_init(&parser, "(3 + 4) * 2");

	ASTNode *root = parse(&parser);

	ast_print(root, 0);

	ast_free(root);

	return 0;
}

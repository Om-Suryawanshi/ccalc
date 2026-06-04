#include <stdio.h>
#include "parser.h"
#include "evaluator.h"

int main(int argc, char* argv[])
{
	Parser parser;

	parser_init(&parser, "(3 + 4) * 2");

	ASTNode *root = parse(&parser);

	printf("%g\n", eval(root));


	ast_free(root);

	return 0;
}

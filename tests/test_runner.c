#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "evaluator.h"

int main()
{
	FILE *f = fopen("../tests/test.txt", "r");
	if (!f)
	{
		fprintf(stderr, "Error: Could not open test/test.txt \n");
		return 1;
	}

	char line[256];
	int passed = 0;
	int total = 0;

	while(fgets(line, sizeof(line), f))
	{
		if (line[0] == '\n' || line[0] == '#') continue;

		char *equals_sign = strchr(line, '=');
		if (!equals_sign) continue;

		*equals_sign = '\0';
		char *expr_str = line;
		char *expected_str = equals_sign + 1;

		double expected = atof(expected_str);

		Parser parser;
		parser_init(&parser, expr_str);
		ASTNode *root = parse(&parser);
		double result = eval(root);
		ast_free(root);

		total++;
		if(result == expected)
		{
			printf("[PASS] %s == %g \n", expr_str, expected);
			passed++;
		}
		else
		{
			printf("[FAIL] %s \n", expr_str);
			printf("	Expected: %g, Got: %g \n", expected, result);
		}
	}

	fclose(f);

	if (passed == total)
	{
		printf("SUCCESS : %d/%d tests passed. \n", passed, total);
		return 0;
	}
	else
	{
		printf("FAILURE : %d/%d test passed. \n", passed, total);
		return 1;
	}
}

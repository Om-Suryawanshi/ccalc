#include <stdio.h>
#include "lexer.h"

int main(int argc, char* argv[])
{
	Lexer lexer;

	lexer_init(&lexer, "3+4*2");

	Token t;

	do
	{
		t = lexer_next_token(&lexer);

		printf("type = %d, value = %f \n", t.type, t.value);
	}while (t.type != TOKEN_EOF);

	return 0;
}

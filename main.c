#include <stdio.h>
#include "evaluator.h"
#include "repl.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if(argc == 2)
	{
		printf("%g\n", evaluate_expression(argv[1]));
		return 0;
	}
	else if(argc > 2)
	{
		printf("Please wrap your expression in quotes (ex calc \"2 + 3\"). \n");
		return 1;
	}

	repl();

	return 0;
}

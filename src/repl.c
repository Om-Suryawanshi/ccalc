#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "evaluator.h"

void repl(void)
{
	char line[1024];

	while(1)
	{
		printf("calc> ");

		if(!fgets(line, sizeof(line), stdin))
			break;

		size_t len = strlen(line);

		if(len && line[len - 1] == '\n')
		{
			line[len - 1] = '\0';
		}

		if(strcmp(line, "exit") == 0)
			break;

		if(strcmp(line, "quit") == 0)
			break;

		if(line[0] == '\0')
			continue;

		printf("%g \n", evaluate_expression(line));
	}
}

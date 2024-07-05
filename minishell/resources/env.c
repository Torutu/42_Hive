#include <stdio.h>
#include <stdlib.h>

int main(int ac, char** av)
{
	char* env_variable = getenv("ENV_TEST");
	if(env_variable == NULL)
	{
		printf("No environment variable was found");
		return 1;
	}
	printf("the env_variable is = %s\n",env_variable);
	return 0;
}

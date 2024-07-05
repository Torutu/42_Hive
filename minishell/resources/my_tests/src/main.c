#include "../minishell.h"
#include "../inc/libft/libft.h"

#include <stdio.h>
#include <string.h>

int main(int ac, char **av, char **envp) {
    // Print the command-line arguments
    printf("Command-line arguments:\n");
    int i = 0;
    while (i < ac) {
        printf("av[%d]: %s\n", i, av[i]);
        i++;
    }
    printf("\n");

    // Print the USER environment variable
    printf("USER environment variable:\n");
    char **env = envp;
    while (*env != 0) {
        if (ft_strncmp(*env, "USER=", 5) == 0) {
			*env += 5;
            printf("%s\n", *env);
            break;
        }
        env++;
    }

    return 0;
}


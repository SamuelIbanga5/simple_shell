#include "shell.h"

/**
 * c_exit - frees user's typed command and linked list before exiting
 * @str: user's typed command
 * @env: input the linked list of envirnment
 */
void c_exit(char **str, list_t *env)
{
	free_double_ptr(str);
	free_linked_list(env);
	_exit(0);
}

/**
 * _execve - execute command user typed into shell
 * @s: command user typed
 * @env: environmental variable
 * @num: nth user command; to be used in error message
 * Return: 0 on success
 */
int _execve(char **s, list_t *env, int num)
{
	char *holder;
	int status = 0, t = 0;
	pid_t pid;

	/* check if command is absolute path */
	if (access(s[0], F_OK) == 0)
	{
		holder = s[0];
		t = 1;
	}
	/* else flesh out full path */
	else
		holder = _which(s[0], env);
	/* if not an executable, free */
	if (access(holder, X_OK) != 0)
	{
		not_found(s[0], num, env);
		free_double_ptr(s);
		return (127);
	}
	else /* else fork and execute executable command */
	{
		pid = fork();
		if (pid == 0) /* if child process, execute */
		{
			if (execve(holder, s, NULL) == -1)
			{
				not_found(s[0], num, env); /* special err msg */
				c_exit(s, env);
			}
		}
		else /* if parent, wait for child then free all */
		{
			wait(&status);
			free_double_ptr(s);
			if (t == 0)
				free(holder);
		}
	}
	return (0);
}

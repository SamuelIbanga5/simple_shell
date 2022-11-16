#include "shell.h"

/**
 * _which - fleshes out command by appending it to a matching PATH directory
 * @str: first command user typed into shell (e.g. "ls" if user typed "ls -l")
 * @env: environmental variable
 * Return: a copy of fleshed out command (e.g. "/bin/ls" if originally "ls")
 */
char *_which(char *str, list_t *env)
{
	char *pth, *cat = NULL, **toks;
	int i = 0;

	/* get and tokenize PATH directories, then free original string */
	pth = get_env("PATH", env);
	toks = c_str_tok(pth, ":");
	free(pth);

	/* append "/cmd" to each token to see it's legit */
	i = 0;
	while (toks[i] != NULL)
	{
		if (toks[i][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = _strdup(toks[i]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			/* free tokens before returning legit fleshed path */
			free_double_ptr(toks);
			return (cat);
		}
		free(cat); /* free concatenated string if cmd is never found */
		i++;
	}
	free_double_ptr(toks);
	return (str); /* return string if not found; won't pass execve */
}

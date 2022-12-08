#include "shell.h"
/**
 * free_tab - FREE TAbleau de tokens
 * @tabtok: Tableau de token.
 */
void free_tab(char **table)
{
	int i = 0;

	if (table != NULL)
	{
		while (table[i])
		{
			free(table[i]);
			i++;
		}
		free(table);
	}
}

#include "shell.h"

/**
 * _myhistory - shows the lists of history, a command by line, prefaced
 *              with line numbers starting at 0.
 * @info: container for potential arguments. It is used to
 *         keep constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets aliases to the string
 * @info: parameter structure
 * @str: the alias string
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, ch;
	int rt;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	ch = *p;
	*p = 0;
	rt = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = ch;
	return (rt);
}

/**
 * set_alias - sets aliases to the string
 * @info: parameter structure
 * @str: the alias string
 *
 * Return: Always 0 on success, 1 otherwise
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - aliases string printer
 * @node: node of the alias
 *
 * Return: Always 0 on success, 1 otherwise
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - imitates the builtin alias (man alias)
 * @info: container for potential arguments. It is used to
 *         keep constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int x = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		p = _strchr(info->argv[x], '=');
		if (p)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}

	return (0);
}

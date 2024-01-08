#include "binary_trees.h"

/**
 * binary_tree_is_root - check if a given node is a root
 * @node: node to check
 * Return: 1 if the node is root, otherwise 0
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node != NULL && node->parent == NULL)
	{
		return (1);
	}
	return (0);
}
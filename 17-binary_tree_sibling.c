#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibling of a node
 * @tree:  pointer to the node of the tree to search the sibling of
 * Return: sibling of the node, NULL otherwise
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node->parent->left == node)
		return (node->parent->right);
	return (node->parent->left);
}

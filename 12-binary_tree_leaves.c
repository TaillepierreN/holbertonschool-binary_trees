#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree
 * Return: 0 if tree is null, otherwise the number of leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree != NULL)
	{
		if (!tree->left && !tree->right)
			size += 1;
		size += binary_tree_leaves(tree->left);
		size += binary_tree_leaves(tree->right);
		return (size);
	}
	else
		return (0);
}

#include "binary_trees.h"

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree != NULL)
	{
		if (!tree->left && !tree->right)
			size+= 1;
		size += binary_tree_leaves(tree->left);
		size += binary_tree_leaves(tree->right);
		return (size);
	}
	else
		return (0);
}

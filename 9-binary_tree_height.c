#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height of the node, 0 if the tree is null
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_max_height, right_max_height;
	
	if (tree != NULL)
	{
		if (tree->left)
			left_max_height = 1 + binary_tree_height(tree->left);
		else
			left_max_height = 0;

		if (tree->right)
			right_max_height = 1 + binary_tree_height(tree->right);
		else
			right_max_height = 0;

		if (left_max_height > right_max_height)
			return (left_max_height);
		else
			return (right_max_height);
	}
	else
		return (0);
}

#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree:  pointer to the root node of the tree to measure the size
 * Return: size of the tree or 0 if empty
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree != NULL)
	{
		size += 1;
		/* +1 for the size of the current node*/
		size += binary_tree_size(tree->left);
		/* recursively calculate the size and add it to total*/
		size += binary_tree_size(tree->right);
		/* recursively calculate the size and add it to total*/
		return (size);
		/*return total size*/
	}
	else
	{
		return (0);
		/*if tree is emptty*/
	}
}

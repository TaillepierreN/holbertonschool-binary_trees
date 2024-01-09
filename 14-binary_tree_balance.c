#include "binary_trees.h"

/**
 * binary_tree_balance_height - measure height of a binary tree for balance
 * @tree: pointer to the root node of the tree to measure the height
 * Return: the height of the node, 0 if the tree is null
 */

size_t balance_height(const binary_tree_t *tree)
{
	size_t left_max_height, right_max_height;
	
	if (tree != NULL)
	{
		if (tree->left)
			left_max_height = 1 + balance_height(tree->left);
		else
			left_max_height = 1;

		if (tree->right)
			right_max_height = 1 + balance_height(tree->right);
		else
			right_max_height = 1;

		if (left_max_height > right_max_height)
			return (left_max_height);
		else
			return (right_max_height);
	}
	else
		return (0);
}

/**
 * binary_tree_balance - measure the balance factor of a binary tree
 * @tree: pointer to the root of the tree
 * Return: 0 if NULL, otherwise the balance factor.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int balance = 0;

	if (tree != NULL)
	{
		balance = balance_height(tree->left) - balance_height(tree->right);
		return (balance);
	}
	return (0);
}


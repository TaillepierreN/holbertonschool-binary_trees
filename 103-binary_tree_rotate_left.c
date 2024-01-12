#include "binary_trees.h"

/**
 * binary_tree_rotate_left - perform a left rotation on binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *spot_right, *spot_left;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	spot_right = tree->right;
	spot_left = spot_right->left;
	spot_right->left = tree;
	tree->right = spot_left;
	if (spot_left != NULL)
		spot_left->parent = tree;
	spot_left = tree->parent;
	tree->parent = spot_right;
	spot_right->parent = spot_left;
	if (spot_left != NULL)
	{
		if (spot_left->left == tree)
			spot_left->left = spot_right;
		else
			spot_left->right = spot_right;
	}

	return (spot_right);
}

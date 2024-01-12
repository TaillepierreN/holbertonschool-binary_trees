#include "binary_trees.h"

/**
 * binary_tree_rotate_right -  perform a right-rotation on binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *spot_left, *spot_right;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	spot_left = tree->left;
	spot_right = spot_left->right;
	spot_left->right = tree;
	tree->left = spot_right;
	if (spot_right != NULL)
		spot_right->parent = tree;
	spot_right = tree->parent;
	tree->parent = spot_left;
	spot_left->parent = spot_right;
	if (spot_right != NULL)
	{
		if (spot_right->left == tree)
			spot_right->left = spot_left;
		else
			spot_right->right = spot_left;
	}

	return (spot_left);
}
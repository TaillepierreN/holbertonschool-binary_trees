#include "binary_trees.h"

/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func) /* if NULL do nothing */
	{
		func(tree->n); /*call function pointed by func &*/
		/* passes the value of current node as an argument*/
		binary_tree_preorder(tree->left, func); /*recursive call*/
		/*on the left subtree of current node*/
		binary_tree_preorder(tree->right, func);/* *recursive call*/
		/*on the right subtree of current node*/
	}
}

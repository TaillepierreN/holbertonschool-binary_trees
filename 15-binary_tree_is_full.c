#include "binary_trees.h"

/**
 * is_recursive_full - checks if a binary tree is full resursively
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if not full, 1 if full
 */
int is_recursive_full(const binary_tree_t *tree)
{
	if (tree != NULL)
	/*if current node is not empty*/
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		(tree->left == NULL && tree->right != NULL))
		/*check if current node has exactly one child(not full)*/
		return (0);
		/*recursive call for each childs*/
		/* if any of them if not full, the tree is not full*/
		if (is_recursive_full(tree->left) == 0 ||
			is_recursive_full(tree->right) == 0)
			return (0);
			/*tree not full*/
	}
	return (1);
	/*if current node is NULL or subtrees are full*/

}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is not NULL or not full, 1 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	/* check if tree is empty*/
		return (0);
	/*call recursive function to check if the tree is full*/
	return (is_recursive_full(tree));
}

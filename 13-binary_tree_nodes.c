#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: If tree is NULL, the function must return 0, else node count
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree != NULL)
	{
		if (tree->left || tree->right)
		/*check if current node has at least 1 child*/
			count++;
		count += binary_tree_nodes(tree->left);
		/*recursively counts nodes with at least 1 child*/
		/*in the left subtree*/
		count += binary_tree_nodes(tree->right);
		/*recursively counts nodes with at least 1 child*/
		/*in the right subtree*/
		return (count);
		/* total number of nodes*/
	}
	else
	{
		return (0);
		/* if tree is empty*/
	}

}

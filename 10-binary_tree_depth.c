#include "binary_trees.h"

/**
 * binary_tree_depth -  measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure
 * Return: If tree is NULL, your function must return 0
 * else return the depth
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	/* if node is not NULL & has a parent*/
	if (tree && tree->parent)
	{
		/*if true recursively call depth of parent*/
		return (1 + binary_tree_depth(tree->parent));
		/* add 1 to the depth for the current node*/
	}
	else
	{
		return (0);
		/*if node is NULL or has no parent, depth is considered to be 0*/
	}

}

#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 * Return: NULL if node is NULL or has no uncle
 *		otherwise, a pointer to the uncle
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
	node->parent->parent == NULL)
	/*check if node is NULL or doesn't have a parent*/
	/* or a grandparent*/
		return (NULL);
	if (node->parent->parent->left == node->parent)
	/*check if the parent's parent's left child is the same as parent*/
		return (node->parent->parent->right);
		/*if true, return the right child of the grandparent(uncle)*/
	else
		return (node->parent->parent->left);
		/* if false, return the left child of the grandparent(uncle)*/

}

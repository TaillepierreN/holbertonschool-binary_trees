#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: pointer to first node
 * @second: pointer to second node
 *
 * Return: Pointer to the lowest common ancestor node of the two nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *parent_first, *parent_second;

	/* Check if node is NULL*/
	if (first == NULL || second == NULL)
		return (NULL);
	/*if nodes are the same, they are the lowest common ancestor*/
	if (first == second)
		return (first);
	/*get the parents of each node*/
	parent_first = first->parent;
	parent_second = second->parent;

	/** Check if the first node is parent of the second
	* or if the first is at root level.
	* If true, start searching for the ancestor between the
	* first node and the parent of the second node.
	*/
	if (first == parent_second || parent_first == NULL
	|| (!parent_first->parent && parent_second))
		return (binary_trees_ancestor(first, parent_second));
	/** Check if the second node is a parent of the first
	* or if the second is at root level.
    * If true, start searching for the ancestor between the
	* parent of the first node and the second node.
	*/
	if (second == parent_first || parent_second == NULL
	|| (!parent_second->parent && parent_first))
		return (binary_trees_ancestor(parent_first, second));

	/*use recursion to find the ancestor one level above for both nodes*/
	return (binary_trees_ancestor(parent_first, parent_second));
}
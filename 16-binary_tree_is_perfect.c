#include "binary_trees.h"
/**
 * is_full_recursive - checks if a binary tree is full resursively
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if not full, 1 if full
 */
int is_full_recursive(const binary_tree_t *tree)
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
		if (is_full_recursive(tree->left) == 0 ||
			is_full_recursive(tree->right) == 0)
			return (0);
			/*tree not full*/
	}
	return (1);
	/*if current node is NULL or subtrees are full*/

}

/**
 * is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is not NULL or not full, 1 otherwise
 */

int is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
	/* check if tree is empty*/
		return (0);
	/*call recursive function to check if the tree is full*/
	return (is_full_recursive(tree));
}
/**
 * check_if_leaves_at_same_level - check if all leaves are at same level
 * @tree: pointer to the node in the tree to check
 * @level: level where the node is
 * @depth: the depth at which the leaves should be
 * Return: 1 (true) if the leaf is at the right depth, 0 otherwise (false);
 */
int check_if_leaves_at_same_level(const binary_tree_t *tree,
int level, int depth)
{
	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return (depth == level);
	return (check_if_leaves_at_same_level(tree->left, level + 1, depth) &&
	check_if_leaves_at_same_level(tree->right, level + 1, depth));
}

/**
 * binary_tree_is_perfect - check if the binary tree is perfect
 * @tree: pointer to the root of the tree
 * Return: 1 if perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int isfull, depth, leaves_same_level;

	if (tree == NULL)
		return (0);
	isfull = is_full(tree);
	if (!isfull)
		return (0);
	depth = binary_tree_height(tree);
	leaves_same_level = check_if_leaves_at_same_level(tree, 0, depth);

	return (leaves_same_level);
}

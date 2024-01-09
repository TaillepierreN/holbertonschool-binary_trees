#include "binary_trees.h"


int check_if_leaves_at_same_level(const binary_tree_t *tree, int level,int depth)
{
	if (tree == NULL)
		return (1);
	if (tree->left == NULL && tree->right == NULL)
		return(depth == level);
	return check_if_leaves_at_same_level(tree->left, level + 1, depth) &&
	check_if_leaves_at_same_level(tree->right, level + 1, depth);
}

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int isfull, depth, leaves_same_level;

	if (tree == NULL)
		return (0);
	isfull = binary_tree_is_full(tree);
	if (!isfull)
		return (0);
	depth = binary_tree_height(tree);
	leaves_same_level = check_if_leaves_at_same_level(tree, 0, depth);

	return (leaves_same_level);
}

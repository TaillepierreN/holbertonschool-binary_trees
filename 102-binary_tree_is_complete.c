#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if binary tree is complete
 * @tree: pointer to root node of the tree
 * Return: 1 if complete, otherwise 0
*/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue;
	int front = 0, rear = 0, size = 0, flag = 0;

	if (tree == NULL)
		return (0);

	// Initialize the queue
	size = 10;
	queue = malloc(sizeof(*queue) * size);
	if (queue == NULL)
		return (0);

	// Enqueue the root
	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *temp = queue[front++];

		// Check left child
		if (temp->left != NULL)
		{
			if (flag) // Found a non-full node before
			{
				free(queue);
				return (0);
			}
			queue[rear++] = temp->left;
		}
		else
			flag = 1; // Set flag for non-full node

		// Check right child
		if (temp->right != NULL)
		{
			if (flag) // Found a non-full node before
			{
				free(queue);
				return (0);
			}
			queue[rear++] = temp->right;
		}
		else
			flag = 1; // Set flag for non-full node

		// Resize the queue if necessary
		if (rear >= size)
		{
			size *= 2;
			queue = realloc(queue, sizeof(*queue) * size);
			if (queue == NULL)
				return (0);
		}
	}

	free(queue);
	return (1);
}

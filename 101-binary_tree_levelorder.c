#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through a binary tree using
 * level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue, *temp;
	int front = 0, rear = 0, size = 0;

	if (tree == NULL || func == NULL)
		return;
	/* Initial size of the queue */
	size = 10;
	queue = malloc(sizeof(*queue) * size);
	if (queue == NULL)
		return;
	/* queue the root */
	queue[rear++] = tree;
	while (front < rear)
	{
		/* remove from queue a node from the queue and process it */
		temp = queue[front++];
		func(temp->n);
		/* Resize the queue if necessary */
		if (rear >= size)
		{
			size *= 2;
			queue = realloc(queue, sizeof(*queue) * size);
			if (queue == NULL)
				return;
		}
		/* queue the left child */
		if (temp->left != NULL)
			queue[rear++] = temp->left;
		/* queue the right child */
		if (temp->right != NULL)
			queue[rear++] = temp->right;
	}
	/* Clean up */
	free(queue);
}

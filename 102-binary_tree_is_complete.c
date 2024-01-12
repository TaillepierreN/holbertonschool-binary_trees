#include "binary_trees.h"

/**
 * resize_queue - resize queue if needed
 * @rear: index of the back of the queue
 * @size: size of the queue
 * @queue: pointer to queue
 */
int resize_queue(const binary_tree_t ***queue, int *size, int rear)
{
	const binary_tree_t **new_queue;

	if (rear >= *size)
	{
		*size *= 2;
		new_queue = realloc(*queue, sizeof(**queue) * (*size));
		if (new_queue == NULL)
			return (0);
		*queue = new_queue;
	}
	return (1);
}
/**
 * binary_tree_is_complete - checks if binary tree is complete
 * @tree: pointer to root node of the tree
 * Return: 1 if complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	const binary_tree_t **queue, *temp;
	int front = 0, rear = 0, size = 10, flag = 0;

	if (tree == NULL)
		return (0);
	queue = malloc(sizeof(*queue) * size);
	if (queue == NULL)
		return (0);

	queue[rear++] = tree;
	while (front < rear)
	{
		temp = queue[front++];
		if (temp->left != NULL)
		{
			if (flag)
				break;
			queue[rear++] = temp->left;
		}
		else
			flag = 1;
		if (temp->right != NULL)
		{
			if (flag)
				break;
			queue[rear++] = temp->right;
		}
		else
			flag = 1;
		if (!resize_queue(&queue, &size, rear))
			break;
	}
	free(queue);
	return ((front >= rear) ? 1 : 0);
}

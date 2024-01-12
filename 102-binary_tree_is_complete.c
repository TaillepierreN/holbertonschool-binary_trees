#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if binary tree is complete
 * @tree: pointer to root node of the tree
 * Return: 1 if complete, otherwise 0
 */
void resize_queue(int rear, int size, binary_tree_t *queue)
{
	if (rear >= size)
	{
		size *= 2;
		queue = realloc(queue, sizeof(*queue) * size);
		if (queue == NULL)
			return (0);
	}
}
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue, *temp;
	int front = 0, rear = 0, size = 0, flag = 0;

	if (tree == NULL)
		return (0);
	size = 10;
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
			{
				free(queue);
				return (0);
			}
			queue[rear++] = temp->left;
		}
		else
			flag = 1;
		if (temp->right != NULL)
		{
			if (flag)
			{
				free(queue);
				return (0);
			}
			queue[rear++] = temp->right;
		}
		else
			flag = 1;
		resize_queue(rear, size, queue);
	}
	free(queue);
	return (1);
}

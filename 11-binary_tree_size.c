#include "binary_trees.h"
void recurse_for_size(const binary_tree_t *tree, size_t *size);
/**
 * binary_tree_size - measure size of binary tree
 * @tree: tree to measure
 *
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		recurse_for_size(tree, &size)
		return (size);
	}
	return (0);
}
/**
 * recurse_for_size - recursive component of size determination
 * @tree: pointer to root of tree
 * @size: pointer to size record
 */
void recurse_for_size(const binary_tree_t *tree, size_t *size)
{
	if (tree)
	{
		recurse_for_size(tree->left, size);
		recurse_for_size(tree->right, size);
		*size++;
	}
}

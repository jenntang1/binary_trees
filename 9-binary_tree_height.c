#include "binary_trees.h"
/**
 * binary_tree_height - measure height of tree
 * @tree: tree to measure
 *
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t heightR = 0, heightL = 0;

	if (tree)
	{
		/* recurse */
		heightL = binary_tree_height(tree->left);
		heightR = binary_tree_height(tree->right);

		if (heightL > heightR)
			return (heightL);
		else
			return (heightR);
	}
	return (0);
}

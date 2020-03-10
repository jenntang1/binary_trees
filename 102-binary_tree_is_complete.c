#include "binary_trees.h"
size_t binary_tree_height(const binary_tree_t *tree);
size_t recurse_for_height(const binary_tree_t *tree);
/**
 * binary_tree_is_complete - check if tree is complete
 * @tree: tree to check
 *
 * Return: 1 if complete; 0 if incomplete
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t height;

	if (!tree)
		return (0);

	/* determine height */
	height = binary_tree_height(tree);

	

}
/**
 * binary_tree_height - measure height of tree
 * @tree: tree to measure
 *
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	return (recurse_for_height(tree) - 1);
}
/**
 * recurse_for_height - measure height
 * @tree: tree to measure
 *
 * Return: height
 */
size_t recurse_for_height(const binary_tree_t *tree)
{
	size_t heightR, heightL;

	if (!tree)
		return (0);

	heightL = recurse_for_height(tree->left);
	heightR = recurse_for_height(tree->right);

	if (heightL > heightR)
		return (heightL + 1);
	else
		return (heightR + 1);
}

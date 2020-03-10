#include "binary_trees.h"

size_t recurse_for_height(const binary_tree_t *tree);

/**
 * binary_tree_levelorder - level-order traversal function
 * @tree: pointer to the root node
 * @func: pointer to function to call for each node
 * Description: 10. Level-order traversal
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	/* base case */
	if ((tree == NULL) || (func == NULL))
	{
		;
	}

	/* if there's only one level
	if (binary_tree_height(tree) == 0)
	{
		func(tree->n);
	} */
	
	/* recursively traverse on each level
	if (binary_tree_height(tree) >= 1)
	*/
	func(tree->n);
	
	binary_tree_levelorder(tree->left, func);
	binary_tree_levelorder(tree->right, func);
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

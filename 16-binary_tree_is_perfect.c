#include "binary_trees.h"

size_t recurse_for_height(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - checks for perfect binary tree
 * @tree: pointer to the root node
 * Description: 16. Is perfect
 * Return: see below
 * 1. upon success, return 1
 * 2. upon fail, return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	/* declare and initialize variables to calculate the heights */
	int left = 0;
	int right = 0;

	/* base case */
	if (tree == NULL)
	{
		return (0);
	}

	/* if root node has no children */
	if ((tree->left == NULL) && (tree->right == NULL))
	{
		return (1);
	}

	/* calculate height of left and right subtrees */
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	/* if balance is 0, then it's perfect */
	if ((left - right) == 0)
	{
		return (1);
	}

	return (0);
}

/**
 * binary_tree_height - measure height of tree
 * @tree: tree to measure
 *
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

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

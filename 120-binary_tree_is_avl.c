#include "binary_trees.h"
int recurse_for_is_bst(const binary_tree_t *tree, int min, int max);
size_t recurse_for_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
/**
 * binary_tree_is_avl - check if tree is AVL
 * @tree: pointer to root of tree
 *
 * Return: 1 if valid AVL; 0 if not
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance_factor;

	/* check if tree is ordered */
	if (recurse_for_is_bst(tree, INT_MIN, INT_MAX) == 1)
	{
		/* determine balance factor */
		balance_factor = binary_tree_balance(tree);

		if (balance_factor  >= -1 && balance_factor <= 1)
			return (1); /* tree is AVL */
	}
	/* tree is not AVL */
	return (0);
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to node to measure the balance factor
 * Description: 14. Balance factor
 * Return: see below
 * 1. upon success, return balance factor
 * 2. upon fail, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	/* declare and initialize variables to calculate the heights */
	int left = 0;
	int right = 0;

	/* base case */
	if (tree == NULL)
	{
		return (0);
	}

	/* if given node has no balance factor */
	if ((tree->left == NULL) && (tree->right == NULL))
	{
		return (0);
	}

	/* calculate height of left and right subtrees */
	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	/* balance factor = left height - right height */
	return (left - right);
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
/**
 * recurse_for_is_bst - recursive check for BST
 * @tree: pointer to root node
 * @min: current minimum
 * @max: current maximum
 *
 * Return: 1 if BST; 0 if not
 */
int recurse_for_is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree) /* if either pointer is NULL */
		return (1);

	if ((tree->n < min) || (tree->n > max))
		return (0);

	return (recurse_for_is_bst(tree->left, min, tree->n - 1)
		&& recurse_for_is_bst(tree->right, tree->n + 1, max));
}

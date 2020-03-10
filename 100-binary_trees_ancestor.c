#include "binary_trees.h"
/**
 * binary_trees_ancestor - find lowest common ancestor
 * @first: first node to find ancestor for
 * @second: second node to find ancestor for
 *
 * Return: pointer to lowest common ancestor; NULL on failure
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *ancestor = NULL;

	if (first != NULL && second != NULL)
	{
		binary_trees_ancestor(first->parent, second);
		binary_trees_ancestor(first, second->parent);
	}
	if (first == second)
		ancestor = first;

	return ancestor;
}

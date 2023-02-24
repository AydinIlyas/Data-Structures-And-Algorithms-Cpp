/**
* @file BinaryTree.cpp
* @description Ikili Arama agaci.
* @course Veri Yapilari 1/C
* @assignment 2
* @date 08.12.2022
* @author İlyas Aydın ilyas.aydin1@ogr.sakarya.edu.tr
*/
#include "BinaryTree.hpp"
#include<iostream>
#include <cmath>

BinaryTree::BinaryTree()
{
	root = NULL;
	deleteAll = true;
}
void BinaryTree::insert(Doku *newDoku)
{
	Doku* path = root;
	if (path == NULL)
	{
		root = newDoku;
		return;
	}
	int value = newDoku->getMidValue();
	bool found = false;
	while (!found)
	{
		if (path->getMidValue() >= value)
		{
			if (path->getLeft() != NULL)
			{
				path = path->getLeft();
			}
			else {
				path->setLeft(newDoku);
				found = true;
			}
		}
		else {
			if (path->getRight() != NULL)
			{
				path = path->getRight();
			}
			else {
				path->setRight(newDoku);
				found = true;
			}
		}
	}
}
bool BinaryTree::AvlCheck(Doku* node)
{
	if (node == NULL)
		return true;
	
	if (abs(height(node->getLeft()) - height(node->getRight()))>1)
	{
		return false;
	}
	AvlCheck(node->getLeft());
	AvlCheck(node->getRight());
}
bool BinaryTree::AvlCheck()
{
	return AvlCheck(root);
}
Doku* BinaryTree::getRoot()
{
	return root;
}
int BinaryTree::height(Doku* node) { 
		if (node == NULL)
			return -1;
		return 1 + std::max(height(node->getLeft()), height(node->getRight()));
}
void BinaryTree::DestroyRecursive(Doku* node)
{
	if (node)
	{
		DestroyRecursive(node->getLeft());
		DestroyRecursive(node->getRight());
		delete node;
	}
}
BinaryTree::~BinaryTree()
{
	if(deleteAll)
	DestroyRecursive(root);
}



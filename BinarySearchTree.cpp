//
// Created by olgui on 11/27/2023.
//
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

void BinarySearchTree::insert(BinarySearchTree::Node *&aNodeptr, BinarySearchTree::Node *&aNewNodeptr) {
    if (aNodeptr == nullptr) {
        aNodeptr = aNewNodeptr;
        //cout << "?" << endl;
    }
    else if (aNewNodeptr->val < aNodeptr->val){
        insert(aNodeptr->left, aNewNodeptr);
        //std::cout << aNewNodeptr->left << endl;
    }
    else {
        insert(aNodeptr->right, aNewNodeptr);
    }
}

void BinarySearchTree::deleteNode(int aVal, BinarySearchTree::Node *&aNodePtr) {
    if (aVal < aNodePtr->val) {
        deleteNode(aVal, aNodePtr->left);
    }
    else if (aVal > aNodePtr->val){
        deleteNode(aVal, aNodePtr->right);
    }
    else {
        makeDeletion(aNodePtr);
    }
}

void BinarySearchTree::makeDeletion(BinarySearchTree::Node *&aNodePtr) {
    Node* tempNodePtr = nullptr;
    if(aNodePtr == nullptr) {
        std::cout << "cant remove" << std::endl;
    }
    else if (aNodePtr->right == nullptr) {
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->left;
        delete tempNodePtr;
    }
    else if (aNodePtr->left == nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete tempNodePtr;
    }
    else {
        tempNodePtr = aNodePtr->right;

        while(tempNodePtr->left) {
            tempNodePtr = tempNodePtr->left;
        }

        tempNodePtr->left = aNodePtr->left;
        tempNodePtr = aNodePtr;
        aNodePtr = tempNodePtr->right;
        delete tempNodePtr;
    }
}

void BinarySearchTree::insertNode(int aVal) {
    Node* newNode = new Node(aVal);
    insert(root, newNode);
}

bool BinarySearchTree::searchNode(int aVal) {
    Node* currentNode = root;
    while(currentNode) {
        if(currentNode->val == aVal) {
            return true;
        }
        else if (aVal < currentNode->val){
            currentNode = currentNode->left;
        }
        else {
            currentNode = currentNode->right;
        }
    }
    return false;
}

void BinarySearchTree::remove(int aVal) {
    deleteNode(aVal, root);
}
BinarySearchTree::Node::Node(int aVal, BinarySearchTree::Node *aLeft, BinarySearchTree::Node *aRight) {
    val = aVal;
    left = aLeft;
    right = aRight;
}
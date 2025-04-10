#ifndef CIRCULAR_DOUBLY_LINKEDLIST_H
#define CIRCULAR_DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int elementType;

typedef struct tagNode{
  elementType data;
  struct tagNode* prevNode;
  struct tagNode* nextNode;
} Node;

Node* CreateNode(elementType newData);
void DestroyNode(Node* node);
void AppendNode(Node** head, Node* newNode);
void InsertAfter(Node* current, Node* newNode);
void RemoveNode(Node** head, Node* remove);
Node* GetNodeAt(Node* head, int location);
int GetNodeCount(Node* head);
void PrintNode(Node* _node);

#endif
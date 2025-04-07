#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagNode {

  ElementType data;
  struct tagNode* prevNode;
  struct tagNode* nextNode;
} Node;

// 함수 원형 선언
Node* CreateNode(ElementType NewData);
void DestroyNode(Node* Node);
void AppendNode(Node** Head, Node* NewNode);
void InsertAfter(Node* Current, Node* NewNode);
void RemoveNode(Node** Head, Node* Remove);
Node* GetNodeAt(Node* Head, int Location);
int GetNodeCount(Node* Head);
void PrintNode(Node* _Node);

#endif
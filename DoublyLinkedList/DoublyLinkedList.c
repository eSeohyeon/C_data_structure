#include "DoublyLinkedList.h"

Node* CreateNode(ElementType NewData){

  Node* NewNode = (Node*)malloc(sizeof(Node));

  NewNode->data = NewData;
  NewNode->prevNode = NULL;
  NewNode->nextNode = NULL;

  return NewNode;
}

void DestoryNode(Node* Node){
  free(Node);
}

void AppendNode(Node** Head, Node* NewNode){

  if((*Head)==NULL){
    *Head = NewNode;
  }
  else{
    Node* tail = (*Head);
    while(tail -> nextNode !=NULL){
      tail = tail->nextNode;
    }
    tail ->nextNode = NewNode;
    NewNode->prevNode = tail;
  }
}

void InsertAfter(Node* Current, Node* NewNode){
  NewNode->nextNode = Current->nextNode;
  NewNode->prevNode = Current;

  if(Current->nextNode !=NULL){
    Current->nextNode->prevNode = NewNode;
    Current->nextNode = NewNode;
  }
}

void RemoveNode(Node** Head, Node* Remove){
  if(*Head==Remove){
    *Head = Remove->nextNode;
    if((*Head)!=NULL)
      (*Head)->prevNode = NULL;

    Remove->prevNode = NULL;
    Remove->nextNode = NULL;
  }
  else{
    Node* Temp = Remove;

    if(Remove->prevNode !=NULL)
      Remove->prevNode->nextNode = Temp->nextNode;
    if(Remove->nextNode !=NULL)
      Remove->nextNode->prevNode = Temp->prevNode;

    Remove->prevNode = NULL;
    Remove->nextNode = NULL;
  }
}

Node* GetNodeAt(Node* Head, int Location){

  Node* Current = Head;

  while(Current !=NULL&& (--Location)>=0){
    Current = Current->nextNode;
  }

  return Current;
}

int GetNodeCount(Node* Head){

  unsigned int count = 0;
  Node* Current = Head;

  while(Current !=NULL){
    Current = Current->nextNode;
    count++;
  }

  return count;
}

void PrintNode(Node* _Node){

  if(_Node->prevNode ==NULL)
    printf("prev : Null");
  else
    printf("prev : %d", _Node->prevNode->data);

  printf("current : %d", _Node->data);

  if(_Node->nextNode ==NULL)
    printf("next : Null\n");
  else
    printf("next : %d\n", _Node->nextNode->data);
}
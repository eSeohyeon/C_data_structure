#include "CircularDoublyLinkedList.h"

Node* CreateNode(elementType newData){

  Node* newNode = (Node*)malloc(sizeof(Node));

  newNode->data = newData;
  newNode->prevNode = NULL;
  newNode->nextNode = NULL;

  return newNode;
}

void DestroyNode(Node* node){
  free(node);
}

void AppendNode(Node** head, Node* newNode){
  if((*head)==NULL){
    *head = newNode;
    (*head)->nextNode = *head;
    (*head)->prevNode = *head;
  }
  else{
    Node* tail = (*head)->prevNode;
    tail->nextNode->prevNode = newNode; // append 되기 전 tail의 nextNode == head
    tail->nextNode = newNode;

    newNode->nextNode = (*head);
    newNode->prevNode = tail;
  }
}

void InsertAfter(Node* current, Node* newNode){

  newNode->nextNode = current->nextNode;
  newNode->prevNode = current;

  if(current->nextNode !=NULL){
    current->nextNode->prevNode = newNode;
    current->nextNode = newNode;
  }
}

void RemoveNode(Node** head, Node* remove){

  if(*head == remove){
    (*head)->prevNode->nextNode = remove->nextNode;
    (*head)->nextNode->prevNode = remove->prevNode;

    *head = remove->nextNode;

    remove->prevNode = NULL;
    remove->nextNode = NULL;
  }
  else{
    remove->prevNode->nextNode = remove->nextNode;
    remove->nextNode->prevNode = remove->prevNode;

    remove->prevNode = NULL;
    remove->nextNode = NULL;
  }
}

Node* GetNodeAt(Node* head, int location){

  Node* current = head;

  while(current!=NULL && (--location)>=0){
    current = current->nextNode;
  }

  return current;
}

int GetNodeCount(Node* head){

  unsigned int count = 0;
  Node* current = head;

  while(current != NULL){
    current = current->nextNode;
    count++;

    if(current == head)
      break;
  }

  return count;
}

void PrintNode(Node* _node){

  if(_node->prevNode == NULL)
    printf("prev: NULL");
  else
    printf("prev: %d", _node->prevNode->data);

  printf("current: %d", _node->data);

  if(_node->nextNode == NULL)
    printf("next: NULL\n");
  else
    printf("next: %d\n", _node->nextNode->data);
}

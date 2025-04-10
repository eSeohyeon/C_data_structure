#include "CircularDoublyLinkedList.h"

int main(void){

  int i = 0;
  int count = 0;
  Node* list = NULL;
  Node* newNode = NULL;
  Node* current = NULL;

  for (i = 0; i<5; i++){
    newNode = CreateNode(i);
    AppendNode(&list, newNode);
  }

  count = GetNodeCount(list);
  for(i=0;i<count;i++){
    current = GetNodeAt(list, i);
    printf("list[%d] : %d\n", i, current->data);
  }

  printf("\nInserting 3000 After [2]\n\n");

  current = GetNodeAt(list, 2);
  newNode = CreateNode(3000);
  InsertAfter(current, newNode);

  printf("\nRemoving Node at 2...\n");
  current = GetNodeAt(list, 2);
  RemoveNode(&list, current);
  DestroyNode(current);

  count = GetNodeCount(list);
  for(i=0;i<count*2; i++){
    if(i==0)
      current = list;
    else
      current = current->nextNode;

    printf("list[%d] : %d\n", i, current->data);
  }

  printf("\nDestroying List...\n");

  count = GetNodeCount(list);

  for(i=0;i<count;i++){
    current = GetNodeAt(list, 0);

    if(current!=NULL){
      RemoveNode(&list, current);
      DestroyNode(current);
    }
  }

  return 0;
}
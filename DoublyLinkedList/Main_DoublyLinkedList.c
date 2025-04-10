#include "DoublyLinkedList.h"

int main(void){

  int i=0;
  int count=0;
  Node* list=NULL;
  Node* NewNode=NULL;
  Node* Current=NULL;

  // 노드 5개 추가
  for(i=0; i<5; i++){
    NewNode = CreateNode(i);
    AppendNode(&list, NewNode);
  }

  // 리스트 출력
  count = GetNodeCount(list);
  for(i=0;i<count;i++){
    Current = GetNodeAt(list, i);
    printf("list[%d] : %d\n", i, Current->data);
  }

  // 리스트의 세 번째 칸 뒤에 노드 삽입
  printf("\nInserting 3000 after [2]...\n");

  Current = GetNodeAt(list, 2);
  NewNode = CreateNode(3000);
  InsertAfter(Current, NewNode);

  count = GetNodeCount(list);
  for(i=0;i<count;i++){
    Current = GetNodeAt(list, i);
    printf("list[%d] : %d\n", i, Current->data);
  }

  printf("\nDestroying list...\n");

  count = GetNodeCount(list);

  for(i=0;i<count; i++){
    Current = GetNodeAt(list, 0);

    if(Current !=NULL){
      RemoveNode(&list, Current);
      DestroyNode(Current);
    }
  }

  return 0;
}
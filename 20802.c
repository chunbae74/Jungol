// 문제: https://jungol.co.kr/problem/20801?cursor=IjE5MTU2Iiw3LDM=

#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct Node
{
    Item data;
    struct Node *next;
} Node;

Node *list_head_insert(Node *head_ptr, Item entry)
{
    Node *insert_ptr;
    insert_ptr = (Node *)malloc(sizeof(Node));
    insert_ptr->data = entry;
    insert_ptr->next = head_ptr;
    head_ptr = insert_ptr;

    return insert_ptr;
}

Node *list_insert(Node *previous_ptr, Item entry)
{
    Node *insert_ptr;
    insert_ptr = (Node *)malloc(sizeof(Node));
    insert_ptr->data = entry;
    insert_ptr->next = previous_ptr->next;
    previous_ptr->next = insert_ptr;
    return insert_ptr;
}

Node *list_saerch(struct Node *head_ptr, Item target)
{
    Node *cursor;
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->next)
    {
        if (target == cursor->data)
            return cursor;
    }

    return NULL;
}

Node *list_locate(Node *head_ptr, int position)
{
    Node *cursor;
    int i;

    cursor = head_ptr;
    for (i = 0; (i < position) && (cursor != NULL); i++)
    {
        cursor = cursor->next;
    }

    return cursor;
}

Node *list_head_remove(Node *head_ptr)
{
    if (head_ptr == NULL)
        return NULL;

    Node *remove_ptr;
    remove_ptr = head_ptr;
    head_ptr = head_ptr->next;

    free(remove_ptr);

    return head_ptr;
}

void list_remove(Node *previous_ptr)
{
    Node *remove_ptr;
    remove_ptr = previous_ptr->next;
    remove_ptr = remove_ptr->next;
    free(remove_ptr);
}

void list_print(Node *head_ptr)
{
    Node *cursor;

    for (cursor = head_ptr; cursor != NULL; cursor = cursor->next)
    {
        printf("%d ", cursor->data);
    }
}

int main()
{
    Node *head_ptr = NULL;
    Node *tail_ptr = NULL;

    /*
     * 방법1: 기존에 만들어놓은 list_head_insert로 역순으로 원소 입력
     */
    // head_ptr = list_head_insert(head_ptr, 60);
    // head_ptr = list_head_insert(head_ptr, 100);
    // head_ptr = list_head_insert(head_ptr, 70);
    // head_ptr = list_head_insert(head_ptr, 90);
    // head_ptr = list_head_insert(head_ptr, 80);

    /*
     * 방법2: list_insert 함수 수정한 뒤 tail_ptr과 함께 사용하기
     */
    head_ptr = tail_ptr = list_head_insert(head_ptr, 80);
    tail_ptr = list_insert(tail_ptr, 90);
    tail_ptr = list_insert(tail_ptr, 70);
    tail_ptr = list_insert(tail_ptr, 100);
    tail_ptr = list_insert(tail_ptr, 60);

    Node *thirdNode = list_locate(head_ptr, 2);

    if (thirdNode != NULL)
    {
        thirdNode->data = 95;
    }

    list_print(head_ptr);
    return 0;
}
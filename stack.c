#include <stdio.h>
#include <stdlib.h>

#define kMaxStackSize 1000000

struct Stack {
    int data[kMaxStackSize];
    int top; // 맨 위의 데이터 index를 담고있음
};

void InitStack(struct Stack* stack) {
    stack->top = -1;
}

void Push(struct Stack* stack, int x) {
    stack->top++;
    stack->data[stack->top] = x;
    /*
     * 간지나는 버전 (feat. 전위연산자/후위연산자))
    stack->data[++stack->top] = x;
    */
}

/*
 * 만약 stack이 비어있다면 -1을,
 * 비어있지 않다면 맨 위의 원소를 삭제 후 반환
 */
int Pop(struct Stack* stack) {
    if (stack->top == -1) {
        return -1;
    }
    int top_data = stack->data[stack->top];
    stack->top --;
    return top_data;
    /*
     * 간지나는 버전 (feat. 전위연산자/후위연산자)
    return stack->data[stack->top--];
    */
}

int Size(struct Stack* stack) {
    return (stack->top + 1);
}

/*
 * stack이 비어있다면 1을,
 * 비어있지 않다면 0을 반환한다.
*/
int IsEmpty(struct Stack* stack) {
    if (stack->top == -1) return 1;
    else return 0; 
    /*
     * 간지나는 버전 (feat. 삼항연산자)
    return stack->top == -1 ? 1 : 0;
     */
}

/*
 * 맨 위에있는 원소를 '조회'만 함. (Stack에서 없애지는 않는다)
 * Stack이 비어있다면 -1을 반환함
*/
int Top(struct Stack* stack) {
    if (IsEmpty(stack)) return -1;
    return stack->data[stack->top];
}

int main() {
    // stack 변수 선언 및 기본 설정
    struct Stack stack;
    InitStack(&stack);

    int N;
    scanf("%d", &N);

    for (int n = 0; n < N; n++) {
        char command;
        // c언어에서 여러 줄의 데이터 받는게 좀 까다로운데...
        // 일단 현재 코드에서는 %c 앞에 공백 추가한다는 것만 알고계세요...
        scanf(" %c", &command);

        // i: a라는 수를 스택에 넣는다.
        if (command == 'i') {
            int a;
            scanf("%d", &a);
            Push(&stack, a);
        }
        // o: 스택에서 데이터를 빼고, 그 데이터를 출력한다.
        // 만약 스택이 비어있다면, "empty"를 출력한다.
        else if (command == 'o') {
            int popData = Pop(&stack);
            if (popData == -1) {
                printf("empty\n");
            } else {
                printf("%d\n", popData); 
            }
            /* 간지나는 버전 (feat. 삼항연산자)
            printf("%d\n", isEmpty(&stack) ? "empty\n" : Pop(&stack));
            */
        } 
        // c: 스택에 쌓여있는 데이터의 수를 출력
        else if (command == 'c') {
            int size = Size(&stack);
            printf("%d\n", size);
        }
    }

    return 0;
}

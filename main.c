#include <stdio.h>
#include <stdlib.h>

//스택이 담는 자료형을 손쉽게 바꾸기 위함.
typedef int Data;

//Node 구조체 정의
typedef struct Node {
    Data data;
    struct Node * next;
} Node;

//Stack 구조체 정의
typedef struct Stack {
    Node *head;
    int Size;
}Stack;

//스택 함수 선언
void StackInit(Stack* st);
int StackEmpty(Stack* st);
void StackPush(Stack* st, Data data);
void StackPop(Stack* st);
Data StackTop(Stack* st);


// main 함수
int main() {

    int N; scanf("%d",&N);

    Stack st;
    StackInit(&st);

    for(int i=0; i<N; ++i){

        int x; scanf("%d",&x);

        while(1) {

            if(StackEmpty(&st)) {
                StackPush(&st, x);
                break;
            }
            else if(x >= StackTop(&st))
                StackPop(&st);
            else {
                StackPush(&st, x);
                break;
            }
        }
    }

    printf("%d\n",st.Size);

    return 0;
}





void StackInit(Stack* st) {
    st->head = NULL;
    st->Size = 0;
}

int StackEmpty(Stack* st) {
    if(st->head == NULL)
        return 1;
    else
        return 0;
}

void StackPush(Stack* st, Data data){

    Node* newNode = (Node*)malloc(sizeof(Node));
    st->Size = st->Size+1;
    newNode->data = data;
    newNode->next = st->head;
    st->head = newNode;
}

void StackPop(Stack* st) {

    if(StackEmpty(st)) {
        printf("Memory Error : Stack is empty!!\n");
        exit(-1);
    }
    Node* node = st->head;
    st->Size = st->Size-1;
    st->head = st->head->next;
    free(node);
}

Data StackTop(Stack *st){
    if(StackEmpty(st)) {
        printf("Memory Error : Stack is empty!!\n");
        exit(-1);
    }
    else
        return st->head->data;
}


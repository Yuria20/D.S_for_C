#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//스택이 담는 자료형을 손쉽게 바꾸기 위함.
typedef char* Data;

//Node 구조체 정의
typedef struct Node {
    Data data;
    struct Node* next;
} Node;

//Stack 구조체 정의
typedef struct Stack {
    Node* head;
    int Size;
}Stack;

//스택 함수 선언
void StackInit(Stack* st);
int StackEmpty(Stack* st);
void StackPush(Stack* st, Data data);
void StackPop(Stack* st);
Data StackTop(Stack* st);

//strlen(const char *s)
//문자열의 길이 반환

//char *strcat(char * restrict s1, const char * restrict s2);
// 첫번째 파라미터의 문자열 뒤에 두번째 파라미터 문자열을 이어붙임.

//int atoi(const char *nptr);
//int형 정수로 변환함.

// main 함수
int main() {



    int N; scanf("%d", &N);

    Stack st;
    StackInit(&st);


    for (int i = 0; i < N; ++i) {

        //Case 번호를 나타내주는 문자열 생성
        char Case[100] = "Case #";
        char num = (char)(49 + i);
        strcat(Case, &num);
        char ccc[] = ":";
        strcat(Case, ccc);

        //문자열 입력
        char str[25];
        scanf(" %[^\n]s", str);
        getchar();

        //단어를 떼어낼 때 필요한 정수
        int first = 0;
        int last = 0;
        // 문자의 갯수
        int size = 0;
        //문자열 길이만큼 for 문
        for (int j = 0; j < strlen(str); ++j) {
            char substr[25] ;
            if(str[j]==' ') {
                last = j;
                for(int i=0,k = first; k<last-first;++k,++i) {
                    substr[i] = str[k];
                }
                StackPush(&st,substr);
                first = last;
                ++size;
            }
        }

        char substr[25] ;
        last = strlen(str);
        for(int j=0,k = first; k<last-first;++k,++j) {
            substr[j] = str[k];
        }
        StackPush(&st,substr);
        ++size;

        for (int j = 0; j < size; ++j) {
            strcat(Case, " ");
            strcat(Case, StackTop(&st));
            StackPop(&st);
        }
        printf("%s\n", Case);
    }



    return 0;
}


void StackInit(Stack* st) {
    st->head = NULL;
    st->Size = 0;
}

int StackEmpty(Stack* st) {
    if (st->head == NULL)
        return 1;
    else
        return 0;
}

void StackPush(Stack* st, Data data) {

    Node* newNode = (Node*)malloc(sizeof(Node));
    st->Size = st->Size + 1;
    newNode->data = data;
    newNode->next = st->head;
    st->head = newNode;
}

void StackPop(Stack* st) {

    if (StackEmpty(st)) {
        printf("Memory Error : Stack is empty!!\n");
        exit(-1);
    }
    Node* node = st->head;
    st->Size = st->Size - 1;
    st->head = st->head->next;
    free(node);
}

Data StackTop(Stack* st) {
    if (StackEmpty(st)) {
        printf("Memory Error : Stack is empty!!\n");
        exit(-1);
    }
    else
        return st->head->data;
}


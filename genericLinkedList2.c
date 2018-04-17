#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXLEN 11

typedef struct NODE {
    void* data;
    struct NODE* next;
} NODE;

typedef NODE* LIST;

typedef struct AA {
    int i;
    char c;
} aSt;

typedef struct BB {
    double d;
    char str[MAXLEN];
} bSt;

typedef struct CC {
    int ci;
} cSt;

void addToList(NODE**, void*);
void printAA(void*);
void printBB(void*);
void printCC(void*);
void printAny(void (pfun)(void*), LIST);

int main() {
    NODE *aHead, *bHead, *cHead;
    void* data;
    aSt* testA;
    int cnt;

    aHead = bHead = cHead = NULL;
    srand(time(NULL));

    for(char c = 'A'; c <= 'Z'; c++) {
        //data = malloc(sizeof(aSt));
        //((aSt*)data)->c = c;
        //((aSt*)data)->i = (int) c;
        testA = (aSt*) malloc(sizeof(aSt));
        testA->c = c;
        testA->i = (int) c;
        addToList(&aHead, (void*)testA);
    }

    printf("Input number of elements: ");
    scanf("%d", &cnt);
    for(int i = 0; i < cnt; i++) {
        data = malloc(sizeof(bSt));
        printf("Name to map: ");
        scanf("%s", ((bSt*)data)->str);
        printf("Floating point to map name: ");
        scanf("%lf", &((bSt*)data)->d);
        addToList(&bHead, data);
    }

    cnt = rand() % 20 + 1;
    printf("\nGenerated random number: %d\n", cnt);
    for(int i = 0; i < cnt; i++) {
        data = malloc(sizeof(cSt));
        ((cSt*)data)->ci = rand() % 100 + 1;
        addToList(&cHead, data);
    }

    printf("\n");
    printf("Printing list A:\n");
    printAny(printAA, aHead);

    printf("\n");
    printf("Printing list B:\n");
    printAny(printBB, bHead);

    printf("\n");
    printf("Printing list C:\n");
    printAny(printCC, cHead);

    return 0;
}

void addToList(NODE** head, void* data) {
    NODE* cur = *head;
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;

    if(!(*head)) {
        *head = newNode;
        return;
    }
    while(cur->next)
        cur = cur->next;
    cur->next = newNode;
}

void printAA(void* dataA) {
    printf("ASCII code of %c is %d.\n", ((aSt*)dataA)->c, ((aSt*)dataA)->i);
}

void printBB(void* dataB) {
    printf("%11s is mapped to %lf.\n", ((bSt*)dataB)->str, ((bSt*)dataB)->d);
}

void printCC(void* dataC) {
    printf("%d\n", ((cSt*)dataC)->ci);
}

void printAny(void (pfun)(void*), LIST listHead) {
    NODE* cur = listHead;
    while(cur) {
        (pfun)(cur->data);
        cur = cur->next;
    }
}

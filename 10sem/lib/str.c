#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "str.h"

StringNode *createStrNode(char *value) {
    StringNode *node = (StringNode *)malloc(sizeof(StringNode));
    node->point = NULL;
    node->str = value;

    return node;
}

StringQueue *createStrQueue() {
    StringQueue *queue = (StringQueue *)malloc(sizeof(StringQueue));
    queue->first = NULL;
    queue->last = NULL;
    return queue;
}

void freeStrQueue(StringQueue *queue) {
    if (queue == NULL)
        return;

    for (StringNode *node = queue->first; node != NULL;) {
        StringNode *point = node;
        node = node->point;
        free(point);
    }
    free(queue);
}

void enqueueStr(StringQueue *queue, char *str) {
    if (queue == NULL) {
        printf("ERRO: Fila não foi criada\n");
    }
    else if (queue->last == NULL) {
        queue->first = createStrNode(str);
        queue->last = queue->first;
    }
    else {
        queue->last->point = createStrNode(str);
        queue->last = queue->last->point;
    }
}

char *dequeueStr(StringQueue *queue) {
    if (queue == NULL) {
        printf("ERRO: Fila nao foi criada\n");
        return NULL;
    }
    if (queue->first == NULL)
        return NULL;
    StringNode *first = queue->first;
    char *result = first->str;
    queue->first = queue->first->point;
    free(first);
    if (queue->first == NULL)
        queue->last = NULL;
    return result;
}

int inQueue(StringQueue *queue, char *str) {
    if (queue == NULL) {
        return 0;
    }
    for (StringNode *node = queue->first; node != NULL; node = node->point) {
        if (strcmp(str, node->str) == 0)
            return 1;
    }
    return 0;
}

int isQueueEmpty(StringQueue *queue) {
    return queue == NULL || queue->first == NULL ? 1 : 0;
}

StringStack *createStrStack() {
    StringStack *queue = (StringStack *)malloc(sizeof(StringStack));
    queue->last = NULL;
    return queue;
}

void freeStrStack(StringStack *stack) {
    if (stack == NULL)
        return;

    for (StringNode *node = stack->last; node != NULL;) {
        free(node->str);
        StringNode *point = node;
        node = node->point;
        free(point);
    }
    free(stack);
}

void pushStr(StringStack *stack, char *str) {
    if (stack == NULL) {
        printf("ERRO: Pilha não foi criada\n");
    }
    else if (stack->last == NULL) {
        stack->last = createStrNode(str);
    }
    else {
        StringNode *node = createStrNode(str);
        node->point = stack->last;
        stack->last = node;
    }
}

char *popStr(StringStack *stack) {
    if (stack == NULL) {
        printf("ERRO: Pilha não foi criada\n");
        return NULL;
    }
    if (stack->last == NULL)
        return NULL;

    StringNode *last = stack->last;
    char *result = last->str;

    stack->last = last->point;
    free(last);

    return result;
}

int isStackEmpty(StringStack *stack) {
    return stack == NULL || stack->last == NULL ? 1 : 0;
}
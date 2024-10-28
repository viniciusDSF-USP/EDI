typedef struct Node {
    struct Node *point;
    char *str;
} StringNode;

typedef struct {
    StringNode *first;
    StringNode *last;
} StringQueue;

typedef struct {
    StringNode *last;
} StringStack;

StringQueue *createStrQueue();
void freeStrQueue(StringQueue *queue);

void enqueueStr(StringQueue *queue, char *str);
char *dequeueStr(StringQueue *queue);

int inQueue(StringQueue *queue, char *str);

int isQueueEmpty(StringQueue *queue);

StringStack *createStrStack();
void freeStrStack(StringStack *stack);

void pushStr(StringStack *stack, char *str);
char *popStr(StringStack *stack);

int isStackEmpty(StringStack *stack);
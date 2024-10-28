#include "str.h"

typedef struct User {
    struct User *next;

    char *name;
    char *nickname;

    StringQueue *partners;
    StringQueue *requests;

    StringStack *messages;
} User;

typedef struct {
    User *first;
    User *last;
} UserList;

// Cria uma lista de usuários
UserList *createUserList();

void freeUserList(UserList *list);

// Cria um usuário, e o adiciona na lista
void addUser(UserList *list, char *name, char *nickname);

// Imprime uma lista de usuários
void printUserList(UserList *list);

// Procura por dois usuários pelo apelido, o remetente e o destinatário,
// o remetente adiciona à fila de pedidos do destinatário sua solicitação de parceria
void requestPartnership(UserList *list, char *sender, char *recipient);

void printRequests(UserList *list, char *nickname);

void sendMessage(UserList *list, char *senderNickname, char *recipientNickname, char *content);
void printMessages(UserList *list, char *nickname);

void suggestPartnerships(UserList *list, char *nickname);

void restart(UserList *list);
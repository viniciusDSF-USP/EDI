#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

User *createUser(char *name, char *nickname) {
    User *user = (User *)malloc(sizeof(User));

    user->name = name;
    user->nickname = nickname;

    user->partners = NULL;
    user->requests = NULL;

    user->next = NULL;

    return user;
}

User *freeUser(User *user) {
    User *result = user->next;

    freeStrQueue(user->partners);
    freeStrQueue(user->requests);

    freeStrStack(user->messages);

    free(user);
    return result;
}

UserList *createUserList() {
    UserList *list = (UserList *)malloc(sizeof(UserList));

    list->first = NULL;
    list->last = NULL;

    return list;
}

void freeUserList(UserList *list) {
    User *aux;
    for (User *user = list->first; user != NULL;) {
        aux = user->next;
        freeUser(user);
        user = aux;
    }
}

User *search(UserList *list, char *nickname) {
    for (User *user = list->first; user != NULL; user = user->next) {
        if (strcmp(user->nickname, nickname) == 0)
            return user;
    }
    return NULL;
}

void partner(User *sender, User *recipient) {
    if (sender->partners == NULL)
        sender->partners = createStrQueue();
    if (recipient->partners == NULL)
        recipient->partners = createStrQueue();

    enqueueStr(sender->partners, recipient->nickname);
    enqueueStr(recipient->partners, sender->nickname);
}

void addUser(UserList *list, char *name, char *nickname) {
    User *user = createUser(name, nickname);

    if (list->last == NULL) {
        list->first = user;
    }
    else {
        list->last->next = user;
    }

    list->last = user;
}

void printUserList(UserList *list) {
    if (list->first == NULL) {
        printf("Lista de usuarios vazia!\n");
    }
    else {
        printf("\nLista de usuarios:\n");
        for (User *user = list->first; user != NULL; user = user->next) {
            printf("\tNome: %s;\n", user->name);
            printf("\tApelido: %s;\n", user->nickname);
            if (user->partners != NULL) {
                printf("\tParceiros: ");
                for (StringNode *node = user->partners->first; node != NULL; node = node->point) {
                    printf("%s%s", node->str, (node->point != NULL) ? ", " : "");
                }
            }
            else
                printf("\tSem parceiros de trabalho.");
            if (user->next != NULL)
                printf("\n\n");
        }
    }
}

void requestPartnership(UserList *list, char *sender, char *recipient) {
    if (search(list, sender) == NULL)
        printf("Voce nao esta cadastrado");
    else {
        User *user = search(list, recipient);
        if (user == NULL) {
            printf("Usuario nao encontrado");
            return;
        }
        if (user->requests == NULL)
            user->requests = createStrQueue();
        enqueueStr(user->requests, sender);
        printf("Pedido enviado com sucesso!");
    }
}

void printRequests(UserList *list, char *nickname) {
    User *user = search(list, nickname);
    if (user == NULL) {
        printf("Usuario nao encontrado.");
    }
    else if (isQueueEmpty(user->requests)) {
        printf("%s nao tem pedidos de parceria.", user->name);
    }
    else {
        for (char *sender = dequeueStr(user->requests); sender != NULL; sender = dequeueStr(user->requests)) {
            printf("\t%s quer parceria. Aceita(s/n)? ", sender);
            char answer;
            scanf(" %c", &answer);
            getchar();
            if (answer == 's')
                partner(user, search(list, sender));
        }
        printf("Operacao realizada com sucesso!");
    }
}

void sendMessage(UserList *list, char *senderNickname, char *recipientNickname, char *content) {
    User *sender = search(list, senderNickname);
    User *recipient = search(list, recipientNickname);

    if (sender == NULL) {
        printf("Usuario remetente nao encontrado.");
        return;
    }

    if (recipient == NULL) {
        printf("Usuario destinatario nao encontrado.");
        return;
    }

    // Verifica se o destinatário é parceiro do remetente
    if (inQueue(sender->partners, recipient->nickname) == 0) {
        printf("Os usuarios nao sao parceiros.");
        return;
    }

    if (recipient->messages == NULL)
        recipient->messages = createStrStack();

    char *message = (char *)malloc((strlen(senderNickname) + strlen(content) + 4) * sizeof(char));

    strcpy(message, "(");
    strcat(message, senderNickname);
    strcat(message, ")");
    strcat(message, "|");
    strcat(message, content);

    pushStr(recipient->messages, message);
    printf("Mensagem enviada com sucesso!");
}

void printMessages(UserList *list, char *nickname) {
    User *user = search(list, nickname);

    if (user == NULL) {
        printf("Usuario nao encontrado.");
        return;
    }

    if (isStackEmpty(user->messages) == 1) {
        printf("Nao ha novas mensagens.");
    }

    while (isStackEmpty(user->messages) == 0) {
        char *info = popStr(user->messages);

        char *sender = strtok(info, "|");
        char *message = strtok(NULL, "|");

        printf("\t%s %s", sender, message);
        if (!isStackEmpty(user->messages))
            printf("\n");
    }
}

void suggestPartnerships(UserList *list, char *nickname) {
    int flag = 0;
    StringQueue *suggestions = createStrQueue();

    User *user = search(list, nickname);
    if (user == NULL) {
        printf("Usuario nao encontrado.");
        return;
    }

    for (User *other = list->first; other != NULL; other = other->next) {
        if (strcmp(other->nickname, user->nickname) == 0)
            continue; // Se other = user
        if (inQueue(user->partners, other->nickname) == 0)
            continue; // Se other nao eh parceiro de user

        StringQueue *temp = createStrQueue();

        while (isQueueEmpty(other->partners) == 0) {
            char *partner = dequeueStr(other->partners);

            if (strcmp(partner, user->nickname) != 0 && inQueue(user->partners, partner) == 0) {
                flag = 1;
                char *suggestion = (char *)malloc(100 * sizeof(char));
                sprintf(suggestion, "%s", partner);
                enqueueStr(suggestions, suggestion);
            }
            enqueueStr(temp, partner);
        }

        while (isQueueEmpty(temp) == 0)
            enqueueStr(other->partners, dequeueStr(temp));

        freeStrQueue(temp);
    }
    if (flag == 0) {
        printf("Nao ha parceiros em comum.");
    }
    else {
        printf("\tSugestoes de novos parceiros:\n\t");

        while (isQueueEmpty(suggestions) == 0) {
            printf("%s", dequeueStr(suggestions));
            if (!isQueueEmpty(suggestions))
                printf(", ");
        }
    }
    freeStrQueue(suggestions);
}

void restart(UserList *list) {
    freeUserList(list);
    list->first = NULL;
    list->last = NULL;
}
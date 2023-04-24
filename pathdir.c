#include "shell.h"

/**
 * Node - Structure to represent a node in the linked list
 * @dir: Directory path
 * @next: Pointer to the next node
 */
typedef struct Node
{
    char *dir;
    struct Node *next;
} Node;

/**
 * build_path_list - Builds a linked list of the PATH directories
 *
 * Return: Pointer to the head of the linked list
 */
Node *build_path_list()
{
    char *path = getenv("PATH");
    Node *head = NULL;
    Node *tail = NULL;
    char *dir;

    if (path == NULL)
        return NULL;

    dir = strtok(path, ":");



    while (dir != NULL)
    {
        Node *node = (Node *)malloc(sizeof(Node));
        if (node == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        node->dir = strdup(dir);
        if (node->dir == NULL)
        {
            perror("strdup");
            exit(EXIT_FAILURE);
        }

        node->next = NULL;

        if (tail == NULL)
        {
            head = tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }

        dir = strtok(NULL, ":");
    }

    return head;
}

int main_pathdir(void)
{
    Node *head = build_path_list();
    Node *node = head;
    while (node != NULL)
    {
        printf("%s\n", node->dir);
        node = node->next;
    }

    node = head;
    while (node != NULL)
    {
        Node *next = node->next;
        free(node->dir);
        free(node);
        node = next;
    }

    return 0;
}

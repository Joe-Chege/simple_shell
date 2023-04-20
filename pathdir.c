#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>

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
    if (path == NULL)
        return NULL;

    Node *head = NULL;
    Node *tail = NULL;
    char *dir = strtok(path, ":");

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

int main(void)
{
    // Example usage of build_path_list function
    Node *head = build_path_list();
    Node *node = head;
    while (node != NULL)
    {
        printf("%s\n", node->dir);
        node = node->next;
    }

    // Free the memory used by the linked list
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

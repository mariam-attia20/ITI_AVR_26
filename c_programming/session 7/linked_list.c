#include <stdio.h>
#include <stdlib.h>

// Structural self-referential template layout
typedef struct Node_t
{
    int data;
    struct Node_t *next;
} node;

// Initializing global base tracker frame mapping list head position
node *head = NULL;

// Insert a new node at the beginning of the list
void addFirst(int value)
{
    node *ptr = (node *)malloc(sizeof(node));

    if (ptr == NULL)
    {
        printf("Can't allocate memory\n");
    }
    else
    {
        ptr->data = value;

        if (head == NULL)
        {
            ptr->next = NULL;
        }
        else
        {
            ptr->next = head;
        }
        head = ptr;
    }
}

// Print all nodes currently linked within the chain sequence
void displaylist()
{
    if (head != NULL)
    {
        node *temp = head;

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    else
    {
        printf("Empty list\n");
    }
}

// Insert a new node at the end of the list boundary line
void addLast(int data)
{
    node *newNode = (node *)malloc(sizeof(node));

    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = NULL;

        if (head != NULL)
        {
            node *temp = head;

            // Traverse until reaching the final element node
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        else
        {
            head = newNode;
        }
    }
    else
    {
        printf("Can't allocate memory\n");
    }
}

int main()
{
    // Insertion sequences target front indices
    addFirst(4);
    addFirst(44);
    addFirst(40);

    // Insertion sequences target rear indices
    addLast(1);
    addLast(9);

    // Render final verification snapshot maps inside console output profiles
    printf("Linked List Elements: ");
    displaylist();

    return 0;
}

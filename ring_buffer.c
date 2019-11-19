#include <stdio.h>
#include <malloc.h>

typedef struct Node{
    int data;
    int empty;
    struct Node* next;
}node;  //  nickname :)

struct ring_buffer{
    node *buff_start;
    node *start;
    node *end;
};

struct ring_buffer create_buffer(int size)
{
    struct ring_buffer b;
    b.start = (node *) malloc(sizeof(node));
    b.start->empty = 1;
    b.start->next = NULL;

    node *ptr = b.start;
    for(int i=0; i<size-1; i++){
        node *newNode = (node *) malloc(sizeof(node));
        newNode->empty = 1;
        newNode->next = NULL;
        ptr->next = newNode;
        ptr = ptr->next;
    }
    ptr->next = b.start;
    b.end = b.start;
    b.buff_start = b.start;

    return b;
}

void display(struct ring_buffer b)
{
    node* ptr = b.buff_start;
    do{
        if(ptr->empty == 1)
            printf("NULL -> ");
        else
            printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }while(ptr != b.buff_start);
    printf("\b\b\b\b   \b\b\b\n");
}

struct ring_buffer enqueue(struct ring_buffer b, int data)
{
    b.end->data = data;
    b.end->empty = 0;
    b.end = b.end->next;

    return b;
}

struct ring_buffer dequeue(struct ring_buffer b)
{
    if(b.start->empty == 1)
        return b;
    b.start->empty = 1;
    b.start = b.start->next;

    return b;
}


int main(int argc, char const *argv[])
{
    int ch, size, data;
    struct ring_buffer b = {NULL, NULL}; 

    while(1){
        printf("RING BUFFER MENU");
        printf("\n1. Create Buffer with a fixed size");
        printf("\n2. Display Buffer");
        printf("\n3. Enqueue to Buffer");
        printf("\n4. Dequeue from Buffer");
        printf("\n0. EXIT");

        printf("\nEnter choice: ");
        scanf("%d", &ch);
        printf("\n");

        switch(ch){
            case 0: exit(0);    break;

            case 1: 
                printf("Enter size: ");
                scanf("%d", &size);
                b = create_buffer(size);
                break;
            
            case 2: display(b); break;

            case 3: 
                printf("Enter data: ");
                scanf("%d", &data);
                b = enqueue(b, data);
                break;

            case 4: b = dequeue(b); break;

            default: printf("Wrong Choice! Try agian!");
        }

        printf("\n\n");
    }
    return 0;
}

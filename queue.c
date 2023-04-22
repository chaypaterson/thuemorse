/* queue.c
 * This is a minimalistic implementation of a queue, using doubly linked lists.
 * This file defines the functions declared in queue.h.
 *
 * Chay (chaypaterson@gmail.com)
 */

#include "queue.h"
#include <stdlib.h>

struct Node* make_node(void* new_item) {
    /* This function receives an item on the heap, and creates a new node (on
     * the heap).
     */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->prev = 0;
    new_node->next = 0;
    new_node->item = new_item;
    return new_node;
}

void free_node(struct Node* node) {
    if (!node) return;
    free(node->item);
    free(node);
}

void enqueue(void* new_item, struct Queue* queue) {
    struct Node* new_node = make_node(new_item);
    new_node->next = queue->start;
    if (queue->start)
        (queue->start)->prev = new_node;
    queue->start = new_node;
    if (!(queue->end))
        queue->end = new_node;
}

void dequeue(struct Queue* queue) {
    struct Node* new_end = 0;
    if (queue->end)
        new_end = (queue->end)->prev;
    if (new_end)
        new_end->next = 0;
    struct Node* old_end = queue->end;
    queue->end = new_end;
    free_node(old_end);
    if (!(new_end))
        queue->start = 0;
}

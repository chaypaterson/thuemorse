/* queue.h
 * This is a minimalistic implementation of a queue used to pass data between
 * threads. The queue is implemented as a doubly linked list of items, where
 * each item is a pointer to an object on the heap. The queue itself only
 * provides the start and end nodes for items to be enqueued and dequeued. 
 *
 * Null pointers should be used for the "previous" node of the start node, the
 * "next" node of the end node, and the addresses of the start and end nodes if
 * the queue is empty.
 *
 * Chay (chaypaterson@gmail.com)
 */

#ifndef QUEUE_H
#define QUEUE_H

struct Node {
    struct Node *prev;
    struct Node *next;
    void* item; /* user-defined data goes here */
};

struct Queue {
    struct Node *start;
    struct Node *end;
};
/* New queues should be created with struct Queue queue = {0, 0}; */

/* make a new node for an item, returning the address of the created node: */
struct Node* make_node(void* new_item);

/* free a node and its item, "closing the ticket": */
void free_node(struct Node* node);

/* enqueue an item onto a queue, "opening a ticket" and creating a new node: */
void enqueue(void* new_item, struct Queue* queue);

/* dequeue the last item from a queue, "closing the ticket" and freeing the last
 * node: 
 */
void dequeue(struct Queue* queue);

#endif

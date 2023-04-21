/* queue.h
 * This is a minimalistic implementation of a queue used to pass data between
 * threads. The queue is implemented as a doubly linked list of items, where
 * each item is a pointer to some data on the heap. The queue itself only
 * provides the start and end nodes for items to be enqueued and dequeued. 
 *
 * Null pointers should be used for the "previous" node of the start node, the
 * "next" node of the end node, and the addresses of the start and end nodes if
 * the queue is empty.
 */

struct node {
    struct node *prev;
    struct node *next;
    void* item;
};

struct queue {
    struct node *start;
    struct node *end;
};

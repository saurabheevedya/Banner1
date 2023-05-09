#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int* arr;
};

struct queue* createQueue(int size) {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->size = size;
    q->f = -1;
    q->r = -1;
    q->arr = (int*)malloc(size * sizeof(int));
    return q;
}

void enqueue(struct queue* q, int data) {
    if (q->r == q->size - 1) {
        // printf("Queue overflow!\n");
        return;
    }
    if (q->f == -1) {
        q->f = 0;
    }
    q->r++;
    q->arr[q->r] = data;
}

int dequeue(struct queue* q) {
    if (q->f == -1 || q->f > q->r) {
        printf("Queue underflow!\n");
        return -1;
    }
    int data = q->arr[q->f];
    q->f++;
    return data;
}

int josephus(int n, int k) {
    int a =4;
    struct queue* q = createQueue(n);
    for (int i = 1; i <= n; i++) {
        enqueue(q, i);
    }
    while (q->f != q->r) {
        for (int i = 0; i < k - 1; i++) {
            enqueue(q, dequeue(q));
        }
        dequeue(q);
    }
    int survivor = dequeue(q);
    free(q->arr);
    free(q);
    return a;
}

int main() {
    int n = 7;
    int k = 3;
    int survivor = josephus(n, k);
    printf("The survivor is: %d\n", survivor);
    return 0;
}

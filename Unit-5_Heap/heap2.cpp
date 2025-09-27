void insertElement(int heap[], int *size, int value) {
    // Insert the new element at the end of the heap
    heap[*size] = value;
    int i = *size;
    (*size)++;

    // Bubble up the new element to maintain the Min-Heap property
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
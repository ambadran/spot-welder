
void push( *pq, FunctionPtr fp, int priority) {
    if (pq->size == MAX_SIZE) {
        // Handle queue overflow
        return;
    }

    // Insert new element at the end
    int i = pq->size++;
    while (i > 0 && pq->priorities[(i - 1) / 2] < priority) {
        pq->functions[i] = pq->functions[(i - 1) / 2];
        pq->priorities[i] = pq->priorities[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    pq->functions[i] = fp;
    pq->priorities[i] = priority;
}


FunctionPtr pop(PriorityQueue *pq) {
    if (pq->size == 0) {
        // Handle empty queue
        return NULL;
    }

    FunctionPtr result = pq->functions[0];
    pq->functions[0] = pq->functions[--pq->size];
    pq->priorities[0] = pq->priorities[pq->size];

    // Heapify down
    int i = 0;
    while (i < pq->size) {
        int maxIndex = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < pq->size && pq->priorities[leftChild] > pq->priorities[maxIndex]) {
            maxIndex = leftChild;
        }

        if (rightChild < pq->size && pq->priorities[rightChild] > pq->priorities[maxIndex]) {
            maxIndex = rightChild;
        }

        if (maxIndex == i) {
            break;
        }

        // Swap
        FunctionPtr tempFunction = pq->functions[i];
        int tempPriority = pq->priorities[i];
        pq->functions[i] = pq->functions[maxIndex];
        pq->priorities[i] = pq->priorities[maxIndex];
        pq->functions[maxIndex] = tempFunction;
        pq->priorities[maxIndex] = tempPriority;

        i = maxIndex;
    }

    return result;
}


void push_task(task_manager_t *task_manager, func_ptr fp, uint16_t period) {
    if (task_manager->size == MAXIMUM_TASK_NUM) {
        // Handle queue overflow
        return;
    }

    // handle TMR1 VALUE first

    // Insert new element at the end
    uint16_t i = pq->size++;
    uint16_t sum = 0;
    while (i > 0 && (sum + (pq->priorities[(i - 1) / 2])) > period) {
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
        int minIndex = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (leftChild < pq->size && pq->priorities[leftChild] < pq->priorities[minIndex]) {
            minIndex = leftChild;
        }

        if (rightChild < pq->size && pq->priorities[rightChild] < pq->priorities[minIndex]) {
            minIndex = rightChild;
        }

        if (minIndex == i) {
            break;
        }

        // Swap
        FunctionPtr tempFunction = pq->functions[i];
        int tempPriority = pq->priorities[i];
        pq->functions[i] = pq->functions[minIndex];
        pq->priorities[i] = pq->priorities[minIndex];
        pq->functions[minIndex] = tempFunction;
        pq->priorities[minIndex] = tempPriority;

        i = minIndex;
    }

    return result;
}



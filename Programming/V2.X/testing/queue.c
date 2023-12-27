#include <stdio.h>
#include <stdint.h>

#define QUEUE_SIZE 8

typedef struct {

  uint8_t front_ptr, rear_ptr, size;
  uint16_t* _array[QUEUE_SIZE];

} uint16_queue_t;

uint16_queue_t create_queue() {

  uint16_queue_t new_queue;
  new_queue.rear_ptr = 0;
  new_queue.front_ptr = QUEUE_SIZE - 1
  new_queue.size = 0;

  return new_queue;

}

uint8_t isFull(uint16_queue_t queue) { return (queue.size == QUEUE_SIZE); }
uint8_t isEmpty(uint16_queue_t queue) { return (queue.size == 0); }

void push_left(uint16_queue_t queue, uint16_t value) {

  if (isFull(queue)) { printf("ERROR: BUFFER FULL\n"); return; }

  queue._array[queue.rear] = value;
  queue.rear += 1;  
}

void push_right(uint16_queue_t queue, uint16_t value) {

  if (isFull(queue)) { printf("ERROR: BUFFER FULL\n"); return; }

  queue._array[queue.front] = value;
  queue.front += 1;
  ##### I think this is not what I want, It will not add next to the first rear


}

uint16_t pop_left(uint16_queue_t queue) {

  if (isEmpty(queue)) { printf("WARNING: BUFFER EMPTY\n"); return; }



}

uint16_t pop_right(uint16_queue_t queue) {

  if (isEmpty(queue)) { printf("WARNING: BUFFER EMPTY\n"); return; }



}

int main() {

  uint16_queue_t time_queue = create_queue();

}

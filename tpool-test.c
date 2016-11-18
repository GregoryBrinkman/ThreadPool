#include <stdio.h>
#include <stdlib.h>
#include "tpool.h"
#include <unistd.h>


void work(int task) {
  printf("!!!!%d%d%d is being worked on\n", task, task, task);
  usleep(300000);
  printf("!!!!%d%d%d is done being worked on\n", task, task, task);
}

int main() {
  if (tpool_init(work) == 0) {
    fprintf(stderr, "Failed creating pool\n");
    exit(EXIT_FAILURE);
  }
  int i = 1;
  while (i < 21) {
    usleep(100000);
    if (tpool_add_task(i) == 0) {
      fprintf(stderr, "Failed adding task to pool\n");
      exit(EXIT_FAILURE);
    }
    i++;
  }
  sleep(1);
}

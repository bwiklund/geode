#include <stdio.h>
#define MEM_SIZE 65536

typedef enum {
  MOVE,
  ADD,
  JUMP
} instruction;

struct Machine {
  int *mem;
  int ip;
};

int main(){
  struct Machine machine = {};
  int mem[ MEM_SIZE ] = {[0 ... MEM_SIZE-1] = 0};
  machine.mem = mem;

  while( machine.ip < MEM_SIZE ){
    int instruction = machine.mem[ machine.ip++ ];
  }

  printf("Program exited: %d",machine.mem[0]);
}

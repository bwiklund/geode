#include <stdio.h>
#define MEM_SIZE 65536

struct Machine {
  int *mem;
  int ip;
};

int main(){
  struct Machine machine = {};
  int mem[ MEM_SIZE ] = {[0 ... MEM_SIZE-1] = 0};
}

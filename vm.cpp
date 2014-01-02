#include <stdio.h>
#define MEM_SIZE 65536

typedef enum {
  JUMP,  // move to the address in the next arg
  ADD,   // add the value in the next arg's adress to ACC
  SET,   // set the ACC to be a value in the next arg
  WRITE, // write ACC to the address in the next arg
  READ   // read the adress in the next arg to ACC 
} t_instruction;

class Machine {
  public:
    int *mem;
    int ip;
    int acc;
};

int main(){
  Machine machine = Machine();
  int mem[ MEM_SIZE ] = {[0 ... MEM_SIZE-1] = 0};
  machine.mem = mem;
  
  int i = 0;
  machine.mem[i++] = SET;
  machine.mem[i++] = 1337;
  machine.mem[i++] = WRITE;
  machine.mem[i++] = 0;
  machine.mem[i++] = JUMP;
  machine.mem[i++] = MEM_SIZE;

  while( machine.ip < MEM_SIZE ){
    t_instruction instruction = (t_instruction) machine.mem[ machine.ip++ ];
    printf("%d\n",machine.ip);
    printf("%d\n",machine.acc);
    switch( instruction ){
      case JUMP:
        machine.ip = machine.mem[ machine.ip ];
        break;
      case ADD:
        machine.acc += machine.mem[ machine.ip++ ];
        break;
      case SET:
        machine.acc = machine.mem[ machine.ip++ ];
        break;
      case WRITE:
        machine.mem[ machine.mem[ machine.ip++ ] ] = machine.acc;
        break;
      case READ:
        machine.acc = machine.mem[ machine.ip++ ];
        break;
    }
  }

  printf("Exit code: %d\n\n",machine.mem[0]);

  return 1;
} 

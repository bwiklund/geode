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
    int ip = 0;
    int acc = 0;

    Machine(){
      mem = (int []) {[0 ... MEM_SIZE-1] = 0};
    }
  
    // read next opcode, increment instruction pointer
    int step(){
      return mem[ ip++ ];
    }


    int run(){
      while( ip < MEM_SIZE ){
        t_instruction instruction = (t_instruction) mem[ ip++ ];
        printf("%d\n",ip);
        printf("%d\n",acc);
        switch( instruction ){
          case JUMP:
            ip = mem[ ip ];
            break;
          case ADD:
            acc += mem[ ip++ ];
            break;
          case SET:
            acc = mem[ ip++ ];
            break;
          case WRITE:
            mem[ mem[ ip++ ] ] = acc;
            break;
          case READ:
            acc = mem[ ip++ ];
            break;
        }
      }

      return 0;
    }
};

int main(){
  Machine machine = Machine();
  
  int i = 0;
  machine.mem[i++] = SET;
  machine.mem[i++] = 1337;
  machine.mem[i++] = WRITE;
  machine.mem[i++] = 0;
  machine.mem[i++] = JUMP;
  machine.mem[i++] = MEM_SIZE;

  machine.run();

  printf("Exit code: %d\n\n",machine.mem[0]);

  return 1;
} 

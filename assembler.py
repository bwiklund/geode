import sys, struct

INSTRUCTIONS = {
  'JUMP':  0,
  'ADD':   1,
  'SET':   2,
  'WRITE': 3,
  'READ':  4
}

class Assembler:
  def load_file( self, path ):
    f = open( path )
    self.lines = [line.strip() for line in f]
    f.close()
    return self
  
  def to_bytecode( self ):
    output = []
    for line in self.lines:
      parts = line.split(' ')
      opcode = INSTRUCTIONS.get( parts[0] )
      output.append( opcode )

      for part in parts[1::]:
        output.append( int(part) )

    return output


exe = Assembler().load_file( sys.argv[1] ).to_bytecode()

fout = open('a.ge','w')

for part in exe:
  print part
  fout.write( struct.pack('i', part ) )

fout.close()


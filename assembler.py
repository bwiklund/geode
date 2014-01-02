import sys

class Assembler:
  def assemble_file( self, path ):
    f = open( path )



assembler = Assembler()
assembler.assemble_file( sys.argv[1] )

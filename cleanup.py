import sys

from os.path import dirname
from os.path import join
from os      import listdir
from os.path import isdir
from os.path import splitext
from os.path import basename

import os

root = dirname( sys.argv[0] )

deletes = ['.user', '.log',  '.ncb' , '.obj', '.idb','.lik','.pch','.ilk','.suo','.ipch',
           '.pdb', '.tlog','.lastbuildstate','.sdf','.opensdf',
           'unsuccessfulbuild']

fileNames = ['UpgradeLog','UpgradeLog2','UpgradeLog3']
def check_delete( name ):
    global deletes
    global fileNames
    fname = basename( name )
    ext = splitext( name )[1]
    if ext in deletes :
        print("D %s" % name )
        os.remove(name)

    fn = splitext(fname)[0]

    if fn in fileNames :
        print("D %s" % name )
        os.remove( name )
    

def enum_dirs( base ):
    dirs = listdir(base)
    for file in dirs :
        name = join( base , file )
        if isdir( name ):
            enum_dirs( name )
        else:
            check_delete( name )
        


enum_dirs( root )

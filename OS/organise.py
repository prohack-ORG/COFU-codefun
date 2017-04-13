import os
import sys
def listall(path, depth):
	#print "|"*(depth+1),
	for f in os.listdir(path):
		if os.path.isfile(os.path.join(path,f)):
			print "    "*(depth+1)+"|-- ",f
	for f in os.listdir(path):
		if os.path.isdir(os.path.join(path,f)):
			print "    "*(depth+1)+" ______"+"_"*len(f)
			print str("    ")*(depth+1)+"|  ",f,"  |"
			print "    "*(depth+1)+" ------"+"-"*len(f)
			oldpath = path
			path = path + "/" + f
			listall(path, depth+1)
			path = oldpath

if __name__=="__main__":
	print "\n"
	if len(sys.argv)>1:
		path=sys.argv[1]
	else:
		path=os.getcwd()
	listall(str(path),0)
	print "\n"

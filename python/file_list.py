import os 
import sys
import shutil

"""
This function interpretes the given file size to human readable format
"""
def read_human(size_b):
	for suffix in ["Byte","KByte","MByte","GByte"]:
		if size_b < 1024:
			return (size_b, suffix)
		size_b = size_b/1024.0

"""
This function recursively lists all the files under specified directory (if specified) or otherwise the current working directory.
"""
def listall_nice(path, depth):
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
			listall_nice(path, depth+1)
			path = oldpath
			
def listall(path):
	for f in os.listdir(path):
		copyof_path = path
		abs_filename = os.path.join(path,f)
		if os.path.isdir(abs_filename):
			listall(abs_filename)
		elif os.path.isfile(abs_filename):
			size, suffix = read_human(os.path.getsize(abs_filename))
			print "[ "+'{:>6.2f} {:<5s}'.format(size, suffix) + " ]\t" + '{:20s}'.format( abs_filename)
		path = copyof_path 

"""
This function copies files to destination folder with name as caps of their extention.
"""
def restructure(path, dst_dir):
	for f in os.listdir(path):
		copyof_path = path
		abs_filename = os.path.join(path,f)
		if os.path.isdir(abs_filename):
			# print (abs_filename)
			restructure(abs_filename, dst_dir)
		elif os.path.isfile(abs_filename):
			filename, file_extension = os.path.splitext(abs_filename)
			if file_extension != "":
				# print "{:>4s}\t{:<s}".format(file_extension, filename)
				dir_name = file_extension.split(".")[1].upper()
				if not os.path.exists(os.path.join(dst_dir, dir_name)):
					os.makedirs(os.path.join(dst_dir, dir_name))
				# print "copying from %s   -->   %s" %(abs_filename, os.path.join(dst_dir, dir_name))
				shutil.copy2(abs_filename, os.path.join(dst_dir, dir_name))
		path = copyof_path 

"""
main entry point to the function (test wrapper)
"""		
if __name__=="__main__":
	if  len(sys.argv) > 1:
		path = str(sys.argv[1])
	else:
		path=os.getcwd()
	# listall(path)
	# listall_nice(path,0)
	dst_dir = "D:\\python_cpoy_test\\"
	restructure(path, dst_dir)
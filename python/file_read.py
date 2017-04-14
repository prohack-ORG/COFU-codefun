# Use words.txt as the file name
fname = raw_input("Enter file name: ")
try:
    fh = open(fname,'r')
except:
    print "No file found with such name"
    exit()
for line in fh:
    print line.upper().rstrip()
    print line.find('p')

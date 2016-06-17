#!/usr/bin/python

import sys
import base64

def main():
    f = sys.argv[1]
    data = file(f).read()
#    bys = ", ".join(["0x%02x" % ord(i) for i in data])
#    output = """static const byte midi[] = {
#    %s
#    };""" % bys
    bd = data.encode("base64")
    for i in bd.split("\n"):
        print "client.println(\"%s\");" % i

if __name__ == "__main__":
    main()

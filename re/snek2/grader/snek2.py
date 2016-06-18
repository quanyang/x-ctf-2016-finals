#!/usr/bin/python

import hashlib
import sys

def check_pass(wpass):
    p1 = hashlib.md5(wpass).hexdigest()
    p2 = hashlib.md5(p1).hexdigest()
    if p2 == "c3d2c9af1491c4f2df2d49e397d28aa9":
        print("XCTF{%s}" % hashlib.sha256(wpass).hexdigest()[::-1])
    else:
        print("Try again")

def main():
    check_pass(sys.argv[1])

if __name__ == "__main__":
    main()

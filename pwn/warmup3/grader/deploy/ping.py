#!/usr/bin/python3

import sys
import subprocess


def main():
    sys.stdout.write("Enter the IP address or domain of the website you wish"
                     " to ping: ")
    sys.stdout.flush()
    ip = sys.stdin.readline()
    print(subprocess.getoutput("ping -c 1 " + ip))

if __name__ == "__main__":
    main()

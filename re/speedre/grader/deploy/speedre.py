#!/usr/bin/python

import random
import sys
import tempfile
import os
import subprocess
import string
import signal

FLAG = file("/home/speedre/flag").read()

NUMVARS = 3
NUMEQS = 3
TEMPLATE = file("/home/speedre/template.c").read()
FN_TEMPLATE = """int x%d(char inp[]) {
    int coefs[] = {%s};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (%d - sum);
}"""

NUMPASS = 50

class Alarm(Exception):
    pass

def alarm_handler(signum, frame):
    raise Alarm

def generate_constraint(solns, numvars):
    coefs = [random.randrange(0, 100) for i in range(numvars)]
    result = sum(map(lambda x,y: x*y, solns, coefs))
    return (coefs, result)

def generate_constraints(numvars, numeqs):
    solns = [ord(random.choice(string.printable[:-6])) for i in range(numvars)]
    eqns = []
    for i in range(numeqs):
        eqns.append(generate_constraint(solns, numvars))
    return (solns, eqns)

def generate_src():
    constraints = generate_constraints(NUMVARS, NUMEQS)
    functions = []
    call = []
    for i in range(NUMEQS):
        vs = constraints[1][i]
        coefs = ", ".join(map(str, vs[0]))
        fn = FN_TEMPLATE % (i, coefs, vs[1])
        functions.append(fn)
        call.append("x%d(user)" % i)
    src = TEMPLATE % ("\n".join(functions), NUMVARS, NUMVARS, " || ".join(call))
    return (src, constraints)

def write(data, end="\n"):
    sys.stdout.write(data + end)
    sys.stdout.flush()

def comp(data):
    tf = tempfile.mkstemp(suffix=".c")
    cf = os.fdopen(tf[0], 'w')
    cf.write(data)
    cf.flush()
    cf.close()
    subprocess.check_call(["gcc", "-o", tf[1][:-2], tf[1]])
    #os.remove(tf[1])
    return tf[1][:-2]

def main():
    write("Welcome to the Speed Reversing Challenge!")
    write("In this game, you are given 5 seconds to reverse a randomly "
          "generated binary.")
    write("Complete 50 rounds and you'll get the flag. Ready? Go!\n")

    win = True
    signal.signal(signal.SIGALRM, alarm_handler)

    for i in range(NUMPASS):

        if not win:
            write("Sorry, you've failed")
            break

        src = generate_src()
        loc = comp(src[0])
        bine = file(loc).read()
        write(bine.encode("base64").replace("\n", ""))

        try:
            signal.alarm(5)
            #userin = "".join(chr(i) for i in src[1][0])
            userin = sys.stdin.read(NUMVARS)
            signal.alarm(0)
        except:
            write("Timed out")
            userin = "\x01"*NUMVARS
            win = False

        proc = subprocess.Popen(loc, stdin=subprocess.PIPE,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE)
        proc.stdin.write(userin)
        proc.stdin.flush()
        result = proc.stdout.read()

        if ("Success" not in result):
            win = False

        os.remove(loc)

    if win:
        write("Flag: %s" % FLAG)
    else:
        write("No flag for you")

if __name__ == "__main__":
    main()

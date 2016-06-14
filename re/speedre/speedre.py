#!/usr/bin/python

import random

NUMVARS = 3
NUMEQS = 3

def generate_constraint(solns, numvars):
    coefs = [random.randrange(0, 100) for i in range(numvars)]
    result = sum(map(lambda x,y: x*y, solns, coefs))
    return (coefs, result)

def generate_constraints(numvars, numeqs):
    solns = [random.randrange(1, 255) for i in range(numvars)]
    eqns = []
    for i in range(numeqs):
        eqns.append(generate_constraint(solns, numvars))
    return (solns, eqns)

def main():
    print generate_constraints(NUMVARS, NUMEQS)

if __name__ == "__main__":
    main()

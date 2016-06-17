import angr
import cle
import StringIO
import socket

def recvline(s):
    data = ""
    while True:
        c = s.recv(1)
        if c == "\n":
            break
        data += c
    return data + "\n"

def main():
    r = socket.socket()
    r.connect(("172.17.0.1", 2323))
    recvline(r)
    recvline(r)
    recvline(r)
    recvline(r)

    for i in range(50):
        print("Iteration %d" % i)
        bine = recvline(r)
        obj = cle.Loader(StringIO.StringIO(bine.decode("base64")))
        proj = angr.Project(obj)
        cfg = proj.analyses.CFG()
        for j in proj.kb.functions:
            if proj.kb.functions[j].name == "success":
                success = proj.kb.functions[j].addr
            if proj.kb.functions[j].name == "failure":
                failure = proj.kb.functions[j].addr
        pg = proj.factory.path_group().explore(find=success, avoid=failure)
        if pg.found:
            solution = pg.found[0].state.posix.dumps(0)
            print("Found input to %d: %s" % (i, solution))
            r.sendall(solution)
        else:
            print("Failure to find a solution on iteration %d" % i)
            exit()

    flag = recvline(r)
    print flag

if __name__ == "__main__":
    main()

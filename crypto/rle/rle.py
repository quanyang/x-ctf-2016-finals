import random
import string

def chunk_ruler(l, m):
    c = []
    while l != 0:
        r = random.randrange(1, m)
        if r > l:
            r = l
        c.append(r)
        l -= r
    return c

def encrypt(s):
    numbers = []
    letters = []
    chunks = chunk_ruler(len(s), 5)
    for i in chunks:
        numbers.append('0')
        numbers.append(str(i))
        letter = random.choice(string.ascii_uppercase)
        letters.append(letter)
        current = s[:i]
        s = s[i:]
        for j in current:
            numbers.append('%02x' % (ord(j) ^ ord(letter)))
    return "[%s]%s" % (":".join(numbers), "".join(letters))

def decrypt(s):
    first, second = s[1:].split("]")
    numbers = [map(lambda x: int(x, 16), i.split(":")[1:]) for i in
                   first[2:].replace(":0:", "|").split("|")]
    letters = map(ord, second)
    dec = ""
    for i in range(len(numbers)):
        for j in numbers[i]:
            dec += chr(letters[i] ^ j)
    return dec

def main():
    hw = encrypt("Hello World!")
    wc = encrypt("Welcome to XCTF")
    fl = encrypt("XCTF{Run_Length_Encoding_Was_Supposed_To_Be_Compression!}")
    print hw
    print wc
    print fl
    print decrypt(hw)
    print decrypt(wc)
    print decrypt(fl)

if __name__ == "__main__":
    main()

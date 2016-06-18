def grade(arg, key):
    if "XCTF{easy_injection}" in key:
        return True, "Damn easy."
    else:
        return False, "Try harder."


def grade(arg, key):
    if "XCTF{preloading_never_fails}" in key:
        return True, "Very easy."
    else:
        return False, "Wrong."

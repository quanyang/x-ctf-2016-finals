def grade(arg, key):
    if "Run_Length_Encoding_Was_Supposed_To_Be_Compression!" in key:
        return True, "Correct!"
    else:
        return False, "Wrong!"

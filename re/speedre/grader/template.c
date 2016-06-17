#include <stdio.h>
#include <stdlib.h>

%s

void success() {
    puts("Success! Submit this input to the server.");
}

void failure() {
    puts("Nope, you fail.");
}

int main() {
    char user[%d];
    read(0, user, %d);
    if (%s) {
        failure();
    }
    else {
        success();
    }
}

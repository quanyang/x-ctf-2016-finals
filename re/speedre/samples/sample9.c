#include <stdio.h>
#include <stdlib.h>

int x0(char inp[]) {
    int coefs[] = {12, 17, 42};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (3653 - sum);
}
int x1(char inp[]) {
    int coefs[] = {15, 16, 75};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (5137 - sum);
}
int x2(char inp[]) {
    int coefs[] = {87, 6, 88};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (9752 - sum);
}

void success() {
    puts("Success! Submit this input to the server.");
}

void failure() {
    puts("Nope, you fail.");
}

int main() {
    char user[3];
    read(0, user, 3);
    if (x0(user) || x1(user) || x2(user)) {
        failure();
    }
    else {
        success();
    }
}

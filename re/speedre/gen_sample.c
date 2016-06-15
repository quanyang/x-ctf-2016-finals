#include <stdio.h>
#include <stdlib.h>

int x0(char inp[]) {
    int coefs[] = {35, 51, 91};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (12656 - sum);
}
int x1(char inp[]) {
    int coefs[] = {56, 90, 4};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (9416 - sum);
}
int x2(char inp[]) {
    int coefs[] = {79, 5, 72};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (13403 - sum);
}

void success() {
    puts("Success! Submit this input as base64 to the server.");
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

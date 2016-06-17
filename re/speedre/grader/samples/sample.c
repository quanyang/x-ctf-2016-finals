#include <stdio.h>
#include <stdlib.h>

int a(char inp[]) {
    int coefs[] = {1, 2, 3};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (398 - sum);
}

int b(char inp[]) {
    int coefs[] = {2, 3, 4};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (596 - sum);
}

int c(char inp[]) {
    int coefs[] = {3, 4, 5};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (794 - sum);
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
    if (a(user) || b(user) || c(user)) {
        failure();
    }
    else {
        success();
    }
}

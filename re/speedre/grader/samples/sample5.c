#include <stdio.h>
#include <stdlib.h>

int x0(char inp[]) {
    int coefs[] = {89, 6, 4, 83, 72, 24, 53};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (25261 - sum);
}
int x1(char inp[]) {
    int coefs[] = {89, 10, 95, 46, 89, 56, 23};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (28500 - sum);
}
int x2(char inp[]) {
    int coefs[] = {78, 86, 69, 88, 7, 78, 96};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (42361 - sum);
}

void success() {
    puts("Success! Submit this input to the server.");
}

void failure() {
    puts("Nope, you fail.");
}

int main() {
    char user[7];
    read(0, user, 7);
    if (x0(user) || x1(user) || x2(user)) {
        failure();
    }
    else {
        success();
    }
}

#include <stdio.h>
#include <stdlib.h>

int x0(char inp[]) {
    int coefs[] = {29, 71, 92};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (8693 - sum);
}
int x1(char inp[]) {
    int coefs[] = {79, 9, 31};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (2760 - sum);
}
int x2(char inp[]) {
    int coefs[] = {44, 26, 44};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (3986 - sum);
}
int x3(char inp[]) {
    int coefs[] = {89, 83, 95};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (10334 - sum);
}
int x4(char inp[]) {
    int coefs[] = {54, 91, 67};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (9358 - sum);
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
    if (x0(user) || x1(user) || x2(user) || x3(user) || x4(user)) {
        failure();
    }
    else {
        success();
    }
}

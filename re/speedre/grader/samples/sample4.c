#include <stdio.h>
#include <stdlib.h>

int x0(char inp[]) {
    int coefs[] = {63, 73, 25, 52, 19, 39, 96};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (26846 - sum);
}
int x1(char inp[]) {
    int coefs[] = {75, 30, 63, 49, 61, 41, 34};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (29181 - sum);
}
int x2(char inp[]) {
    int coefs[] = {14, 56, 87, 68, 30, 13, 97};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (27428 - sum);
}
int x3(char inp[]) {
    int coefs[] = {53, 63, 73, 14, 58, 44, 68};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (30306 - sum);
}
int x4(char inp[]) {
    int coefs[] = {53, 39, 10, 64, 73, 34, 9};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (22788 - sum);
}
int x5(char inp[]) {
    int coefs[] = {9, 83, 71, 97, 53, 35, 57};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (30616 - sum);
}
int x6(char inp[]) {
    int coefs[] = {70, 24, 76, 65, 12, 17, 35};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (23985 - sum);
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
    if (x0(user) || x1(user) || x2(user) || x3(user) || x4(user) || x5(user) || x6(user)) {
        failure();
    }
    else {
        success();
    }
}

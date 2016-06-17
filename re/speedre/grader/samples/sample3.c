#include <stdio.h>
#include <stdlib.h>

int x0(char inp[]) {
    int coefs[] = {64, 42, 65, 70, 89, 49, 36, 84, 52, 67};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (45603 - sum);
}
int x1(char inp[]) {
    int coefs[] = {55, 81, 66, 28, 16, 41, 88, 4, 5, 32};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (30291 - sum);
}
int x2(char inp[]) {
    int coefs[] = {6, 43, 54, 9, 70, 27, 41, 70, 57, 84};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (36762 - sum);
}
int x3(char inp[]) {
    int coefs[] = {3, 90, 88, 50, 9, 0, 71, 84, 55, 30};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (35284 - sum);
}
int x4(char inp[]) {
    int coefs[] = {9, 30, 46, 77, 34, 25, 57, 20, 29, 80};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (30136 - sum);
}
int x5(char inp[]) {
    int coefs[] = {1, 43, 58, 34, 93, 72, 25, 73, 60, 15};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (31858 - sum);
}
int x6(char inp[]) {
    int coefs[] = {72, 86, 18, 34, 99, 29, 13, 14, 80, 90};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (45012 - sum);
}
int x7(char inp[]) {
    int coefs[] = {45, 60, 10, 33, 2, 77, 0, 69, 63, 29};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (30012 - sum);
}
int x8(char inp[]) {
    int coefs[] = {72, 31, 39, 36, 71, 56, 13, 74, 12, 54};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (33373 - sum);
}
int x9(char inp[]) {
    int coefs[] = {29, 72, 43, 91, 52, 3, 10, 38, 85, 37};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (34917 - sum);
}

void success() {
    puts("Success! Submit this input to the server.");
}

void failure() {
    puts("Nope, you fail.");
}

int main() {
    char user[10];
    read(0, user, 10);
    if (x0(user) || x1(user) || x2(user) || x3(user) || x4(user) || x5(user) || x6(user) || x7(user) || x8(user) || x9(user)) {
        failure();
    }
    else {
        success();
    }
}

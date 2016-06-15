#include <stdio.h>
#include <stdlib.h>

int x0(char inp[]) {
    int coefs[] = {20, 92, 67, 61};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (14853 - sum);
}
int x1(char inp[]) {
    int coefs[] = {17, 94, 2, 41};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (10487 - sum);
}
int x2(char inp[]) {
    int coefs[] = {61, 72, 81, 44};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (14220 - sum);
}
int x3(char inp[]) {
    int coefs[] = {36, 0, 31, 27};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (4653 - sum);
}

void success() {
    puts("Success! Submit this input to the server.");
}

void failure() {
    puts("Nope, you fail.");
}

int main() {
    char user[4];
    read(0, user, 4);
    if (x0(user) || x1(user) || x2(user) || x3(user)) {
        failure();
    }
    else {
        success();
    }
}

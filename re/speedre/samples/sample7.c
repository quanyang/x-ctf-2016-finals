#include <stdio.h>
#include <stdlib.h>

int x0(char inp[]) {
    int coefs[] = {64, 43, 26, 81, 58, 30, 43, 69, 37};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (41556 - sum);
}
int x1(char inp[]) {
    int coefs[] = {65, 37, 71, 33, 46, 42, 19, 50, 8};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (33521 - sum);
}
int x2(char inp[]) {
    int coefs[] = {73, 97, 20, 7, 56, 77, 17, 14, 26};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (40437 - sum);
}

void success() {
    puts("Success! Submit this input to the server.");
}

void failure() {
    puts("Nope, you fail.");
}

int main() {
    char user[9];
    read(0, user, 9);
    if (x0(user) || x1(user) || x2(user)) {
        failure();
    }
    else {
        success();
    }
}

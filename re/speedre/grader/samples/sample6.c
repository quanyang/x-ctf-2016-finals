#include <stdio.h>
#include <stdlib.h>

int x0(char inp[]) {
    int coefs[] = {41, 29, 11};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (6648 - sum);
}
int x1(char inp[]) {
    int coefs[] = {61, 54, 85};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (18316 - sum);
}
int x2(char inp[]) {
    int coefs[] = {72, 23, 19};
    int sum = 0;
    int i;
    for (i = 0; i < 3; i++) {
        sum += inp[i] * coefs[i];
    }
    return (9740 - sum);
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

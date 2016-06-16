// gcc -m32 -O0 -o warmup2 warmup2.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PASS_LEN 8

int explode()
{
    puts("         GOSH! It is exploded! AHHH!        ");
    puts("                                            ");
    puts("               _ ._  _ , _ ._               ");
    puts("                                            ");
    puts("             (_ ' ( `  )_  .__)             ");
    puts("          ( (  (    )   `)  ) _)            ");
    puts("         (__ (_   (_ . _) _) ,__)           ");
    puts("               `~~`\\ ' . /`~~`             ");
    puts("               ,::: ;   ; :::,              ");
    puts("              ':::::::::::::::'             ");
    puts("         __________/_ __ \\____________     ");
    puts("         ___________!!!!!______________     ");
    puts("                                            ");
    puts("                                            ");
    return 0;
}

int main(int argc, char *argv[])
{
    char username[100] = {0};
    char real_pass[PASS_LEN] = {0};
    char in_pass[20] = {0};
    FILE *pass_file = NULL;
    int rsize = 0;

    pass_file = fopen("password.txt", "r");
    if (pass_file == NULL) {
        fprintf(stderr, "error: feed me password\n");
        explode();
        exit(EXIT_FAILURE);
    }

    rsize = fread(real_pass, 1, PASS_LEN, pass_file);
    real_pass[strcspn(real_pass, "\n")] = '\0'; 
    if (rsize != PASS_LEN) {
        fprintf(stderr, "error: Invalid password\n");
        explode();
        exit(EXIT_FAILURE);
    }

    fclose(pass_file);

    puts("*-----------------------------------------------*");
    puts("*---- [You must login to defuse the bomb. ] ----*");
    puts("*-----------------------------------------------*");

    printf("*---Your Name: ");
    fflush(stdout);
    fgets(username, 100, stdin);
    username[strcspn(username, "\n")] = '\0';  

    printf("*---Your Password: ");
    fflush(stdout);
    fgets(in_pass, sizeof(in_pass), stdin);
    in_pass[strcspn(in_pass, "\n")] = '\0';     

    puts("*-----------------------------------------------*");
    fflush(stdout);

    if(!strncmp(real_pass, in_pass, PASS_LEN)){
        printf("ok.ok.I will give you your shell, %s!\n", username);
        fflush(stdout);
        system("/bin/sh");
    } else {
        printf(username);
        printf(" .Hey no shell!!\n");
        explode();
        fflush(stdout);
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

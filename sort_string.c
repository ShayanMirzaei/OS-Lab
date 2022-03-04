#include "types.h"
#include "stat.h"
#include "user.h"
//#include "string.h"
#include "fcntl.h"

#define STRINGSIZE 100

char * sort_str(char in[]) {

    static char result[STRINGSIZE];
    strcpy(result, in);
    char temp;
    uint len = strlen(in);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
          if (result[i] > result[j]) {
                temp = result[i];
                result[i] = result[j];
                result[j] = temp;
            }
        }
    }

    //printf("you entered : %s\n", in);
    //printf("result : %s\n", result);
    return result;

}

void file_write(char a[]) {

    int s = strlen(a);
    unlink("sort_string.txt");
    int f = open("sort_string.txt", O_CREATE | O_WRONLY);
    
    //printf(1, "len is : %d\n", s); 
    write(f, a, s);
    write(f, "\n", 1);
    close(f);

}

int main(int argc, char** argv) {

    char * a = sort_str(argv[1]);
    file_write(a);
    exit();

}

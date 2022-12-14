#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);

int parse_int(char*);

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

int pageCount(int n, int p) {
        int i, f, k, c1 = 0, c2 = 0, flag, a, b = 0;
        k = (n % 2 != 0) ? 1 : 0;
        f = (p % 2 != 0) ? 1 : 0;
        if(k == 1) {
          for(i = 1; i <= n; i += 2) {
              if(f == 1) {
                  if(i == p) {
                      break;
                  }
                  c1++;
              }
              else {
                if(i - 1 == p) {
                    break;
                }
                c1++;
              }
          }
          for(i = n; i >= 0; i -= 2) {
            if(f == 1) {
                if(i == p) {
                    break;
                }
                c2++;
            }
            else {
              if(i - 1 == p) {
                  break;
              }
              c2++;
            }
          }
        }
        else {
            for(i = 1; i <= n - 1; i += 2) {
              if(f == 1) {
                  if(i == p) {
                      flag = 1;
                      break;
                  }
                  c1++;
              }
              else {
                if(i - 1 == p) {
                    break;
                }
                c1++;
              }
            }
            if(flag != 1)
              c1++;
            for(i = n; i >= 1; i -= 2) {
              if(f != 1) {
                  if(i == p) {
                    a = 0;
                    break;
                  }
                  c2++;
              }
              else {
                if(i == p && b == 0) {
                  flag = 3;
                  a = 0;
                  b = 2;
                  break;
                }
                else if (i + 1 == p) {
                  flag = 3;
                  a = 0;
                  break;
                }
                c2++;
              }
            }
            if (flag != 3 && a != 0)
              c2++;
        }
        if(c1 > c2)
            return c2;
        else
            return c1;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    int p = parse_int(ltrim(rtrim(readline())));

    int result = pageCount(n, p);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* ltrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
    }

    return str;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;

    while (end >= str && isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    return str;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);

    if (endptr == str || *endptr != '\0') {
        exit(EXIT_FAILURE);
    }

    return value;
}

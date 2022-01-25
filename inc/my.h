#include <stdlib.h>
#include <stdio.h>

typedef struct s_garbage garbage_t;

struct s_garbage {
    void *allocated;
    garbage_t *next;
};

garbage_t *collection = NULL;

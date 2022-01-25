#include "../inc/my.h"

#ifdef __GNUC__
    #define UNUSED(x) UNUSED_##x __attribute__((__unused__))
#else
    #define UNUSED(x) UNUSED_##x
#endif

void *my_malloc(int size)
{
    extern garbage_t *collection;
    garbage_t *garbage = malloc(sizeof(garbage_t));
    void *allocation = malloc(size);

    if (allocation == NULL)
        return NULL;
    garbage->allocated = allocation;
    garbage->next = collection;
    collection = garbage;
    return allocation;
}

void my_dealloc()
{
    garbage_t *old = NULL;
    extern garbage_t *collection;

    if (!(collection->next))
        return;
    while (collection) {
        old = collection;
        free(collection->allocated);
        collection = collection->next;
        free(old);
    }
}

int main(int UNUSED(argc), char **UNUSED(argv))
{
    char **memory_array = my_malloc(sizeof(char *) * 1000);

    for (int i = 0; i < 1000; i++) {
        memory_array[i] = my_malloc(1000);
    }
    my_dealloc();
}

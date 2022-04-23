#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct file_s {
	char * filename;
	int id;
} file_t;

void memdel(void **ptr) {
	if (ptr) {
		printf("free this : %p\n", ptr);
		free(*ptr);
		*ptr = NULL;
	}
}

int fun(void) {
    void *data __attribute__((cleanup(memdel)));
    void *str __attribute__((cleanup(memdel)));
	file_t *file_ptr = NULL;

	if (!(data = malloc(sizeof(file_t))))
		return (3);
	if (!(str = strdup("super_secret_passwd.txt")))
		return (2);
	printf("file:%p;filename:%p\n", &data, &str);
	file_ptr = data;
	file_ptr->filename = str;
	file_ptr->id = 0;
	if (0)
		return (1);
	printf("filename:%s;id:%d\n", file_ptr->filename, file_ptr->id);
	return (0);
}

int main(void) {
    return (fun());
}
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

int main(void) {
    void *data;
    void *str;
	file_t *file_ptr = NULL;

	if (!(data = malloc(sizeof(file_t))))
		goto end;
	if (!(str = strdup("super_secret_passwd.txt")))
		goto error1;
	printf("file:%p;filename:%p\n", &data, &str);
	file_ptr = data;
	file_ptr->filename = str;
	file_ptr->id = 0;
	if (1)
		goto error2;
	printf("filename:%s;id:%d\n", file_ptr->filename, file_ptr->id);

	error2:
		memdel((void**)&str);
	error1:
		memdel((void**)&data);
	end:
		return (1);
}
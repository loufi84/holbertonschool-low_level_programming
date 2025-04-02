#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void display_elf_header(Elf64_Ehdr *header);
void print_error(char *message);


#endif /* MAIN_H */

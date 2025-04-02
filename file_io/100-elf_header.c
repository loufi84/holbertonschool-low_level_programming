#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <elf.h>

/**
 * print_error - A function that prints error
 *
 * @message: The message to print
 *
 * Return: Nothing
 */

void print_error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(98);
}

/**
 * display_elf_header - A function that display the ELF header
 *
 * @header: The header to display
 *
 * Return: Nothing
 */

void display_elf_header(Elf64_Ehdr *header)
{
	int i = 0;

	printf("Magic:	");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("Class:						");
	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (header->e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("Invalid class\n");

	printf("Data:						");
	if (header->e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (header->e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("Invalid data encoding\n");

	printf("Version:					%d\n", header->e_ident[EI_VERSION]);
	printf("OS/ABI:						");
	if (header->e_ident[EI_OSABI] == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else
		printf("Other OS/ABI\n");
	printf("ABI Version:			%d\n", header->e_ident[EI_ABIVERSION]);
	printf("Type:					");
	if (header->e_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (header->e_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else
		printf("Other type\n");
	printf("Entry point address:	0x%lx\n", (unsigned long)header->e_entry);
}

/**
 * main - Entry point
 *
 * @argc: Argument count
 * @argv: Argument values
 *
 * Return: 0 for success
 */

int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Unable to open file");
	if (read(fd, &header, sizeof(header)) != sizeof(header))
		print_error("Error: Unable to read ELF header");
	if (header.e_ident[0] != 0x7f || header.e_ident[1] != 'E' ||
	header.e_ident[2] != 'L' || header.e_ident[3] != 'F')
		print_error("Error: Not an ELF file");
	display_elf_header(&header);
	close(fd);
	return (0);
}

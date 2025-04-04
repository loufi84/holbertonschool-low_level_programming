#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
 * print_error - Prints an error message to stderr and exits.
 * @msg: The error message to print.
 */
void print_error(const char *msg)
{
	fprintf(stderr, "%s\n", msg);
	exit(98);
}

/**
 * validate_and_read_header - Reads and validates the ELF header.
 * @fd: The file descriptor of the ELF file.
 * @header: A pointer to the elf_header_t struct to store the header.
 *
 * Return: 0 on success, 98 on error.
 */
int validate_and_read_header(int fd, elf_header_t *header)
{
	unsigned char magic[4];
	ssize_t bytes_read;

	bytes_read = read(fd, magic, sizeof(magic));
	if (bytes_read == -1 || bytes_read < sizeof(magic))
	{
		fprintf(stderr, "Error: Cannot read file\n");
		return (98);
	}

	if (magic[EI_MAG0] != 0x7f || magic[EI_MAG1] != 'E' ||
		magic[EI_MAG2] != 'L' || magic[EI_MAG3] != 'F')
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		return (98);
	}

	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		fprintf(stderr, "Error: Cannot seek file\n");
		return (98);
	}

	bytes_read = read(fd, header, sizeof(elf_header_t));
	if (bytes_read == -1 || (size_t)bytes_read < sizeof(elf_header_t))
	{
		fprintf(stderr, "Error: Cannot read ELF header\n");
		return (98);
	}
	return (0);
}

/**
 * print_identification - Prints the ELF identification fields.
 * @e_ident: The e_ident array from the ELF header.
 */
void print_identification(unsigned char *e_ident)
{
	printf("Magic:");
	for (int i = 0; i < EI_NIDENT; i++)
		printf(" %02x", e_ident[i]);
	printf("\n");
	printf("  Class:                             %s\n",
		   (e_ident[EI_CLASS] == ELFCLASSNONE) ? "none" :
		   (e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" :
		   (e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "<unknown>");
	printf("  Data:                              %s\n",
		   (e_ident[EI_DATA] == ELFDATANONE) ? "none" :
		   (e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" :
		   (e_ident[EI_DATA] == ELFDATA2MSB) ?
			   "2's complement, big endian" :
			   "<unknown>");
	printf("  Version:                           %d%s\n", e_ident[EI_VERSION],
		   (e_ident[EI_VERSION] == EV_CURRENT) ? " (current)" :
		   (e_ident[EI_VERSION] == EV_NONE) ? " (invalid)" :
		   " <unknown>");
	printf("  OS/ABI:                            %s\n",
		   (e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" :
		   (e_ident[EI_OSABI] == ELFOSABI_HPUX) ? "HP-UX" :
		   (e_ident[EI_OSABI] == ELFOSABI_NETBSD) ? "NetBSD" :
		   (e_ident[EI_OSABI] == ELFOSABI_LINUX) ? "Linux" :
		   (e_ident[EI_OSABI] == ELFOSABI_SOLARIS) ? "Solaris" :
		   (e_ident[EI_OSABI] == ELFOSABI_IRIX) ? "IRIX" :
		   (e_ident[EI_OSABI] == ELFOSABI_FREEBSD) ? "FreeBSD" :
		   (e_ident[EI_OSABI] == ELFOSABI_TRU64) ? "Compaq TRU64 UNIX" :
		   (e_ident[EI_OSABI] == ELFOSABI_ARM) ? "ARM" :
		   (e_ident[EI_OSABI] == ELFOSABI_STANDALONE) ? "Standalone App" :
		   "<unknown>");
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_other_info - Prints the remaining ELF header information.
 * @header: A pointer to the elf_header_t struct.
 */
void print_other_info(elf_header_t *header)
{
	printf("  Type:                              %s\n",
		   (header->e_type == ET_NONE) ? "NONE (No file type)" :
		   (header->e_type == ET_REL) ? "REL (Relocatable file)" :
		   (header->e_type == ET_EXEC) ? "EXEC (Executable file)" :
		   (header->e_type == ET_DYN) ? "DYN (Shared object file)" :
		   (header->e_type == ET_CORE) ? "CORE (Core file)" :
		   "<unknown>");
	printf("  Entry point address:               ");
	if (header->e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)header->e_entry);
	else if (header->e_ident[EI_CLASS] == ELFCLASS64)
		printf("%#lx\n", header->e_entry);
	else
		printf("<unknown>\n");
}

/**
 * main - Displays the information contained in the ELF header.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	int fd;
	elf_header_t header;
	int result;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Cannot open file");

	result = validate_and_read_header(fd, &header);
	if (result == 98)
	{
		close(fd);
		return (98);
	}

	print_identification(header.e_ident);
	print_other_info(&header);

	if (close(fd) == -1)
		print_error("Error: Cannot close file");

	return (0);
}

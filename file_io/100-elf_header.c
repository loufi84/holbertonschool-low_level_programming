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
 * get_osabi_string - Returns the string representation of the ELF OS/ABI.
 * @osabi: The ELF OS/ABI byte.
 *
 * Return: A string representing the ELF OS/ABI.
 */
const char *get_osabi_string(unsigned char osabi)
{
	switch (osabi)
	{
		case ELFOSABI_SYSV: return ("UNIX - System V");
		case ELFOSABI_HPUX: return ("HP-UX");
		case ELFOSABI_NETBSD: return ("UNIX - NetBSD");
		case ELFOSABI_LINUX: return ("UNIX - Linux");
		case ELFOSABI_SOLARIS: return ("UNIX - Solaris");
		case ELFOSABI_IRIX: return ("UNIX - IRIX");
		case ELFOSABI_FREEBSD: return ("UNIX - FreeBSD");
		case ELFOSABI_TRU64: return ("Compaq TRU64 UNIX");
		case ELFOSABI_ARM: return ("ARM");
		case ELFOSABI_STANDALONE: return ("Standalone App");
		default: return ("<unknown>");
	}
}

/**
 * get_type_string - Returns the string representation of the ELF type.
 * @type: The ELF type value.
 *
 * Return: A string representing the ELF type.
 */
const char *get_type_string(uint16_t type)
{
	switch (type)
	{
		case ET_NONE: return ("NONE (No file type)");
		case ET_REL: return ("REL (Relocatable file)");
		case ET_EXEC: return ("EXEC (Executable file)");
		case ET_DYN: return ("DYN (Shared object file)");
		case ET_CORE: return ("CORE (Core file)");
		default: return ("<unknown>");
	}
}

/**
 * display_elf_header - Reads and displays the ELF header information.
 * @fd: The file descriptor of the ELF file.
 */
void display_elf_header(int fd)
{
	elf_header_t header;
	unsigned char magic[4];
	ssize_t bytes_read;
	int i;

	bytes_read = read(fd, magic, sizeof(magic));
	if (bytes_read == -1 || bytes_read < sizeof(magic))
		print_error("Error: Cannot read file");

	if (magic[EI_MAG0] != 0x7f || magic[EI_MAG1] != 'E' ||
		magic[EI_MAG2] != 'L' || magic[EI_MAG3] != 'F')
		print_error("Error: Not an ELF file");

	if (lseek(fd, 0, SEEK_SET) == -1)
		print_error("Error: Cannot seek file");

	bytes_read = read(fd, &header, sizeof(elf_header_t));
	if (bytes_read == -1 || (size_t)bytes_read < sizeof(elf_header_t))
		print_error("Error: Cannot read ELF header");

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", header.e_ident[i], (i == EI_NIDENT - 1) ? "" : " ");
	printf("\n");
	printf("  Class:                             %s\n",
		   (header.e_ident[EI_CLASS] == ELFCLASSNONE) ? "none" :
		   (header.e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" :
		   (header.e_ident[EI_CLASS] == ELFCLASS64) ? "ELF64" : "<unknown>");
	printf("  Data:                              %s\n",
		   (header.e_ident[EI_DATA] == ELFDATANONE) ? "none" :
		   (header.e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" :
		   (header.e_ident[EI_DATA] == ELFDATA2MSB) ? "2's complement, big endian" : "<unknown>");
	printf("  Version:                           %d (current)\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %s\n",
		   get_osabi_string(header.e_ident[EI_OSABI]));
	printf("  ABI Version:                       %d\n", header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              %s\n",
		   get_type_string(header.e_type));
	printf("  Entry point address:               ");
	if (header.e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)header.e_entry);
	else if (header.e_ident[EI_CLASS] == ELFCLASS64)
		printf("%#lx\n", header.e_entry);
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

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Cannot open file");

	display_elf_header(fd);

	if (close(fd) == -1)
		print_error("Error: Cannot close file");

	return (0);
}

#include "main.h"

/**
 * check_elf - Checks if a file is an ELF file and prints magic numbers
 * @e_ident: A pointer to an array containing the ELF magic numbers
 */
void check_elf(unsigned char *e_ident)
{
	int index;

	if (e_ident[EI_MAG0] != ELFMAG0 ||
		e_ident[EI_MAG1] != ELFMAG1 ||
		e_ident[EI_MAG2] != ELFMAG2 ||
		e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x", e_ident[index]);
		if (index < EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");

	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - Prints data encoding and version info
 * @e_ident: A pointer to an array containing the ELF class
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");
	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}

	printf("  Version:                           %d", e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Prints OS/ABI and ABI version info
 * @e_ident: A pointer to an array containing the ELF version
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");
	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_AIX:
		printf("UNIX - AIX\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}

	printf("  ABI Version:                       %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
 * print_type_entry - Prints type and entry point info
 * @e_type: The ELF type
 * @e_entry: The address of the ELF entry point
 * @e_ident: A pointer to an array containing the ELF class
 */
void print_type_entry(unsigned int e_type, unsigned long int e_entry,
		unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");
	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}

	printf("  Entry point address:               ");
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file
 * @argc: The number of arguments supplied to the program
 * @argv: An array of pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fd, read_result;

	if (argc != 2)
	{ dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{ dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		if (close(fd) == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		dprintf(STDERR_FILENO, "Error: Can't allocate memory\n");
		exit(98);
	}
	read_result = read(fd, header, sizeof(Elf64_Ehdr));
	if (read_result == -1)
	{
		free(header);
		if (close(fd) == -1)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	check_elf(header->e_ident);
	print_data(header->e_ident);
	print_osabi(header->e_ident);
	print_type_entry(header->e_type, header->e_entry, header->e_ident);
	free(header);
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(98);
	}
	return (0);
}

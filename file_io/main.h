#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
void print_error(const char *msg);
void display_elf_header(int fd);
const char *get_osabi_string(unsigned char osabi);
const char *get_type_string(uint16_t type);

/**
 * struct elf_header - Represents the ELF header structure.
 *
 * @e_ident: An array of bytes marking the file as an ELF file
 * and providing machine-independent data.
 * - e_ident[EI_MAG0]: Magic number (0x7F).
 * - e_ident[EI_MAG1]: Magic number ('E').
 * - e_ident[EI_MAG2]: Magic number ('L').
 * - e_ident[EI_MAG3]: Magic number ('F').
 * - e_ident[EI_CLASS]: Class of the architecture (e.g., ELFCLASS32,
 *   ELFCLASS64).
 * - e_ident[EI_DATA]: Data encoding of the object file.
 * - e_ident[EI_VERSION]: Version number of the ELF specification.
 * - e_ident[EI_OSABI]: Operating system and ABI identification.
 * - e_ident[EI_ABIVERSION]: ABI version.
 * - e_ident[EI_PAD]: Starts padding bytes.
 * - e_ident[EI_NIDENT]: Size of e_ident array.
 * @e_type: Object file type (e.g., ET_REL, ET_EXEC, ET_DYN).
 * @e_machine: Machine architecture (e.g., EM_X86_64).
 * @e_version: Object file version (must be EV_CURRENT).
 * @e_entry: Virtual address of the entry point for executable files.
 * @e_phoff: Program header table's file offset in bytes.
 * @e_shoff: Section header table's file offset in bytes.
 * @e_flags: Processor-specific flags.
 * @e_ehsize: ELF header's size in bytes.
 * @e_phentsize: Size in bytes of one entry in the program header table.
 * @e_phnum: Number of entries in the program header table.
 * @e_shentsize: Size in bytes of one entry in the section header table.
 * @e_shnum: Number of entries in the section header table.
 * @e_shstrndx: Section header table index of the section containing
 * section names.
 *
 * Description: This structure defines the layout of the ELF header, which is
 * present at the beginning of every ELF file. It contains essential
 * information about the file's organization and content, allowing the
 * system to interpret and execute or link the file correctly.
 */

typedef struct elf_header
{
	unsigned char e_ident[EI_NIDENT];
	uint16_t e_type;
	uint16_t e_machine;
	uint32_t e_version;
	uintptr_t e_entry;
	uintptr_t e_phoff;
	uintptr_t e_shoff;
	uint32_t e_flags;
	uint16_t e_ehsize;
	uint16_t e_phentsize;
	uint16_t e_phnum;
	uint16_t e_shentsize;
	uint16_t e_shnum;
	uint16_t e_shstrndx;
} elf_header_t;


#endif /* MAIN_H */

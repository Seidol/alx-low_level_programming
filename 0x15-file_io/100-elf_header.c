#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * main - function
 * print_elf_info - Displays information from the ELF header.
 * @filename: The name of the ELF file to read.
 */
void print_elf_info(const char *filename);

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	const char *filename = argv[1];

	print_elf_info(filename);

	return (0);
}
/**
 * print_elf_info - function
 * @filename - fine name
 */
void print_elf_info(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		perror("Error opening file");
		exit(98);
	}

	Elf64_Ehdr elf_header;

	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		perror("Error reading ELF header");
		close(fd);
		exit(98);
	}

	/* Check if it's an ELF file */
	if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0)
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		close(fd);
		exit(98);
	}

	printf("Magic: ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", elf_header.e_ident[i]);
	printf("\n");

	printf("Class: %s\n",
elf_header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
	printf("Data: %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ?
"2's complement, little endian" : "2's complement, big endian");
	printf("Version: %d (current)\n", elf_header.e_ident[EI_VERSION]);
	printf("OS/ABI: %s\n", elf_header.e_ident[EI_OSABI] == ELFOSABI_NONE ?
"UNIX - System V" : "Other");
	printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);

	switch (elf_header.e_type)
	{
	case ET_NONE:
		printf("Type: NONE (None)\n");
		break;
	case ET_REL:
		printf("Type: REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("Type: EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("Type: DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("Type: CORE (Core file)\n");
		break;
	default:
		printf("Type: <unknown: %x>\n", elf_header.e_type);
	}

	printf("Entry point address: %#lx\n", (unsigned long)elf_header.e_entry);

	close(fd);
}

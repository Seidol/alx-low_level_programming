#include "elf_header.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * main - Displays the information contained in the ELF header at
 * the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exits with code 98 if the file is not
 * an ELF File or the function fails.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int elf_file_descriptor, read_result;

	elf_file_descriptor = open(argv[1], O_RDONLY);
	if (elf_file_descriptor == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		closeElfFile(elf_file_descriptor);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	read_result = read(elf_file_descriptor, header, sizeof(Elf64_Ehdr));
	if (read_result == -1)
	{
		free(header);
		closeElfFile(elf_file_descriptor);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	verifyElfFile(header->e_ident);
	printf("ELF Header:\n");
	printMagicNumbers(header->e_ident);
	printClass(header->e_ident);
	printDataEncoding(header->e_ident);
	printVersion(header->e_ident);
	printOSABI(header->e_ident);
	printABI(header->e_ident);
	printFileType(header->e_type, header->e_ident);
	printEntryPoint(header->e_entry, header->e_ident);

	free(header);
	closeElfFile(elf_file_descriptor);
	return (0);
}

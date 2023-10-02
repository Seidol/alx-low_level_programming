#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * display_elf_info - Displays information from the ELF header.
 * @fd: File descriptor of the ELF file.
 */
void display_elf_info(int fd);

/**
 * close_fd - Closes a file descriptor.
 * @fd: File descriptor to close.
 */
void close_fd(int fd);

/**
 * print_error - Prints an error message to stderr.
 * @message: The error message.
 */
void print_error(char *message);

/**
 * main - Entry point of the program.
 * @argc: The argument count.
 * @argv: An array of pointers to the program's arguments.
 *
 * Return: 0 on success, or exit with code 98 if there's an error.
 *
 * Description: This function checks if the correct number of arg is provided
 * If not, it prints a usage message to stderr and returns with exit code 98
 * It then attempts to open the specified ELF file,handling any potential err
 * If successful,it calls a function to display the ELF header information, and
 * then closes the file descriptor.Finally, it returns 0 to indicate successful
 * execution of the program.
 */

int main(int argc, char *argv[])
{
	int fd;
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		perror("Error");
		return (98);
	}

	display_elf_info(fd);
	close_fd(fd);

	return (0);
}
/**
 * display_elf_info - Displays information from the ELF header of an open file.
 * @fd: The file descriptor of the open ELF file.
 *
 * Description: This func reads and interprets the ELF header from the provided
 * file descriptor. It then prnts various pieces of info about the ELF file
 * such as magic numbers, class, data encoding,version,OS/ABI,ABI version,type
 * and entry point address, following the format of the 'readelf -h' command.
 * If an error occurs during reading or printing,it will print an error message
 * to stderr and exit with code 98.
 */

void display_elf_info(int fd)
{
	Elf64_Ehdr header;
	ssize_t bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));
	int i;

	if (bytes_read != sizeof(Elf64_Ehdr) || memcmp(header.e_ident,
		ELFMAG, SELFMAG) != 0)
	{
		print_error("Not an ELF file");
		exit(98);
	}

	printf("ELF Header:\n");
	printf("	Magic:	");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", header.e_ident[i]);
		if (i < EI_NIDENT - 1)
		{
			printf(" ");
		}
		else
		{
			printf("\n");
		}
	}

	printf("Class: ");
	switch (header.e_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", header.e_ident[EI_CLASS]);
	}

	printf("Data:");
	switch (header.e_ident[EI_DATA])
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
		printf("<unknown: %x>\n", header.e_ident[EI_DATA]);
	}

	printf("	Version:			%d", header.e_ident[EI_VERSION]);
	if (header.e_ident[EI_VERSION] == EV_CURRENT)
	{
		printf(" (current)\n");
	}
	else
	{
		printf("\n");
	}

	printf("	OS/ABI:				");
	switch (header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
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
		case ELFOSABI_ARM:
		printf("ARM\n");
		break;
		case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
		default:
		printf("<unknown: %x>\n", header.e_ident[EI_OSABI]);
	}

	printf("	ABI Version:		%d\n", header.e_ident[EI_ABIVERSION]);

	printf("	Type:				");
	switch (header.e_type)
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
		printf("<unknown: %x>\n", header.e_type);
	}

	printf("	Entry point address:		%#lx\n", (unsigned long)header.e_entry);
}
/**
 * close_fd - Closes a file descriptor and handles errors.
 * @fd: The file descriptor to be closed.
 *
 * Description: This function takes a file descriptor as input and attempts to
 * close it. If an error occurs during the close operation, it prints an error
 * message to stderr and exits the program with status code 98.
 */

void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		perror("Error");
		exit(98);
	}
}
/**
 * print_error - Prints an error message to stderr.
 * @message: The error message to be printed.
 *
 * Description: This function takes an error message as input and prints it to
 * the standard error stream (stderr) with a newline character. It is used to
 * display error messages during the execution of the program.
 */

void print_error(char *message)
{
	fprintf(stderr, "Error: %s\n", message);
}

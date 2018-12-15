#include "libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

# define GNL_LAST_ALLOC 0

void	read_file(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	while (ft_gnl(fd, &line, "\n") > 0)
	{
		ft_printf("Adress = %p Line = %s\n", line, line);
		ft_strdel(&line);
	}
	if (GNL_LAST_ALLOC)
		ft_strdel(&line);
	ft_printf("Adress = %p Line = %s\n", line, line);
	if (0 && line != NULL)
		ft_printf("Error.");
	close(fd);
}

int		test1(int ac, char **argv)
{
	int		idx;

	if (ac != 4)
		return (-1);
	idx = 1;
	while (idx < ac)
	{
		read_file(argv[idx]);
		idx++;
	}
	while (ac) ;
	return (0);
}

int		main(int ac, char **argv)
{
	test1(ac, argv);
	return(0);
}

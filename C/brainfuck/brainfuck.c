# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# define BUFFER 8

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_mem(char *str,int index)
{
	index = 0;
	while(index <= BUFFER)
		ft_putchar(str[index++]);
}

int ft_match_close(char *str, int index)
{
	int bracket;

	bracket = 0;
	while (str[index] != ']' || bracket)
	{
		index++;
		if (str[index] == '[')
			bracket++;
		else if (str[index] == ']' && bracket > 0)
			bracket--;
	}
	return (index);
}

int ft_match_open(char *str, int index)
{
	int bracket;

	bracket = 0;
	while (str[index--] != '[' || bracket)
	{
		if (str[index] == ']')
			bracket++;
		else if (str[index] == '[' && bracket > 0)
			bracket--;
	}
	return (index);
}

void basicfuck(char *str)
{	
	char *memory;
	int pos;
	int index;

	if (!(memory = malloc(sizeof(char) * BUFFER + 1)))
		return ;
	pos = BUFFER + 1;
	while(--pos)
		memory[pos] = 48;
	pos = 0;
	index = 0;
	while(str[index])
	{
		// printf("\tindex:%i \tstr[index]:%c \tpos:%i\tbyte:%i \n", index, str[index], pos, memory[pos]);
		if (str[index] == '>')
			pos++;
		else if (str[index] == '<')
			pos--;
		else if (str[index] == '+')
			memory[pos]++;
		else if (str[index] == '-')
			memory[pos]--;
		else if (str[index] == '.')
			ft_putchar(memory[pos]);
		else if (str[index] == '[' && memory[pos] == 48)
		 {
		 	printf("%i\n", ft_match_close(str, index - 1));
		 	index = ft_match_close(str, index - 1);
		 }
		else if (str[index] == ']' && memory[pos] != 48)
			index = ft_match_open(str, index + 1);
		index++;
	}
	free(memory);
}


int main (int ac, char **av)
{
	if (ac == 2)
		basicfuck(av[1]);
	ft_putchar('\n');
	return (ac);
}

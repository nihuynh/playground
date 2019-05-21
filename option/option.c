#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

typedef struct	s_opt_func t_opt_func;
typedef struct	s_option t_option;

struct			s_option
{
	int			argc;
	char		**argv;
	void		*link_prg;
	int			flag_found;
	t_opt_func	funct[128];
	int			(*set_func) (t_option*, char, char*, void *(*func) (void*));
	int			(*do_) (char*, t_option);
};

struct			s_opt_func
{
	bool		in_argv;
	short		idx_argv;
	char		*name;
	void		*(*func) (void*);

};

void	option_do_if(char key, char *func_name, t_option *self)
{
	// check if key is valid
	t_opt_func	*func_wanted;
	// check if func is set

	func_wanted = self->funct[key].func;
	if (func_wanted != NULL)
		func_wanted()
	self->funct[key].name = func_name;
	// Stuff
	// return (0);
}

void	option_set_func(t_option *self, char key, char *func_name, void *(*func) (t_option*, void*))
{
	// check if key is valid
	self->funct[key].func = func;
	self->funct[key].name = func_name;
}

void	parse_options(t_option *self, int argc, char *argv[], void *link_prg)
{
	bzero(self, sizeof(t_option));
	self->argc = argc;
	self->argv = argv;
	self->link_prg = link_prg;
	self->flag_found = 0;
}


void	*debug_leaks(t_option *option, t_opt_func *self)
{
	while ((self->in_argv))
		;
	return (NULL);
}

void	*set_height(t_option *option, t_opt_func *self)
{
	int *env;

	if (self->in_argv)
	{
		env = option->link_prg;
		*env = atoi(option->argv[self->idx_argv + 1]);
		printf("found in height in the argv set at %d\n", *env);
	}
	return (NULL);
}

int		main(int ac, char *av[])
{
	t_option	option;
	int			env;

	env = 0;
	parse_options(&option, ac, av, &env);
	option_set_func(&option, 'l', "debug_leaks", &debug_leaks);
	option_set_func(&option, 'h', "set_height", &set_height);
	option_do_if('h', "set_height", &option);
	printf("found in height in the argv set at %d\n", env);
	option_do_if('l', "debug_leaks", &option);
    return (0);
}
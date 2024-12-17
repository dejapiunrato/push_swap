#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

// check_input_utils.c
int			is_digit(char c);
int			is_sign(char c);
int			cmp_nbr(char *n1, char *n2);
int			is_zero(char *s);
int			is_num(char *s);

// check_input.c
int			is_dup(char **input);
void		exit_error(t_stack **stack_a, t_stack **stack_b);
int			check_input(char **input);

// utils_1.c
long int	ft_atoi(char *s);
int			ft_strlen(char *s);

// stack.c
void		free_stack(t_stack **stack);
t_stack 	*new_node(int value);
t_stack		*get_last_node(t_stack **stack);
void		add_node_end(t_stack **stack, t_stack *new);

// inizialization.c
t_stack		*start_stack(char **argv);
int			add_index(t_stack *stack);

#endif

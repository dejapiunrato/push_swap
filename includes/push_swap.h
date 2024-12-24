#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	unsigned int	index;
	char			*bin;
	struct s_stack	*next;
}	t_stack;

// check_input_utils.c
int				is_digit(char c);
int				is_sign(char c);
int				cmp_nbr(char *n1, char *n2);
int				is_zero(char *s);
int				is_num(char *s);

// check_input.c
int				is_dup(char **input);
void			exit_error(t_stack **stack_a, t_stack **stack_b);
int				check_input(char **input);

// utils_1.c
long int		ft_atoi(char *s);
void			ft_putstr(char *s);
int				ft_strlen(char *s);

// utils_2.c
int				get_max_index(t_stack **stack);

// stack.c
void			free_stack(t_stack **stack);
t_stack			*new_node(int value);
t_stack			*get_last_node(t_stack **stack);
void			add_node_end(t_stack **stack, t_stack *new);

// inizialization.c
t_stack			*start_stack(char **argv);
int				add_index(t_stack *stack, int size);

// swap.c
void			swap_a(t_stack **stack);
void			swap_b(t_stack **stack);
void			swap_ab(t_stack **stack_a, t_stack **stack_b);

// push.c
void			push_a(t_stack **stack_a, t_stack **stack_b);
void			push_b(t_stack **stack_a, t_stack **stack_b);

// rotate.c
void			rotate_a(t_stack **stack);
void			rotate_b(t_stack **stack);
void			rotate_ab(t_stack **stack_a, t_stack **stack_b);

// reverse_rotate.c
void			reverse_rotate_a(t_stack **stack);
void			reverse_rotate_b(t_stack **stack);
void			reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

// sort_simple.c
void			sort_2(t_stack **stack);
void			sort_3(t_stack **stack);
void			sort_4(t_stack **stack_a, t_stack **stack_b);

// sort_simple_utils.c
unsigned int	*check_order_return_max(t_stack **stack, unsigned int size);
unsigned int	*check_order_return_min(t_stack **stack, unsigned int size);

void	rotate(t_stack	**stack);
char	*ft_strjoin(char const *s1, char const *s2);

#endif

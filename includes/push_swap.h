#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

// Estructuras
typedef struct s_stack
{
	int				value;
	unsigned int	index;
	char			*bin;
	struct s_stack	*next;
}	t_stack;

typedef struct s_size
{
	int		size;
	int		size_a;
	int		size_b;
	int		bin_pos;
}	t_size;

// Funciones de check_input_utils.c
int		is_digit(char c);
int		is_sign(char c);
int		cmp_nbr(char *n1, char *n2);
int		is_zero(char *s);
int		is_num(char *s);

// Funciones de check_input.c
int		is_dup(char **input);
void	exit_error(t_stack **stack_a, t_stack **stack_b);
int		check_input(char **input);
int		check_order(t_stack **stack);

// Funciones de inizialization.c
t_stack	*start_stack(char **argv);
void	add_index(t_stack *stack, int bin_len);
t_size	*start_size(int argc);
int		bin_len(int size);

// Funciones de instructions.c
void	push(t_stack **src, t_stack **dest);
void	reverse_rotate(t_stack **stack);
void	rotate(t_stack **stack);
void	swap(t_stack **stack);

/* // Funciones de radix_sort.c
char	*push_b(t_stack **s_a, t_stack **s_b, t_size *size, char *sol);
char	*push_a(t_stack **s_a, t_stack **s_b, t_size *size, char *sol);
char	*radix_sort(t_stack **s_a, t_stack **s_b, t_size *size, char *sol); */

// Funciones de sort_simple.c
char	*s_2(t_stack **s, char *sol);
char	*s_3(t_stack **s_a, t_size *size, char *sol);
char	*s_4(t_stack **s_a, t_stack **s_b, t_size *size, char *sol);
char	*s_5(t_stack **s_a, t_stack **s_b, t_size *size, char *sol);

// Funciones de sort_utils.c.c
char	*optim_rotation_a(t_size *size, int i, char *sol);
char	*optim_rotation_b(t_size *size, int i, char *sol);
char	*add_moves(char *sol, char *moves, int i);

// Funciones de sort.c
char	*sort(t_stack **s_a, t_stack **s_b, t_size *size, char *sol);

// Funciones de stack.c
void	free_stack(t_stack **stack);
t_stack	*new_node(int value);
t_stack	*get_last_node(t_stack **stack);
void	add_node_end(t_stack **stack, t_stack *new);

// Funciones de str_utils.c
long int	ft_atoi(char *s);
void	ft_putstr(char *s);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);

#endif

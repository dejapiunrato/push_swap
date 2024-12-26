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
int				is_digit(char c);
int				is_sign(char c);
int				cmp_nbr(char *n1, char *n2);
int				is_zero(char *s);
int				is_num(char *s);

// Funciones de check_input.c
int				is_dup(char **input);
void			exit_error(t_stack **stack_a, t_stack **stack_b);
int				check_input(char **input);

// Funciones de str_utils.c
long int		ft_atoi(char *s);
void			ft_putstr(char *s);
int				ft_strlen(char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(char *s);

// Funciones de utils_2.c
int				get_max_index(t_stack **stack);

// Funciones de stack.c
void			free_stack(t_stack **stack);
t_stack			*new_node(int value);
t_stack			*get_last_node(t_stack **stack);
void			add_node_end(t_stack **stack, t_stack *new);

// Funciones de inizialization.c
t_stack			*start_stack(char **argv);
void			add_index(t_stack *stack, int bin_len);
t_size			*start_size(int argc);
int				bin_len(int size);

// Funciones de instructions.c
void			push(t_stack **src, t_stack **dest);
void			reverse_rotate(t_stack **stack);
void			rotate(t_stack **stack);
void			swap(t_stack **stack);

// Funciones de sort_simple.c
void			sort_2(t_stack **stack);
void			sort_3(t_stack **stack);
void			sort_4(t_stack **stack_a, t_stack **stack_b);

// Funciones de sort_simple_utils.c
unsigned int	*check_order_return_max(t_stack **stack, unsigned int size);
unsigned int	*check_order_return_min(t_stack **stack, unsigned int size);

// Funciones de radix_sort.c
char			*optim_rotation_a(t_size *size, int i, char *solution);
char			*add_moves(char *solution, char *moves, int i);
char			*move_to_b(t_stack **stack_a, t_stack **stack_b, t_size *size, char *solution);
char			*radix_sort(t_stack **stack_a, t_stack **stack_b, t_size *size);

#endif

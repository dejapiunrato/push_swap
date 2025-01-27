/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psevilla <psevilla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:43:55 by psevilla          #+#    #+#             */
/*   Updated: 2025/01/27 17:44:03 by psevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_replacement
{
	char	*old_sub;
	char	*new_sub;
}	t_replacement;

// Funciones de check_input_utils.c
int			is_digit(char c);
int			is_sign(char c);
int			cmp_nbr(char *n1, char *n2);
int			is_zero(char *s);
int			is_num(char *s);

// Funciones de check_input.c
void		exit_error(t_stack **stack_a, t_stack **stack_b);
int			check_input(char **input);
int			check_order(t_stack **stack);

// Funciones de inizialization.c
t_stack		*start_stack(char **argv);
t_size		*start_size(int argc);
void		add_index(t_stack *stack, int bin_len);

// Funciones de instructions.c
void		push(t_stack **src, t_stack **dest, t_size *size, char stack);
void		reverse_rotate(t_stack **stack);
void		rotate(t_stack **stack);
void		swap(t_stack **stack);

// Funciones de optimization.c
char		*optimization(char *sol);

// Funciones de sort_simple.c
char		*s_2(t_stack **s, char *sol);
char		*s_3(t_stack **s_a, t_size *size, char *sol);
char		*s_4(t_stack **s_a, t_stack **s_b, t_size *size, char *sol);
char		*s_5(t_stack **s_a, t_stack **s_b, t_size *size, char *sol);

// Funciones de sort_utils_1.c.c
char		*optim_rotation_a(t_size *size, int i, char *sol);
char		*optim_rotation_b(t_size *size, int i, char *sol);
char		*add_moves(char *sol, char *moves, int i);
int			find_min_a(t_stack **s_a, t_size *size);
int			find_max_a(t_stack **s_a);

// Funciones de sort_utils_2.c
int			find_first(t_stack **s_a, t_size *size, unsigned int block);
int			find_last(t_stack **s_a, t_size *size, unsigned int block);

// Funciones de sort.c
char		*sort(t_stack **s_a, t_stack **s_b, t_size *size, char *sol);

// Funciones de stack.c
t_stack		*new_node(int value);
void		free_stack(t_stack **stack);
t_stack		*get_last_node(t_stack **stack);
void		add_node_end(t_stack **stack, t_stack *new);

// Funciones de str_utils_1.c
long int	ft_atoi(char *s);
void		ft_putstr(char *s);
int			ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s);

// Funciones de str_utils_2.c
char		*ft_strstr(const char *s1, const char *s2);
char		*ft_strcpy(char *s1, char *s2);
char		*ft_strncpy(char *dest, char *src, int n);

#endif

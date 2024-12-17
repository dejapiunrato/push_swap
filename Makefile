# Variables
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes
SRCS_DIR = sources
OBJS_DIR = objects
SRCS = $(SRCS_DIR)/main.c $(SRCS_DIR)/inizialization.c $(SRCS_DIR)/check_input.c $(SRCS_DIR)/check_input_utils.c $(SRCS_DIR)/utils_1.c $(SRCS_DIR)/stack.c $(SRCS_DIR)/swap.c $(SRCS_DIR)/push.c $(SRCS_DIR)/rotate.c
OBJS = $(OBJS_DIR)/main.o $(OBJS_DIR)/inizialization.o $(OBJS_DIR)/check_input.o $(OBJS_DIR)/check_input_utils.o $(OBJS_DIR)/utils_1.o $(OBJS_DIR)/stack.o $(OBJS_DIR)/swap.o $(OBJS_DIR)/push.o $(OBJS_DIR)/rotate.o
RM = rm -f

# Regla principal
all: $(NAME)

# Regla para compilar el ejecutable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Regla para compilar los archivos .c en archivos .o
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Crear el directorio de objetos si no existe
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

# Regla para limpiar los archivos objeto
clean:
	$(RM) $(OBJS)

# Regla para limpiar los archivos objeto y el ejecutable
fclean: clean
	$(RM) $(NAME)

# Regla para recompilar todo
re: fclean all

# Regla para evitar errores con nombres de archivos que coincidan con las reglas
.PHONY: all clean fclean re

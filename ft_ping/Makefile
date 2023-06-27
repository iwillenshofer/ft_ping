# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwillens <iwillens@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 15:22:29 by iwillens          #+#    #+#              #
#    Updated: 2023/06/15 10:01:50 by iwillens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# *** Main Definitions                                                         #
# **************************************************************************** #

NAME = ft_ping

CC = gcc
CCFLAGS = -Wall -Werror -Wextra

SRC_DIR = ./srcs
OBJ_DIR = ./build
INC_DIR = ./includes
INCLUDES = ${INC_DIR}/ft_ping.h

SRCS = ${SRC_DIR}/main.c \
		${SRC_DIR}/debug_tools.c

OBJS = $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRCS})

DEPENDS = $(patsubst %.o, %.d, ${OBJS})

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
HOST_PREFIX = .host_
HOST_FILE = ${OBJ_DIR}/${HOST_PREFIX}${HOSTTYPE}

# **************************************************************************** #
# *** Libft Definitions                                                        #
# **************************************************************************** #
LIBFT_DIR = ./srcs/libft
LIBFT = ${LIBFT_DIR}/libft.a

# **************************************************************************** #
# *** Main Rules                                                               #
# **************************************************************************** #

all: ${NAME}

${NAME}: ${HOST_FILE} ${LIBFT} ${OBJS} ${INCLUDES} Makefile 
	@gcc ${CCFLAGS} ${OBJS}  -L./srcs/libft -lft -o ${NAME}
	@rm -f ${SYMLINK}
	@echo "\033[96m${NAME} is built. \033[0m"
	
${OBJ_DIR}/%.o: $(SRC_DIR)/%.c ${INC_DIR} ${INCLUDES} Makefile
	@mkdir -p ${OBJ_DIR}
	@${CC} ${CCFLAGS} -MMD -c $< -I. -I ${INC_DIR} -I ${LIBFT_DIR} -o $@

run: all
	./${NAME}

${LIBFT}:
	@make -s -C ${LIBFT_DIR}


# **************************************************************************** #
# *** HOSTFILE Rules. Forces remake when the host type file changes            #
# **************************************************************************** #

${HOST_FILE}:
	@make -s fclean
	@mkdir -p ${OBJ_DIR}
	@touch ${HOST_FILE}

# **************************************************************************** #
# *** Common Rules                                                             #
# **************************************************************************** #
clean:
	@rm -rf ${OBJ_DIR}
	@make  -s -C ${LIBFT_DIR} clean

fclean: clean
	@rm -rf ./${NAME}
	@make  -s -C ${LIBFT_DIR} fclean

re: fclean all

-include $(DEPENDS)

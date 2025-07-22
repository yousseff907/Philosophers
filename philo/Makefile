# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yitani <yitani@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/20 17:44:10 by yitani            #+#    #+#              #
#    Updated: 2025/07/22 19:16:48 by yitani           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = philo

CC        = cc

CFLAGS    = -Wall -Wextra -Werror -pthread

GENERAL_HELPERS_SRCS = src/general_helpers/ft_atoi.c \
                       src/general_helpers/get_current_time.c

PARSING_SRCS = src/parsing/arguments_validation.c \
               src/parsing/mem_thr_mut_alloc.c

PHILOS_ROUTINE_SRCS = 	src/philos_routine/philosophers_routine.c \
						src/philos_routine/routine_helpers.c \
						src/philos_routine/simulation_helpers.c \
						src/philos_routine/simulation_monitoring.c

CLEANUP_EXIT_SRCS = src/cleanup_exit/cleanup_and_return.c

MAIN_SRCS = philo.c

SRC = $(GENERAL_HELPERS_SRCS) \
      $(PARSING_SRCS) \
      $(PHILOS_ROUTINE_SRCS) \
      $(CLEANUP_EXIT_SRCS) \
      $(MAIN_SRCS)

HDR = philo.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "┌────────────────────────────────┐"
	@echo "│   🧠  Building philosophers... │"
	@echo "└────────────────────────────────┘"
	@$(CC) $(CFLAGS) -o $@ $(OBJ)
	@echo "✅  Build complete! The philosophers are ready to think."

%.o: %.c $(HDR)
	@echo "[🛠️ ] Compiling $<…"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "[✔️ ] Created $@"

clean:
	@echo "[🧹] Cleaning object files…"
	@rm -f $(OBJ)
	@echo "[✔️ ] Objects removed."

fclean: clean
	@echo "[💣] Nuking philosophers"
	@rm -f $(NAME)
	@echo "[✔️ ] the philosophers have been nuked."

re: fclean all

norminette:
	@echo "🔍 Running Norminette on all files…"
	@norminette $(SRC) $(HDR)

.PHONY: all clean fclean re norminette
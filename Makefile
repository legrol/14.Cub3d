# ══ Names ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

NAME 				= cub3D

# ══ Colors ══════════════════════════════════════════════════════════════════ #
#    ------                                                                    #

DEL_LINE 			= \033[2K
ITALIC 				= \033[3m
BOLD 				= \033[1m
DEF_COLOR 			= \033[0;39m
GRAY 				= \033[0;90m
RED 				= \033[0;91m
GREEN 				= \033[0;92m
YELLOW 				= \033[0;93m
BLUE 				= \033[0;94m
MAGENTA 			= \033[0;95m
CYAN 				= \033[0;96m
WHITE 				= \033[0;97m
BLACK 				= \033[0;99m
ORANGE 				= \033[38;5;209m
BROWN 				= \033[38;2;184;143;29m
DARK_GRAY 			= \033[38;5;234m
MID_GRAY 			= \033[38;5;245m
DARK_GREEN 			= \033[38;2;75;179;82m
DARK_YELLOW 		= \033[38;5;143m

# ══ Compilation══════════════════════════════════════════════════════════════ #
#    -----------                                                               #

CC 					= clang
AR 					= ar rcs
RM 					= rm -f
MK 					= make -C -g
MKD					= mkdir -p
MCL 				= make clean -C
MFCL 				= make fclean -C
MK_					= && make

# ══ Directories ═════════════════════════════════════════════════════════════ #
#    -----------                                                               #

CONTROL_DIR			= ./control
ERRORS_DIR			= ./errors
IMAGES_DIR			= ./imgs
# EXEC_DIR			= ./exec
# FREE_DIR			= ./free
INIT_DIR			= ./init
LIBRARIES			= ./libs
OBJ_DIR				= ./obj
SRC_DIR				= ./src
VERIFY_DIR			= ./verify
UTILS_DIR			= ./utils
# PARSER_DIR			= ./parser
LIBFT_DIR			= libft
PRINTFT_DIR			= printf
EXAMFT_DIR			= examft
GNL_DIR				= gnl
INCLUDES_DIR		= ./includes

# ══ Directories Bonus ═══════════════════════════════════════════════════════ #
#    -----------                                                               #


# ══ Library Archives ════════════════════════════════════════════════════════ #
#    ----------------                                                          #

LIBFT_A				= ${LIBRARIES}/${LIBFT_DIR}/libft.a
PRINTFT_A			= ${LIBRARIES}/${PRINTFT_DIR}/libftprintf.a
EXAMFT_A			= ${LIBRARIES}/${EXAMFT_DIR}/libexamft.a

# ══ Flags ═══════════════════════════════════════════════════════════════════ #
#    -----                                                                     #

CFLAGS 				= -Wall -Werror -Wextra
IFLAGS				= -I${INCLUDES_DIR}
LFLAGS				= -L${LIBRARIES}/${LIBFT_DIR} -lft \
						-L${LIBRARIES}/${PRINTFT_DIR} -lftprintf \
						-L${LIBRARIES}/${EXAMFT_DIR} -lexamft -lreadline				

# ══ Flags Bonus══════════════════════════════════════════════════════════════ #
#    -----------                                                               #

# IFLAGS_BONUS		= -I${INCLUDES_BONUS_DIR}

# ══ Sources ═════════════════════════════════════════════════════════════════ #
#    -------                                                                   #

SRC 				= ${SRC_DIR}/cub3D.c

GNL					= ${LIBRARIES}/${GNL_DIR}/get_next_line.c \
						${LIBRARIES}/${GNL_DIR}/get_next_line_utils.c \
						${LIBRARIES}/${GNL_DIR}/get_next_line_bonus.c \
						${LIBRARIES}/${GNL_DIR}/get_next_line_utils_bonus.c

ERR					= ${ERRORS_DIR}/ft_manage_err.c

INT					= ${INIT_DIR}/ft_init_struct.c

UTL					= ${UTILS_DIR}/ft_count_col.c

CTRL				= ${CONTROL_DIR}/ft_control_args.c \
						${CONTROL_DIR}/ft_ext_valid.c

VRF					= ${VERIFY_DIR}/ft_verify_enclosure.c \
						${VERIFY_DIR}/ft_verify_lines.c \
						${VERIFY_DIR}/ft_verify_maps.c \
						${VERIFY_DIR}/ft_verify_spaces.c

# FRE					= ${FREE_DIR}/xxxx.c

# PAR					= ${PARSER_DIR}/xxx.c

# EXE					= ${EXEC_DIR}/xxxx.c

OBJ_SRC				= $(patsubst ${SRC_DIR}/%.c, ${OBJ_DIR}/%.o, ${SRC})
OBJ_GNL				= $(patsubst ${LIBRARIES}/${GNL_DIR}/%.c, ${OBJ_DIR}/%.o, \
						${GNL})
OBJ_ERR				= $(patsubst ${ERRORS_DIR}/%.c, ${OBJ_DIR}/%.o, ${ERR})
OBJ_INT				= $(patsubst ${INIT_DIR}/%.c, ${OBJ_DIR}/%.o, ${INT})
OBJ_UTL				= $(patsubst ${UTILS_DIR}/%.c, ${OBJ_DIR}/%.o, ${UTL})
OBJ_CTRL			= $(patsubst ${CONTROL_DIR}/%.c, ${OBJ_DIR}/%.o, ${CTRL})
OBJ_VRF				= $(patsubst ${VERIFY_DIR}/%.c, ${OBJ_DIR}/%.o, ${VRF})
# OBJ_FRE				= $(patsubst ${FREE_DIR}/%.c, ${OBJ_DIR}/%.o, ${FRE})
# OBJ_PAR				= $(patsubst ${PARSER_DIR}/%.c, ${OBJ_DIR}/%.o, ${PAR})
# OBJ_EXE				= $(patsubst ${EXEC_DIR}/%.c, ${OBJ_DIR}/%.o, ${EXE})

# ═══ Rules ══════════════════════════════════════════════════════════════════ #
#     -----                                                                    #

all: ${NAME}

${NAME}: ftlibft ftprintf ftexamft  ${OBJ_SRC} ${OBJ_GNL} \
									${OBJ_ERR} ${OBJ_INT} ${OBJ_UTL} \
									${OBJ_CTRL} ${OBJ_VRF} ${OBJ_FRE} \
									${OBJ_PAR}
	@echo "$(YELLOW)Compiling root ...$(DEF_COLOR)"
	@${CC} ${CFLAGS} ${IFLAGS} -o ${NAME} ${OBJ_SRC} ${OBJ_GNL} ${OBJ_ERR} \
									${OBJ_INT} ${OBJ_UTL} ${OBJ_FRE} \
									${OBJ_CTRL} ${OBJ_VRF} ${OBJ_PAR} ${LFLAGS}
	@echo "$(GREEN) $(NAME) all created ✓$(DEF_COLOR)"

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${LIBRARIES}/${GNL_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${ERRORS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${INIT_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${UTILS_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${CONTROL_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

${OBJ_DIR}/%.o: ${VERIFY_DIR}/%.c
	@${MKD} $(dir $@)
	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

# ${OBJ_DIR}/%.o: ${FREE_DIR}/%.c
# 	@${MKD} $(dir $@)
# 	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

# ${OBJ_DIR}/%.o: ${PARSER_DIR}/%.c
# 	@${MKD} $(dir $@)
# 	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

# ${OBJ_DIR}/%.o: ${EXEC_DIR}/%.c
# 	@${MKD} $(dir $@)
# 	@$(CC) ${CFLAGS} ${IFLAGS} -c $< -o $@

ftlibft:
	@cd ${LIBRARIES}/${LIBFT_DIR} ${MK_} all

ftprintf:
	@cd ${LIBRARIES}/${PRINTFT_DIR} ${MK_} all

ftexamft:
	@cd ${LIBRARIES}/${EXAMFT_DIR} ${MK_} all

clean:
	@echo "$(YELLOW)Removing object files ...$(DEF_COLOR)"

	@cd ${LIBRARIES}/${LIBFT_DIR} ${MK_} clean
	@cd ${LIBRARIES}/${PRINTFT_DIR} ${MK_} clean
	@cd ${LIBRARIES}/${EXAMFT_DIR} ${MK_} clean
	@$(RM) ${OBJ_DIR}/*.o

	@echo "$(RED)Object files removed $(DEF_COLOR)"

fclean:	clean
	@echo "$(YELLOW)Removing binaries ...$(DEF_COLOR)"

	@cd ${LIBRARIES}/${LIBFT_DIR} ${MK_} fclean
	@cd ${LIBRARIES}/${PRINTFT_DIR} ${MK_} fclean
	@cd ${LIBRARIES}/${EXAMFT_DIR} ${MK_} fclean
	@${RM} ${NAME} ${NAME_BONUS}

	@echo "$(RED)Binaries removed $(DEF_COLOR)"

re:	fclean all

.PHONY : all ftlibft ftprintf ftexamft clean fclean bonus re

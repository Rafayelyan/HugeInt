SOURCES		= HugeInt.cpp source.cpp
OBJS		= ${SOURCES:.cpp=.o}
CC			= g++
RM			= rm -f
FLAGS		= #-Wall -Wextra -Werror

%.o : %.c
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all : ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o huge_int

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} huge_int

re : fclean all

.PHONY: all clean fclean bonus re .c.o
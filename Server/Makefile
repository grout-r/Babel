NAME		=		BabelServer

CC		=		g++

RM		=		rm -f

INCLUDES	=		-Iincludes -I../CommonIncludes

CXXFLAGS	=		 --std=c++11 $(INCLUDES) 

SRCS		=		src/ClientBase.cpp \
				src/ClientDataHandler.cpp \
				src/main.cpp \
				src/Server.cpp \

OBJS		=		$(SRCS:.cpp=.o)

RED_COLOR	=		"\033[31;01m"

NO_COLOR	=		"\033[0m"


all:				$(NAME)

$(NAME):		 	$(OBJS)
				$(CC) -o $(NAME) $(OBJS) $(GDL_LDFLAGS)

clean:
				$(RM) $(OBJS)

fclean:				clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:				all clean fclean

NAME = intern

CXX	= c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I. -Iforms

SRCS = main.cpp \
	   Bureaucrat.cpp \
	   Intern.cpp \
	   AForm.cpp \
	   forms/PresidentialPardonForm.cpp \
	   forms/RobotomyRequestForm.cpp \
	   forms/ShrubberyCreationForm.cpp

all: $(NAME)

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

$(NAME): $(OBJS)
		 $(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
		@mkdir -p $(dir $@)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJDIR)

fclean: clean
		rm -f $(NAME)
		rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = src
BUILTINSDIR = builtins
INCLUDEDIR = include
TESTDIR = test
ADVANCEDDIR = advanced
HANDLERSDIR = handlers
ENVIRONMENTDIR = environment
OBJDIR = obj
EXEC = simple_shell

SRC := $(shell find $(SRCDIR) -name '*.c')
BUILTINSSRC := $(shell find $(BUILTINSDIR) -name '*.c')
TESTSRC := $(shell find $(TESTDIR) -name '*.c')
ADVANCEDSRC := $(shell find $(ADVANCEDDIR) -name '*.c')
HANDLERSSRC := $(shell find $(HANDLERSDIR) -name '*.c')
ENVIRONMENTSRC := $(shell find $(ENVIRONMENTDIR) -name '*.c')

OBJ := $(SRC:.c=$(OBJDIR)/%.o)
BUILTINSOBJ := $(BUILTINSSRC:.c=$(OBJDIR)/%.o)
TESTOBJ := $(TESTSRC:.c=$(OBJDIR)/%.o)
ADVANCEDOBJ := $(ADVANCEDSRC:.c=$(OBJDIR)/%.o)
HANDLERSOBJ := $(HANDLERSSRC:.c=$(OBJDIR)/%.o)
ENVIRONMENTOBJ := $(ENVIRONMENTSRC:.c=$(OBJDIR)/%.o)

all: $(EXEC)

$(EXEC): $(OBJ) $(BUILTINSOBJ) $(TESTOBJ) $(ADVANCEDOBJ) $(HANDLERSOBJ) $(ENVIRONMENTOBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c $< -o $@

$(OBJDIR)/builtins/%.o: builtins/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c $< -o $@

$(OBJDIR)/test/%.o: test/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c $< -o $@

$(OBJDIR)/advanced/%.o: advanced/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c $< -o $@

$(OBJDIR)/handlers/%.o: handlers/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c $< -o $@

$(OBJDIR)/environment/%.o: environment/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re

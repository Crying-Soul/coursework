CC = gcc
CFLAGS = -I$(INCDIR) -Wall -Wextra -g -pedantic -fsanitize=address -fsanitize=undefined -DLOG_USE_COLOR
RM = rm -rf

SRCDIR = src
INCDIR = include
OBJDIR = obj

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))
EXECUTABLE = cw

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJDIR) $(EXECUTABLE)

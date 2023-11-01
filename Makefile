CC = gcc
DEBUG_FLAGS = -fsanitize=address -fsanitize=undefined
COLOR_FLAG = -DLOG_USE_COLOR 
CFLAGS = -I$(INCDIR) $(DEBUG_FLAGS) $(COLOR_FLAG) -pedantic -Wall -Wextra -Wformat -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes -Wmissing-prototypes -Wstrict-overflow -Wundef -Wnested-externs -Wunreachable-code -Wlogical-op -Wvla -Wdisabled-optimization -Wcast-align -Wconversion -Wsign-compare -Wwrite-strings -Wimplicit-fallthrough -Wno-multichar
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

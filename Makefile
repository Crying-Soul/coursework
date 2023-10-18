CC = gcc
CFLAGS = -Wall -Wextra -pedantic
SRC = main.c get_text_input.c remove_lead_spaces.c
OBJ = $(SRC:.c=.o)
OUT = coursework

all: $(OUT)
	$(CC) $(CFLAGS) -o $@ $(OBJ)


$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f all $(OUT) $(OBJ)
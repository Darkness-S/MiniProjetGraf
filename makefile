CC=gcc
CFLAGS=-g -W -Wall

OBJDIR=obj
BINDIR=bin
SRCDIR=src
INCDIR=include

SRC=$(wildcard $(SRCDIR)/*.c)
INC=$(wildcard $(INCDIR)/*.h)
OBJ=$(SRC: $(SRCDIR)/%.c=$(OBJDIR)/%.o)

EXEC=exec

all: $(BINDIR)/$(EXEC)

$(BINDIR)/$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)%.h
	$(CC) -o $@ $(CFLAGS) -c $<

clean:
	rm $(OBJDIR)/*.o; rm $(BINDIR)/$(EXEC)

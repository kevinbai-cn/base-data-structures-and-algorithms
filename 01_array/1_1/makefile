CC = g++
INCDIR = ../../include
IDIR = $(INCDIR)/catch2
CFLAGS = -I$(IDIR) -std=c++11

ODIR = obj
DIRGUARD = @mkdir -p $(@D)

test: $(INCDIR)/$(ODIR)/catch.o $(ODIR)/test.o
	$(CC) $^ -o $@ $(CFLAGS)

$(INCDIR)/$(ODIR)/catch.o: $(INCDIR)/catch.cpp
	$(DIRGUARD)
	$(CC) -c $< -o $@ $(CFLAGS)

$(ODIR)/%.o: %.cc
	$(DIRGUARD)
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: clean

clean:
	rm -rf $(ODIR) $(INCDIR)/$(ODIR)

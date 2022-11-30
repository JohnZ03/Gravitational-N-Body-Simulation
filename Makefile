
# ****************************************************
# Targets needed to bring the executable up to date
 
all: run.o main.o plot.o
    gcc -o run run.o main.o
# The main.o target can be written more simply
run.o: run.cpp main.cpp
    $(CC) $(CFLAGS) -c run.cpp
 

CC=gcc 
all: doc src header bin lib obj program

#entry point for compilation. 
#currently is basic since there are no dependencies.
program:  
	$(CC) -o bin/program src/main.c src/car_expenses.c src/flight_expenses.c src/conference_fee.c src/display.c


#generates the directories:
doc:
	mkdir -p $@
src:
	mkdir -p $@
header:
	mkdir -p $@
bin:
	mkdir -p $@
lib:
	mkdir -p $@
obj:
	mkdir -p $@




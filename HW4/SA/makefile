CC = g++
MAIN_FILE=main
BACKPACK_FILE=backpack
SA_FILE=SA

all:run

# run:$(MAIN_FILE).cpp $(MAIN_FILE).o $(MAIN_FILE)
run:
	$(CC) -c $(MAIN_FILE).cpp $(SA_FILE).cpp ../src/$(BACKPACK_FILE).cpp
	$(CC) -o $(MAIN_FILE) $(MAIN_FILE).o $(SA_FILE).o $(BACKPACK_FILE).o
	# usage of hw4:
	# ./main.exe -input <inputfile>


clean:
	rm -f $(MAIN_FILE)
	rm -f $(MAIN_FILE).o
	rm -f $(SA_FILE).o
	rm -f $(BACKPACK_FILE).o
	rm -r answer/
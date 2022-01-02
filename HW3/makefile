CC = g++
MAIN_FILE=main
BACKPACK_FILE=backpack
DYNAMIC_FILE=Dynamic

all:run

# run:$(MAIN_FILE).cpp $(MAIN_FILE).o $(MAIN_FILE)
run:
	$(CC) -c $(MAIN_FILE).cpp $(DYNAMIC_FILE).cpp src/$(BACKPACK_FILE).cpp
	$(CC) -o $(MAIN_FILE) $(MAIN_FILE).o $(DYNAMIC_FILE).o $(BACKPACK_FILE).o
	# usage of hw3:
	# ./main.exe -input <inputfile>


clean:
	rm -f $(MAIN_FILE)
	rm -f $(MAIN_FILE).o
	rm -f $(DYNAMIC_FILE).o
	rm -f $(BACKPACK_FILE).o
	rm -r answer/
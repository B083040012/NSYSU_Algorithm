CC = g++
MAIN_FILE=main
BACKPACK_FILE=backpack
ES_FILE=ES

all:run

# run:$(MAIN_FILE).cpp $(MAIN_FILE).o $(MAIN_FILE)
run:
	$(CC) -c $(MAIN_FILE).cpp $(ES_FILE).cpp src/$(BACKPACK_FILE).cpp
	$(CC) -o $(MAIN_FILE) $(MAIN_FILE).o $(ES_FILE).o $(BACKPACK_FILE).o
	./$(MAIN_FILE)


clean:
	rm -f $(MAIN_FILE)
	rm -f $(MAIN_FILE).o
	rm -f $(ES_FILE).o
	rm -f $(BACKPACK_FILE).o
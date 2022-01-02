CC = g++
MAIN_FILE=main
BACKPACK_FILE=backpack
GA_FILE=GA

all:run

# run:$(MAIN_FILE).cpp $(MAIN_FILE).o $(MAIN_FILE)
run:
	$(CC) -c $(MAIN_FILE).cpp $(GA_FILE).cpp ../src/$(BACKPACK_FILE).cpp
	$(CC) -o $(MAIN_FILE) $(MAIN_FILE).o $(GA_FILE).o $(BACKPACK_FILE).o
	# uGAge of hw4:
	# ./main.exe -input <inputfile>


clean:
	rm -f $(MAIN_FILE)
	rm -f $(MAIN_FILE).o
	rm -f $(GA_FILE).o
	rm -f $(BACKPACK_FILE).o
	rm -r answer/
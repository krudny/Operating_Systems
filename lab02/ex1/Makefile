CC = gcc
BUILD_DIR = build

all:
	make reverse_short
	make reverse_long

reverse_short: reverse.c
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$@ $<
	./$(BUILD_DIR)/$@ files/input_short.txt files/output_short.txt

reverse_long: reverse.c
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$@ $<
	./$(BUILD_DIR)/$@ files/input_long.txt files/output_long.txt

clean:
	rm -rf $(BUILD_DIR)
	rm -rf files/pomiar_zad_2.txt
CC = gcc
BUILD_DIR = build

find: find.c
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$@ $<
	./$(BUILD_DIR)/$@

clean:
	rm -rf $(BUILD_DIR)
	rm -rf results.txt
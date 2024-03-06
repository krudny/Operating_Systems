CC = gcc
BUILD_DIR = build

collatz_static: collatz.c
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$@ -c $<
	ar rcs $(BUILD_DIR)/lib$@.a $(BUILD_DIR)/$@

collatz_shared: collatz.c
	mkdir -p $(BUILD_DIR)
	$(CC) -fPIC -o $(BUILD_DIR)/$@.o -c $<
	$(CC) -shared -o $(BUILD_DIR)/lib$@.so $(BUILD_DIR)/$@.o


clean:
	rm -rf $(BUILD_DIR)


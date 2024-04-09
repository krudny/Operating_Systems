CC = gcc
BUILD_DIR = build


run_static: main.c
	mkdir -p $(BUILD_DIR)
	make -C library library_static
	$(CC) -o $(BUILD_DIR)/$@ $< library/build/liblibrary_static.a
	./$(BUILD_DIR)/$@

run_shared: main.c
	mkdir -p $(BUILD_DIR)
	make -C library library_shared
	$(CC) -L library/build $< -llibrary_shared -Wl,-rpath=./library/build -o $(BUILD_DIR)/$@
	./$(BUILD_DIR)/$@


run_dynamic: main.c
	mkdir -p $(BUILD_DIR)
	make -C library library_shared
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $< -ldl -D DYNAMIC
	./$(BUILD_DIR)/$@


clean:
	rm -rf $(BUILD_DIR)
	make -C library clean
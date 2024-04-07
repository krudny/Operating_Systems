CC=gcc
BUILD_DIR=build

spawn_process: ex1.c
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$@ $<
	./$(BUILD_DIR)/spawn_process 10

execute: ex2.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $(BUILD_DIR)/$@ $<
	mkdir -p test_dir
	touch test_dir/file1
	touch test_dir/file2

#	./$(BUILD_DIR)/execute test_dir
#	@echo "Return code: $$?"
	./$(BUILD_DIR)/execute asdmasdk
	@echo "Return code: $$?"

clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(BUILD_DIR) test_dir
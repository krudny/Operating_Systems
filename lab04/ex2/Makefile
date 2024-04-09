CC=gcc
BUILD_DIR=build

# create sender executable
sender: sender.c
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$@ $<

# create catcher executable
catcher: catcher.c
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$@ $<

PID := 0
ARGUMENT := 1
run_sender: sender
	./$(BUILD_DIR)/sender $(PID) $(ARGUMENT)

run_catcher: catcher
	./$(BUILD_DIR)/catcher

clean:
	rm -rf $(BUILD_DIR)
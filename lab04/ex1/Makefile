CC=gcc
BUILD_DIR=build


signal_demo: signal_demo.c
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$@ $<

test: signal_demo
	./$(BUILD_DIR)/signal_demo ignore
	./$(BUILD_DIR)/signal_demo handler
	./$(BUILD_DIR)/signal_demo mask
	./$(BUILD_DIR)/signal_demo none


clean:
	rm -rf $(BUILD_DIR)
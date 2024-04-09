CC = gcc
BUILD_DIR = build

# ar command packs compilation result (object file) into .a archive
# ar options:
#    r - insert with replacement, if archive exists and contains given file, file inside archive will be replaced
#	 c - create, creates archive if it does not exist
# 	 s - updates archive index

library_static: library_code.c
	mkdir -p $(BUILD_DIR)
	$(CC) -o $(BUILD_DIR)/$@ -c $<
	ar rcs $(BUILD_DIR)/lib$@.a $(BUILD_DIR)/$@

# -fPIC - create Position Indexed Code, code accesses all constant adrress through special offset table

library_shared: library_code.c
	mkdir -p $(BUILD_DIR)
	$(CC) -fPIC -o $(BUILD_DIR)/$@.o -c $<
	$(CC) -shared -o $(BUILD_DIR)/lib$@.so $(BUILD_DIR)/$@.o

clean:
	rm -rf $(BUILD_DIR)
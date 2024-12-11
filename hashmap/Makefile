CXX := g++
CXXFLAGS := -std=c++20 -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused

# Target source files and executables
LIBRARY_SOURCE := hashmap.cpp
LIBRARY_EXECUTABLE := hashmap

TEST_SOURCE := hashmap_test.cpp
TEST_EXECUTABLE := hashmap_test

TESTING_FRAMEWORK := ../simple_test.h

# Default rule: Compile and run the library
run: $(LIBRARY_EXECUTABLE)
	./$(LIBRARY_EXECUTABLE)

# Rule to build the library executable
$(LIBRARY_EXECUTABLE): $(LIBRARY_SOURCE)
	$(CXX) $(CXXFLAGS) -o $(LIBRARY_EXECUTABLE) $(LIBRARY_SOURCE)

# Rule to compile and run the test
test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

# Rule to build the test executable
$(TEST_EXECUTABLE): $(TEST_SOURCE) $(LIBRARY_SOURCE) $(TESTING_FRAMEWORK)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXECUTABLE) $(TEST_SOURCE) $(LIBRARY_SOURCE)

# Clean up generated files
clean:
	rm -f $(LIBRARY_EXECUTABLE) $(TEST_EXECUTABLE)

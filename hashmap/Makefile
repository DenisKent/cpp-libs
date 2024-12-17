CXX := g++
CXXFLAGS := -std=c++20 -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused
DEBUGFLAGS := -O0 -g
TEST_SOURCE := hashmap_test.cpp
TEST_EXECUTABLE := hashmap_test
DEBUG_EXECUTABLE := hashmap_debug

TESTING_FRAMEWORK := ../simple_test.h

# Rule to compile and run the test
test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

# Rule to build the test executable
$(TEST_EXECUTABLE): $(TEST_SOURCE) $(TESTING_FRAMEWORK)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXECUTABLE) $(TEST_SOURCE)

# Rule to build the debug executable
$(DEBUG_EXECUTABLE): $(TEST_SOURCE) $(TESTING_FRAMEWORK)
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -o ./$(DEBUG_EXECUTABLE) $(TEST_SOURCE)


# Clean up generated files
clean:
	rm -f $(TEST_EXECUTABLE) $(DEBUG_EXECUTABLE)

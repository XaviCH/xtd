CC = g++
TARGET = *

test: $(TARGET)/*.cpp $(TARGET)/*.hpp $(TARGET)/*.tpp
	$(CC) -o test.exe test/$(TARGET).cpp
	./test.exe
	rm test.exe

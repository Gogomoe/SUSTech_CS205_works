C++ = c++
TARGET = main
OBJ = main.o candybar.o
INCLUDE = candybar.h

$(TARGET): $(OBJ)
	$(C++) $^ -o $@


%.o: %.cpp $(INCLUDE)
	$(C++) $< -c -o $@

clean:
	rm -f *.o $(TARGET)
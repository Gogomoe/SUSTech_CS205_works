C++ = c++
TARGET = main
OBJ = main.o fun.o
INCLUDE = fun.h

$(TARGET): $(OBJ)
	$(C++) $^ -o $@


%.o: %.cpp $(INCLUDE)
	$(C++) $< -c -o $@

clean:
	rm -f *.o $(TARGET)
SRC = $(wildcard *.cpp)
OBJ = $(addprefix object/, $(SRC:.cpp=.o))
DEP = $(addprefix object/, $(SRC:.cpp=.d))
CXX = g++

main:$(OBJ)
	$(CXX) -O3 $^
object/%.o:%.cpp
	$(CXX) -O3 -o $@ -c -MMD -MP -MF $(@:%.o=%.d) $<
-include $(DEP)

.PHONY:clean
clean:
	rm -f $(OBJ) $(DEV)

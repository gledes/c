SUBDIR=src
CXX_SOURCE=$(foreach dir, $(SUBDIR), $(wildcard $(dir)/*.cpp))
CXX_OBJECT=$(patsubst %.cpp, %.o, $(CXX_SOURCE))
DEP_FILE = $(patsubst %.o, %.d, $(CXX_OBJECT))

#-L库路径   -l库名
hello:$(CXX_OBJECT)
	g++ $^ -o $@


%.o:%.cpp
	g++ -c -MMD $< -o $@
pr:
	@echo $(CXX_OBJECT)

-include $(DEP_FILE)

clean:
	rm $(CXX_OBJECT) $(DEP_FILE)  hello
#readelf -d
#export LD_LIBRARY_PATH
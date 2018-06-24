SUBDIR=src
CXX_SOURCE=$(foreach dir, $(SUBDIR), $(wildcard $(dir)/*.cpp))
CXX_OBJECT=$(patsubst %.cpp, %.o, $(CXX_SOURCE))
DEP_FILE = $(patsubst %.o, %.d, $(CXX_OBJECT))


libexample.so:$(CXX_OBJECT)
	g++ -shared $^ -o libexample.so

%.o:%.cpp
	g++ -c -fPIC -MMD $< -o $@

-include $(DEP_FILE)

clean:
	rm $(CXX_OBJECT) $(DEP_FILE) libexample.so
#readelf -d
#export LD_LIBRARY_PATH
SUBDIR=src
CXX_SOURCE=$(foreach dir, $(SUBDIR), $(wildcard $(dir)/*.cpp))
CXX_OBJECT=$(patsubst %.cpp, %.o, $(CXX_SOURCE))
DEP_FILE = $(patsubst %.o, %.d, $(CXX_OBJECT))

CXXFLAGS += -I/home/jin/project/example/include
LDFLAGS += -L/home/jin/project/example/lib -lexample

hello:$(CXX_OBJECT)
	g++ $(CXX_OBJECT) -o $@ $(LDFLAGS)

%.o:%.cpp
	g++ -c $(CXXFLAGS) -MMD $< -o $@
pr:
	@echo $(CXX_OBJECT)

-include $(DEP_FILE)

clean:
	rm $(CXX_OBJECT) $(DEP_FILE) hello
#readelf -d
#export LD_LIBRARY_PATH=/home/jin/project/example/lib
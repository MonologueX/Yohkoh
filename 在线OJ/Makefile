oj_server:oj_server.cpp oj_model.hpp oj_view.hpp 
	g++ oj_server.cpp -o oj_server -std=c++11 -lpthread -ljsoncpp -lctemplate -L ~/third_part/lib
compile_server:compiler_server.cpp compiler.hpp
	g++ compiler_server.cpp compiler.hpp -o compiler_server -std=c++11 -lpthread -ljsoncpp
test:test.cpp compiler.hpp 
	g++ -std=c++11 test.cpp -o test -lpthread -ljsoncpp

.PHONY:clean
clean:
	rm -f test

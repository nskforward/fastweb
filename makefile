test:
	g++ -pthread -std=c++17 ./tests/*.cpp -o ./build/test && ./build/test

run:
	awk '{if ($$2 == "_APP_VERSION_PATCH") print $$1, $$2, ++$$3; else print $$0}' version.hpp > tmp && mv tmp version.hpp
	g++ -pthread -g -std=c++17 ./*.cpp ./*/*.cpp  ./*/*/*.cpp -o ./build/app_server && ./build/app_server

compile:
	mkdir -p ./build
	g++ -pthread -std=c++17 ./src/*.cpp ./src/*/*/*.cpp -o ./build/app_server

trace:
	g++ -pthread -g -std=c++17 ./*.cpp ./*/*/*.cpp -o ./build/app
	strace ./build/app

mem:
	g++ -pthread -g -std=c++17 ./*.cpp ./*/*/*.cpp -o ./build/app
	valgrind --tool=massif ./build/app
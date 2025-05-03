
clean:
	rm -rf build

build-release:
	cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
	cmake --build build --config Release

run:
	./build/todo-list-app

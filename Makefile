config:
	cmake -B build -G Ninja
build:config
	cmake --build build 

clean:
	rm -rf build/
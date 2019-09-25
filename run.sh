
DIR="build"
if [ -d "$DIR" ]; then
	echo "delete then init ${DIR}..."
	rm -r build && mkdir build && cd build && cmake .. && make && ./app
else
	echo "init ${DIR}..."
	mkdir build && cd build && cmake .. && make && ./app
	exit 1
fi

CXX = g++
# Добавляем -O2 (или -O3, если хотите ещё агрессивнее). Можно также добавить -march=native и другие флаги.
CXXFLAGS = -Wall -Werror -Wextra -c -std=c++17 -pedantic -O2

all:
	make clean
	make install

install:
	# Передаём CMake флаг: CMAKE_BUILD_TYPE=Release
	cd view && cmake -B ../build_tmp -S . -DCMAKE_BUILD_TYPE=Release
	cd view && cmake --build ../build_tmp --config Release
	mkdir -p build
	cp build_tmp/3DViewer build/3DViewer
	rm -rf build_tmp

uninstall:
	rm -rf build

clean:
	rm -rf build rm *.o rm test_back *.a *.gcno *.gcov *.gcda *.info test_gcov rm -rf report rm -rf doc rm -rf build_tmp 3DViewer_dist.tgz

clangformat:
	clang-format -i --style=google bl/* controller/* view/*.cpp view/*.h qtgifimage/*.h qtgifimage/*.cpp test/*.cpp test/*.h

dvi:
	doxygen

dist:
	mkdir -p 3DViewer_dist
	@cp -r bl 3DViewer_dist
	@cp -r controller 3DViewer_dist
	@cp -r view 3DViewer_dist
	@cp -r test 3DViewer_dist
	@cp -r qtgifimage 3DViewer_dist
	@cp Makefile 3DViewer_dist
	@cp Doxyfile 3DViewer_dist
	@tar -cvzf 3DViewer_dist.tgz 3DViewer_dist
	@rm -rf 3DViewer_dist

bl.a:
	$(CXX) $(CXXFLAGS) bl/bl.cpp bl/new_affine.cpp controller/controller.cpp
	ar rcs bl.a *.o
	rm *.o

test: bl.a
	$(CXX) $(CXXFLAGS) test/*.cpp
	$(CXX) -L. -I. -o test_back *.o bl.a -lgtest -pthread
	rm *.o
	./test_back

gcov_report:
	mkdir -p report
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage bl/bl.cpp bl/new_affine.cpp controller/controller.cpp
	ar rcs bl_gcov.a *.o
	ranlib bl_gcov.a
	rm *.o
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage test/*.cpp
	$(CXX) -L. -I. -o test_gcov *.o bl_gcov.a -lgcov -pthread -lgtest
	./test_gcov
	gcov -o . bl/bl.cpp bl/new_affine.cpp controller/controller.cpp
	lcov -b ./ -d . --gcov-tool /usr/bin/gcov -c -o output.info --no-external
	genhtml -o report/ output.info
	xdg-open report/index.html

valgrind:
	valgrind  --tool=memcheck --track-fds=yes --trace-children=yes --track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test_back

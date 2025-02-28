.PHONY: build install test clean lint format

RELEASE_TYPE = Release
PY_SRC = src/pysrc
CPP_SRC = src/cppsrc

build: cppinstall
	cd build && cmake .. -DCMAKE_TOOLCHAIN_FILE=$(RELEASE_TYPE)/generators/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=$(RELEASE_TYPE) -G Ninja
	cd build && cmake --build .
	@cp -f build/*.so $(PY_SRC)

pyinstall:
	poetry install

cppinstall:
	conan install . --build=missing

install: pyinstall cppinstall

pyunit: pyinstall build
	@poetry run pytest $(PY_SRC)/test/unit

pyintegration: pyinstall build
	@poetry run pytest $(PY_SRC)/test/integration

correlation: pyinstall build
	poetry run python3 src/pysrc/correlation.py

cpptest: build
	@cd build && ./intern_tests

test: pyunit pyintegration cpptest

run: pyinstall build
	poetry run python3 src/pysrc/exec.py

clean:
	@rm -rf build
	@rm -f $(PY_SRC)/*.so

lint:
	poetry run mypy $(PY_SRC)
	poetry run ruff check $(PY_SRC)
	poetry run ruff format --check $(PY_SRC)

format:
	find $(CPP_SRC) -name '*.cpp' -o -name '*.hpp' | xargs clang-format -i
	poetry run ruff format $(PY_SRC)
	poetry run ruff check --fix $(PY_SRC)

# build:
# 	g++ -std=c++17 -Wall -Werror -O -o may27.out may27.cpp; echo "Compiled successful!"

# run: build
# 	./may27.out
	

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -O

.PHONY: all clean

# Default target when no argument is given
all:
	@echo "Usage: make <filename_without_extension>"
	@echo "Example: make may27"

# %: %
# 	$(CXX) $(CXXFLAGS) $< -o $@.out
# 	./$@.out

%:
	@base=$*; \
	if [ -f $$base.cpp ]; then src=$$base.cpp; \
	elif [ -f $$base.cc ]; then src=$$base.cc; \
	elif [ -f $$base ]; then src=$$base; \
	else echo "Error: No matching source file for '$$base'"; exit 1; \
	fi; \
	output=$${src%.*}.out; \
	echo "Compiling $$src to $$output..."; \
	$(CXX) $(CXXFLAGS) $$src -o $$output; \
	echo "Running $$output..."; \
	./$$output

clean:
	rm -f *.out
.PHONY: all run

FLAGS := -I headers/ -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
OBJECTS := array_transformation.o matrix_func.o input_matrix.o command_line.o help.o output_matrix.o
DIR_OBJECTS := $(addprefix obj/, $(OBJECTS))

all: array_transformation_start.exe

array_transformation_start.exe: $(DIR_OBJECTS)
	g++ $(DIR_OBJECTS) -o array_transformation_start

obj/%.o : src/%.cpp
	g++ $< -c $(FLAGS) -o $@

run:
	array_transformation_start.exe

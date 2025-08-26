CXX = g++
CXXFLAGS += -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix -Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla -fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr
CXXFLAGS += -I Headers

o = ObjectFiles/
s = Source/

all : prog testing
	$(CXX) $(CXXFLAGS) $(o)commands_def.o $(o)commands.o $(o)scam.o $(o)tools.o $(o)solvers.o $(o)main.o $(o)tests.o $(o)list.o $(o)list_tests.o $(o)readtests.o -o prog


prog : tools.o solvers.o main.o list.o readtests.o commands.o commands_def.o scam.o

list.o : $(s)list.cpp
	$(CXX) $(CXXFLAGS) -c $(s)list.cpp -o $(o)list.o

tools.o : $(s)tools.cpp
	$(CXX) $(CXXFLAGS) -c $(s)tools.cpp -o $(o)tools.o

readtests.o : $(s)readtests.cpp
	$(CXX) $(CXXFLAGS) -c $(s)readtests.cpp -o $(o)readtests.o

main.o : $(s)main.cpp
	$(CXX) $(CXXFLAGS) -c $(s)main.cpp -o $(o)main.o

solvers.o : $(s)solvers.cpp
	$(CXX) $(CXXFLAGS) -c $(s)solvers.cpp -o $(o)solvers.o

commands_def.o : $(s)commands_def.cpp
	$(CXX) $(CXXFLAGS) -c $(s)commands_def.cpp -o $(o)commands_def.o

commands.o : $(s)commands.cpp
	$(CXX) $(CXXFLAGS) -c $(s)commands.cpp -o $(o)commands.o


testing : tests.o list_tests.o

tests.o : $(s)tests.cpp
	$(CXX) $(CXXFLAGS) -c $(s)tests.cpp -o $(o)tests.o

list_tests.o : $(s)list_tests.cpp
	$(CXX) $(CXXFLAGS) -c $(s)list_tests.cpp -o $(o)list_tests.o


scam.o : $(s)scam.cpp
	$(CXX) $(CXXFLAGS) -c $(s)scam.cpp -o $(o)scam.o


clean:
	rm -f $(o)tools.o $(o)solvers.o $(o)main.o $(o)tests.o

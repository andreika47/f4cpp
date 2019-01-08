TARGET = f4cpp

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

CXXFLAGS = -std=c++14 -Wall -Wextra -Werror

ifneq ($(DEBUG), 1)
	OPTFLAGS = -O3 -flto
else
	OPTFLAGS = -ggdb3
endif

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) $(OBJS) -o $@

-include $(DEPS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(OPTFLAGS) -MP -MMD -c $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) *.{d,o}

.PHONY: fmt
fmt:
	clang-format -i *.{h,c}pp

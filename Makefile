CFLAGS = -Wall -Wextra -lncursesw -std=c++17 -O2

StudentDashboard : src/main.cpp
	g++ $(CFLAGS) -o bin/StudentDashboard src/main.cpp includes/weeknumber.cpp 

.PHONY: test clean

test: StudentDashboard 
	./bin/StudentDashboard

clean:
	rm -f /bin/StudentDashboard 

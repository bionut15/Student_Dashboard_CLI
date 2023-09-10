CFLAGS = -std=c++17 -O2

StudentDashboard : src/main.cpp
	g++ $(CFLAGS) -o bin/StudentDashboard src/main.cpp 

.PHONY: test clean

test: StudentDashboard 
	./bin/StudentDashboard

clean:
	rm -f /bin/StudentDashboard 

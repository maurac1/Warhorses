CXX = g++
CXXFLAGS = -Wall

proj4: War.o  Horse.o Light.o Medium.o Heavy.o Untrained.o  Warhorse.o driver.cpp
	$(CXX) $(CXXFLAGS) driver.cpp War.o Horse.o Light.o Medium.o Heavy.o Untrained.o Warhorse.o -o proj4

War.o:  Horse.o Light.o Medium.o Heavy.o Untrained.o War.cpp War.h
	$(CXX) $(CXXFLAGS) -c War.cpp

Horse.o: Horse.cpp Horse.h
	$(CXX) $(CXXFLAGS) -c Horse.cpp

Untrained.o: Untrained.cpp Untrained.h Horse.o Light.o Medium.o Heavy.o
	$(CXX) $(CXXFLAGS) -c Untrained.cpp

Warhorse.o: Warhorse.cpp Warhorse.h Horse.o
	$(CXX) $(CXXFLAGS) -c Warhorse.cpp

Light.o: Light.cpp Light.h Horse.o Warhorse.o
	$(CXX) $(CXXFLAGS) -c Light.cpp

Medium.o: Medium.cpp Medium.h Horse.o Warhorse.o
	$(CXX) $(CXXFLAGS) -c Medium.cpp

Heavy.o: Heavy.cpp Horse.o Heavy.h Warhorse.o
	$(CXX) $(CXXFLAGS) -c Heavy.cpp

clean:
	rm *.o*
	rm *~

run:
	./proj4 proj4_data.txt

val:
	valgrind ./proj4 proj4_data.txt

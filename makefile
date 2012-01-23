EXE = main
SOURCES = domesticTrip.cc internationalTrip.cc trip.cc main.cc
OBJECTS := $(SOURCES:%.cc=%.o)
CXXFLAGS = -Wall

$(EXE): $(OBJECTS)
	$(CXX) $^ -o $@

clean:
	$(RM) $(EXE) $(OBJECTS)

domesticTrip.o: domesticTrip.cc domesticTrip.h trip.h
internationalTrip.o: internationalTrip.cc internationalTrip.h trip.h
main.o: main.cc trip.h internationalTrip.h domesticTrip.h
trip.o: trip.cc trip.h

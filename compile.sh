
#!/usr/bin/env bash

g++ -I ./ -o launcher  src/main2.cpp src/source/Source.cpp  src/source/aperiodique.cpp src/source/periodique.cpp src/source/creneau.cpp src/source/echelon.cpp src/source/rectang.cpp src/source/sinus.cpp src/source/triang.cpp src/EDP/EDP.cpp src/EDP/EDP1.cpp src/EDP/exemple1.cpp src/EDP/circuit.cpp src/EDP/RC.cpp src/EDP/RCD.cpp src/EDP/EDP_2.cpp src/EDP/exemple2.cpp src/EDP/circuit2.cpp src/EDP/RLC.cpp src/EDP/RLCparallel.cpp


#!/usr/bin/env bash

# g++ -c main.cpp source/Source.cpp  source/aperiodique.cpp source/periodique.cpp source/creneau.cpp source/echelon.cpp source/rectang.cpp source/sinus.cpp source/triang.cpp \
#     EDP/EDP.cpp EDP/EDP1.cpp EDP/exemple1.cpp EDP/RC.cpp EDP/RCD.cpp


g++ -o launcher  main.cpp source/Source.cpp  source/aperiodique.cpp source/periodique.cpp source/creneau.cpp source/echelon.cpp source/rectang.cpp source/sinus.cpp source/triang.cpp EDP/EDP.cpp EDP/EDP1.cpp EDP/exemple1.cpp EDP/circuit.cpp EDP/RC.cpp EDP/RCD.cpp EDP/EDP_2.cpp EDP/exemple2.cpp

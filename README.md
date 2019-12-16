# Spice Simulator

<p align="center"><img src="UI1.png" alt="screenshot" width="400"></p>

Ce projet consiste à simuler différents circuits électriques à l'aide de plusieurs méthodes de résolution : 
  - Euler
  - Heun
  - Range-Kutta ordre 4

Pour cela, plusieurs sources sont disponibles (Sinusoïde, échelon, carrée, triangulaire).

Ce programme utilise la bibliothèque Eigen. Si vous vouler modifier ou recompiler le programme, il vous faudra le spécifier au compilateur. La bibliothèque est fournie dans le repositorie, il suffit de copier ce dossier dans le répertoire dédier du compilateur. Sinon, les sriptes de compilation fournis sont préconfigurés pour utiliser cette bibliothèque.

Le site officiel de Eigen : <http://eigen.tuxfamily.org/index.php?title=Main_Page>.

## Setup
###   Sous linux 
#### Utilisation

Ouvrez un terminal dans le dossier et lancer l'executable `launcher`. 
```shell
./launcher
```
Suivez les instructions puis terminer la simulation.
Pour tracez les résultats, vous pouvez utiliser le scipt python nommé `trace.py` 
```shell
python trace.py
```
#### Compilation
Pour compiler, aucun fichier Makefile n'a encpore été fait. Utiliser la commande suivante ou le script bash `complile.sh` pour le faire. attention s'il des fichiers sources sont ajouter il faudra aussi les rajouter en argument de la commande.
```shell
g++ -I ./ -o launcher  src/main2.cpp src/source/Source.cpp  src/source/aperiodique.cpp src/source/periodique.cpp src/source/creneau.cpp src/source/echelon.cpp src/source/rectang.cpp src/source/sinus.cpp src/source/triang.cpp src/EDP/EDP.cpp src/EDP/EDP1.cpp src/EDP/exemple1.cpp src/EDP/circuit.cpp src/EDP/RC.cpp src/EDP/RCD.cpp src/EDP/EDP_2.cpp src/EDP/exemple2.cpp src/EDP/circuit2.cpp src/EDP/RLC.cpp src/EDP/RLCparallel.cpp
````
ou
``` shell
./compile.sh
```


###   Sous Windows
#### Utilisation
Il suffit de lancer l'executable nommé `laucher.exe`. Cela derait ouvrir un terminal et lancez le programme.
Pour tracer vos résultats, vous pouvez utiliser le script python. Un fichier Batch `trace.bat` a été créé pour faciliter la tache.  

#### Compilation 
Pour facilité la compilation (et comme aucun fichier Makefile n'a encore été fait) le fichier Batch `compile.bat` contient la commande à lancer. Sinon lancez dans un cmd.exe ou dans un PowerShell :

```shell
g++ -I %cd% -o launcher.exe    src/main2.cpp src/source/Source.cpp  src/source/aperiodique.cpp src/source/periodique.cpp src/source/creneau.cpp src/source/echelon.cpp src/source/rectang.cpp src/source/sinus.cpp src/source/triang.cpp src/EDP/EDP.cpp src/EDP/EDP1.cpp src/EDP/exemple1.cpp src/EDP/circuit.cpp src/EDP/RC.cpp src/EDP/RCD.cpp src/EDP/EDP_2.cpp src/EDP/exemple2.cpp src/EDP/circuit2.cpp src/EDP/RLC.cpp  src/EDP/RLCparallel.cpp
```

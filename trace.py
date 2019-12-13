import matplotlib.pyplot as plt
import numpy as np
import math

####### lecture du fichier ###########
def readData(filename):
    with open(filename, "r") as f:
        content = f.read().splitlines()
    data = []
    # on retire les commentaires des data
    i = 0
    while content[i][0]=='#' :
        i+=1

    for el in content[i:] :
        data.append(el.split("\t"))
        # print el
    # print "next"
    for el in data :
        # print el
        for i in range(len(el)):
            el[i] = float(el[i])

    data = np.array(data)

    return data


print("Choose data to trace : \n[1] Euler \n[2] Heun \n[3] RK4 \n[4] Les 3")
choix = input()

fig = plt.figure()
ax = plt.subplot(111)


if choix==1 or choix==4:
    file = "data/euler.txt"
    data = readData(file)
    x = data[:,0]
    y = data[:,1]
    ax.plot(x,y,'b', label="Euler")

if choix==2 or choix==4:
    file = "data/heun.txt"
    data = readData(file)
    x = data[:,0]
    y = data[:,1]
    ax.plot(x,y,'g', label="Heun")

if choix==3 or choix==4:
    file = "data/RK4.txt"
    data = readData(file)
    x = data[:,0]
    y = data[:,1]
    ax.plot(x,y,'black', label="RK4")







src = readData("data/src.txt")
x_src = src[:,0]
y_src = src[:,1]
ax.plot(x_src,y_src,'r', label="Source")


ax.grid()
ax.legend()
plt.show()

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


file = "euler.txt"
data = readData(file)

x = data[:,0]
y = data[:,1]
plt.plot(x,y)

src = readData("src.txt")
y_src = src[:,1]
plt.plot(x,y_src)

alpha = 0
fexacte = (alpha-1.0/3)*np.exp(-3*x)-x+1.0/3;
# plt.plot(x,fexacte,'r')


plt.show()

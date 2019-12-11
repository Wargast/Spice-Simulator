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

if choix==1 or choix==4:
    file = "euler.txt"
    data = readData(file)
    x = data[:,0]
    y = data[:,1]
    plt.plot(x,y,'b')

if choix==2 or choix==4:
    file = "heun.txt"
    data = readData(file)
    x = data[:,0]
    y = data[:,1]
    plt.plot(x,y,'g')

if choix==3 or choix==4:
    file = "RK4.txt"
    data = readData(file)
    x = data[:,0]
    y = data[:,1]
    plt.plot(x,y,'black')

src = readData("src.txt")
x_src = src[:,0]
y_src = src[:,1]
plt.plot(x_src,y_src,'r')

# alpha = 0
# # fexacte = (alpha-1.0/3)*np.exp(-3*x)-x+1.0/3;
#
# r_lambda = math.sqrt(1)
# v0 = 0
# u0 = 1
# fexacte = v0 / r_lambda * np.sin(r_lambda*x) + u0*np.cos(r_lambda * x);
# # plt.plot(x,fexacte,'r')

plt.grid()
plt.show()

#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Aug 22 16:30:45 2022

@author: fabianodicheti
"""

import numpy as np
from numpy import arange
from numpy import meshgrid

from matplotlib import pyplot
import matplotlib as plt
from mpl_toolkits.mplot3d import Axes3D

E = 2.718281828459045


menor = -4
maior = 4



inicial = np.linspace(-4,4,10000)
x_inicial = inicial[np.random.randint(0,10000,1)[0]]
y_inicial = inicial[np.random.randint(0,10000,1)[0]]

delta_explot = 1/1000
delta_explor = 0.2

def quatro_g (x, y):
    linha1 = (0.97*((E))** -(((x+3)**2)+((y+3)**2)/5))
    linha2 = (0.98*((E))** -(((x+3)**2)+((y-3)**2)/5))
    linha3 = (0.99*((E))** -(((x-3)**2)+((y+3)**2)/5))
    linha4 = (1*((E))** -(((x-3)**2)+((y-3)**2)/5))
    
    return linha1+linha2+linha3+linha4

def perturba (x_atual, y_atual, delta):
    x_sorte = np.random.random(1)[0]
    if x_sorte >= 0.5:
        x_novo = x_atual + delta
    else:
        x_novo = x_atual - delta
        
    y_sorte = np.random.random(1)[0]
    if y_sorte >= 0.5:
        y_novo = y_atual - delta
    else:
        y_novo = y_atual + delta
        
    return[x_novo, y_novo]


conta = 0

todas = []
melhores =[]
melhores.append([x_inicial, y_inicial])

while conta < 50:
    for i in range(20):
        
        x = melhores[-1][0]
        y = melhores[-1][1]
        
        delta1 = perturba(x, y, delta_explot)
        
        x_novo = delta1[0]
        y_novo = delta1[1]
        
        sol_velha = quatro_g(x, y)
        sol_nova = quatro_g(x_novo, y_novo)
        
        if sol_nova > sol_velha:
            melhores.append(delta1)
            todas.append(delta1)
        else:
            todas.append(delta1)
            
    delta2 = perturba(x, y, delta_explor)
    x_novo2 = delta2[0]
    y_novo2 = delta2[1]
        
    sol_velha2 = quatro_g(x, y)
    sol_nova2 = quatro_g(x_novo2, y_novo2)
    
    if sol_nova2 > sol_velha2:
        melhores.append(delta2)
        todas.append(delta2)
    else:
        todas.append(delta2)
    
    
    
    conta += 1
    
print('x = ', round( melhores[-1][0],4), 'y = ',round(melhores[-1][1],4))
print('resultado = ', quatro_g(melhores[-1][0], melhores[-1][1]))


#### PLOT ####

plt.rcParams['figure.dpi'] = 400

eixo_x = arange(menor, maior, delta_explot)
eixo_y = arange(menor, maior, delta_explot)


x, y = meshgrid(eixo_x, eixo_y)


res_continuo = quatro_g(x, y)


figura = pyplot.figure()
axis = figura.gca(projection='3d')
axis.plot_surface(x, y, res_continuo, cmap='jet')


pyplot.show()

#### CONFERENCIA


lin_x = []
lin_y = []
lin_r = []
for t in range(len(todas)):
    lin_x.append(todas[t][0])
    lin_y.append(todas[t][1])
    lin_r.append(quatro_g(todas[t][0],todas[t][1]))
    
selec_x = []
selec_y = []
selec_r = []
for m in range(len(melhores)):
    selec_x.append(melhores[m][0])
    selec_y.append(melhores[m][1])
    selec_r.append(quatro_g(melhores[m][0],melhores[m][1]))

    
#graf1 = pyplot.plot(lin_x, lin_y) # caminho todas

#graf2 = pyplot.plot(lin_r) # evolucao todas

#graf3 = pyplot.plot(selec_x, selec_y) # caminho melhores

#graf4 = pyplot.plot(selec_r) # evolucao melhores


teste_lin = 0
teste_x_y = []
for j in range(len(eixo_x)):
    x = eixo_x[j]
    y = eixo_y[j]
    temp = quatro_g(x, y)
    if temp > teste_lin:
        teste_lin = temp
        teste_x_y = [x,y]


print('\n','conf x = ', round(teste_x_y[0],4) ,'conf y = ', round(teste_x_y[1],4))
print('conf resultado = ',round(teste_lin,6))    


            
  
    
    



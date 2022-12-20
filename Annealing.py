#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep  6 10:52:35 2022

@author: fabianodicheti
"""
import numpy as np
from osgeo import gdal
import random as rand

alfa = 0 # menor do que 1 para abaixar o valor de T gradualmente de 0.8 ate 0.99
n_repeticoes = 0

# dxelta eh diferenca entre o fitneszs da solucao corrente e o fitness da solucao anterior,
#  para maximizacao delta term que asermaior que zero para ser minimazo o delta tem
#   que ser menor que zero.

s = [] #conjunto de solucoes iniciais
T = 0  #limite superior
T_min =0 #limite inferior


e = 2.718281828459045

def fitness(x, y):
    E = 2.718281828459045
    linha1 = (0.97*((E))** -(((x+3)**2)+((y+3)**2)/5))
    linha2 = (0.98*((E))** -(((x+3)**2)+((y-3)**2)/5))
    linha3 = (0.99*((E))** -(((x-3)**2)+((y+3)**2)/5))
    linha4 = (1*((E))** -(((x-3)**2)+((y-3)**2)/5))
    
    return linha1+linha2+linha3+linha4


def populacao_inicial(N):
    rand = np.random.uniform(-4.01,3.99, size=(N, 2))
    return rand



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


def g(s):
    return s

while T > T_min:
    for i in range(n_repeticoes):
        s1 = perturba(s)
        delta_E = g(s1) - g(s)
        if delta_E <= 0:
            s = g()
        else:
            aleatorio = populacao_inicial()
            if aleatorio < e*(-delta_E/T):
                S = s
    T = T * alfa
    
    
def simulated_annealing(func_fitness,iteracoes, delta, temperatura):
	
    # populacao inicial
    popula = populacao_inicial(1)[0]
    #print(popula)
	#popula = limites[:, 0] + rand(len(limites)) * (limites[:, 1] - limites[:, 0])

    fit1 = func_fitness(popula[0],popula[1])
    
	# solucao corrente
    corrente, fitness_corrente = popula, fit1
    #print(corrente)

    for i in range(iteracoes):

        tentativa = [i+np.random.uniform(0-delta,0+delta) for i in corrente]
        #print(tentativa)
        fitness_tentativa = func_fitness(tentativa[0], tentativa[1])

        if fitness_tentativa > fit1:
            popula, fit1 = tentativa, fitness_tentativa
            print('>%d f(%s) = %.5f' % (i, popula, fit1))

        diferenca = fitness_tentativa - fitness_corrente

        
        t = temperatura / float(i + 1)

        metropolis = np.exp(-diferenca / t)

        if diferenca < 0 or np.random.uniform(0-delta,0+delta) < metropolis:
            corrente, fitness_corrente = tentativa, fitness_tentativa

    return [popula, fit1]


simulated_annealing(fitness, 5000, 0.5, 2000)
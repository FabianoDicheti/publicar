#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Aug 30 15:17:49 2022

@author: fabianodicheti
"""

import numpy as np
from copy import copy as cp
import matplotlib.pyplot as plt

E = 2.718281828459045
N = 15


def fitness(x, y):
    linha1 = (0.97*((E))** -(((x+3)**2)+((y+3)**2)/5))
    linha2 = (0.98*((E))** -(((x+3)**2)+((y-3)**2)/5))
    linha3 = (0.99*((E))** -(((x-3)**2)+((y+3)**2)/5))
    linha4 = (1*((E))** -(((x-3)**2)+((y-3)**2)/5))
    
    return linha1+linha2+linha3+linha4

def fitness_lista(lista):
    fitness_array = []
    for i in range(len(lista)):
        x = lista[i][0]
        y = lista[i][1]
        ft = fitness(x, y)
        fitness_array.append(ft)
    return fitness_array

def delta_desvio(lista_acumulada):
    fits = fitness_lista(lista_acumulada)
    desvio = np.std(fits)
    return desvio

def delta_variancia(lista_acumulada):
    fits = fitness_lista(lista_acumulada)
    desvio = np.std(fits)
    variancia = desvio**2
    return variancia

def selecao(lista_corrente): #selecao baseada na media
    fit = fitness_lista(lista_corrente)
    media = np.mean(fit)
    for i in range(len(lista_corrente)):
        if fit[i] > media:
            x = lista_corrente[i][0]
            y = lista_corrente[i][1]
            return([x,y], [i])
        
def mutacao(selecao, delta):
    x = selecao[0]
    y = selecao[1]
    if (np.random.random(1)[0]) > 0.5:
        x = x+delta
    else:
        x = x-delta
        
    if (np.random.random(1)[0]) > 0.5:
        y = y+delta
    else:
        y = y-delta 
    xy = [x,y]
    return np.array(xy)
        
def evolucao(geracoes, tamanho_populacao):
    N = tamanho_populacao
    G = geracoes
    populacao_inicial = np.random.uniform(-4.01,3.99, size=(N, 2))
    #print(populacao_inicial)
    populacao_acumulada = cp(populacao_inicial)
    populacao_corrente = cp(populacao_inicial)

    deltas = []
    delta_fixo = []#para comparativo dos desvios
    for i in range(G):

        d = delta_variancia(populacao_acumulada)
        s = selecao(populacao_corrente)[0] #solucao
        l = selecao(populacao_corrente)[1] #indice da solucao
        m = mutacao(s, d)

        populacao_acumulada = np.vstack([populacao_acumulada, m])
        
        deltas.append(d)
        df = delta_variancia(populacao_corrente)
        delta_fixo.append(df)
        
        if fitness(m[0],m[1]) > fitness(s[0],s[1]):
            populacao_corrente = np.delete(populacao_corrente, l[0], axis=0)#remove o pai pelo indice
            populacao_corrente = np.vstack([populacao_corrente, m])
        else:
            populacao_corrente = np.delete(populacao_corrente, l[0], axis=0)
            populacao_corrente = np.vstack([populacao_corrente, s]) # remove o item selecionado e joga ele pra o final da fila

    
    solucoes_finais = fitness_lista(populacao_corrente)  
    maximo = max(solucoes_finais)
    indice = solucoes_finais.index(maximo)
    
    plt.rcParams['figure.dpi'] = 400
    
    graf_d = plt.plot(deltas)
    
    return populacao_corrente[indice], fitness(populacao_corrente[indice][0], populacao_corrente[indice][1])


a = evolucao(3500, 10)

b = evolucao(2000, 20)



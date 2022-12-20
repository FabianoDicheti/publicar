#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep  6 16:25:29 2022

@author: fabianodicheti
"""
import numpy as np
from copy import copy as cp


def solucoes_rand(tam_populacao, tamanho_cromo = 32):
    return [np.random.randint(0,2,tamanho_cromo) for i in range(tam_populacao)]

def quatro_g (x, y):
    E = 2.718281828459045
    linha1 = (0.97*((E))** -(((x+3)**2)+((y+3)**2)/5))
    linha2 = (0.98*((E))** -(((x+3)**2)+((y-3)**2)/5))
    linha3 = (0.99*((E))** -(((x-3)**2)+((y+3)**2)/5))
    linha4 = (1*((E))** -(((x-3)**2)+((y-3)**2)/5))
    return linha1 + linha2 +linha3 +linha4
    
## 32 bits 16 p/x e 16 p/y
def bit2float(lista, menor, maior):
    index = [128,64,32,16,8,4,2,1,0.5, 0.25,0.125,0.0625,0.031,0.015625,0.007813,0.003906]
    numero = np.sum([lista[i] * index[i] for i in range(16)])
    escala = (((maior - menor) / np.sum(index)) * numero) + menor
    
    return escala


#selecionar o individuio pela roleta
def roleta(populacao):
    V = [quatro_g(i[0], i[1]) for i in populacao] #avaliacao da populacao
    media = np.mean(V)
    for j in range(len(V)):
        seta = np.random.randint(0,len(V))
        if V[seta] > media:
            return seta
        else:
            if V[j] > media:
                return j
    

# cruzamento => sortear qual o ponto do cruzamento fazer os cortes
def ponto_corte(lista, quant_pontos):
    pontos = np.sort([np.random.randint(1,(len(lista)-2)) for i in range(quant_pontos)])
    for i in range(quant_pontos-1):
        if pontos[i] == pontos[i+1]:
            pontos[i+1] = pontos[i]+1
    pontos = np.sort(pontos)
    for j in range(quant_pontos-1):
        if pontos[j] == pontos[j+1]:
            pontos[j+1] = pontos[j]+1
            
    return np.sort(pontos)


def cruzamento(lista1, lista2, quant_cortes):
    pontos = ponto_corte(lista1, quant_cortes)
    resultante = []
    inicio = [i for i in pontos]
    inicio.insert(0,0)
    fim = [f for f in pontos]
    fim.append(len(lista1))
    
    c = 2
    for j in range(quant_cortes+1):
        if c % 2 ==0:
            lista = lista1
        else:
            lista = lista2
        corte = lista[inicio[j]:fim[j]]
        resultante = resultante + corte
        c = c+1
       
    return resultante



# mutacao probabilidade de troca, sortear um ponto no vetori para mudar de 0 p/1 ou de 1 p/0
def mutacao(solucao, probabilidade_porcento, quant_mutacoes):
    lista = cp(solucao)
    for i in range(quant_mutacoes):
        moeda = np.random.randint(0,100)
        if moeda < probabilidade_porcento:
            indice = np.random.randint(0,len(lista))
            if lista[indice] != 0:
                lista[indice] = 0
            else:
                lista[indice] = 1
    return lista
       


def cruza_med_aritm(sol1, sol2):
    return [(sol1[0]+sol2[0])/2, (sol1[1]+sol2[1])/2]

def cruza_med_geom(sol1, sol2):
    return [(sol1[0]*sol2[0])**0.5, (sol1[1]*sol2[1])**0.5]

def cruza_blx_alfa(sol1, sol2, alfa = 0.05):
    beta = np.random.uniform(low=-alfa,high=1+alfa, size=1)[0]
    N_x = sol1[0] + (beta * (sol2[0]-sol1[0]))
    N_y = sol1[1] + (beta * (sol2[1]-sol1[1]))
    return [N_x,N_y]

def cruza_aritm(sol1, sol2):
    beta = np.random.uniform(low=0,high=1, size=1)[0]
    N_x1 = (beta * sol1[0]) +((1-beta)*sol2[0])
    N_y1 = (beta * sol1[1]) +((1-beta)*sol2[1])
    N_x2 = ((1-beta)*sol1[0]) + (beta*sol2[0])
    N_y2 = ((1-beta)*sol1[1]) + (beta*sol2[1])
    return [N_x1,N_y1],[N_x2,N_y2]

def cruza_heuristic(sol1, sol2, func_fitness):
    a = func_fitness(sol1[0],sol1[1])
    b = func_fitness(sol2[0],sol2[1])
    if a>b:
        x = [sol1[0],sol2[0]]
        y = [sol1[1],sol2[1]]
    else:
        x = [sol2[0],sol1[0]]
        y = [sol2[1],sol1[1]]
        
        P1x,P2x = x
        P1y,P2y = y
        

    r = np.random.uniform(low=0,high=1, size=1)[0]
    N_x = P1x+ (r * (P1x-P2x))
    N_y = P1y+ (r * (P1y-P2y))
    return [N_x,N_y]

def muta_uniforme(sol, prob_perc, menor, maior):
    a = np.random.uniform(low=menor, high=maior, size=100)
    if np.random.randint(0,100)< prob_perc:
        x = a[0]
    else:
        x = sol[0]
    b = np.random.uniform(low=menor, high=maior, size=100)
    if np.random.randint(0,100)< prob_perc:
        y = b[0]
    else:
        y = sol[1]
    return [x,y]

# mersenne algoritmo de geracao de numeros naouniformemente distribuidos
def muta_n_uniform(sol, porb_perc, menor, maior):
    if np.random.randint(0,100) < porb_perc:
        n_uni = np.linspace(menor,maior, num=100)
        pin = [i+1 for i in range(100)]
        p = [i/(np.sum(pin))for i in pin]
        x = np.random.choice(n_uni, 1, p = p)
    else:
        x = sol[0]
    if np.random.randint(0,100) < porb_perc:
        n_uni = np.linspace(menor,maior, num=100)
        pin = [i+1 for i in range(100)]
        p = [i/(np.sum(pin))for i in pin]
        y = np.random.choice(n_uni, 1, p = p)
    else:
        y = sol[1]
        
    return [x,y]

def muta_gaussiana(sol, prob_perc, desv_pad):
    x,y = sol
    if np.random.randint(0,100)< prob_perc:
        a = np.random.normal(x, desv_pad, 100)
        indice = np.random.randint(0,100)
        x = a[indice]
    else:
        x = x
    if np.random.randint(0,100)< prob_perc:
        b = np.random.normal(y, desv_pad, 100)
        indiceb = np.random.randint(0,100)       
        y = b[indiceb]
    else:
        y=y
        
    return [x,y]

def muta_creep(sol, prob_perc, desv_pad):
    x,y = sol
    if np.random.randint(0,100)< prob_perc:
        a = np.random.normal(0, desv_pad, 100)
        indice = np.random.randint(0,100)
        x = x+a[indice]
    else:
        x = x
    if np.random.randint(0,100)< prob_perc:
        b = np.random.normal(0, desv_pad, 100)
        indiceb = np.random.randint(0,100)       
        y = y+b[indiceb]
    else:
        y=y
        
    return [x,y]


def muta_n_uniform_mult(sol, porb_perc, menor, maior):
    if np.random.randint(0,100) < porb_perc:
        n_uni = np.linspace(menor,maior, num=100)
        pin = [i+1 for i in range(100)]
        px = [i/(np.sum(pin))for i in pin]
        x = np.random.choice(n_uni, 1, p = px)[0]
        pin = [i+1 for i in range(100)]
        py = [i/(np.sum(pin))for i in pin]
        y = np.random.choice(n_uni, 1, p = py)[0]
    else:
        x = sol[0]
        y = sol[1]
        
    return [x,y]



# int main

def genetico(geracoes, populacao_inicial, cortes=2,mutacao_percent=40,quant_muta=2):
    
    inicial = solucoes_rand(populacao_inicial)
    inicial2 = solucoes_rand(populacao_inicial)
    pop_inicial = []
    pop_inicial2 = []
    for i in range(len(inicial)):
        x = bit2float(inicial[i][0:16],-4,4)
        y = bit2float(inicial[i][16:],-4,4)
        pop_inicial = pop_inicial +[[x,y]]
        x2 = bit2float(inicial2[i][0:16],-4,4)
        y2 = bit2float(inicial2[i][16:],-4,4)
        pop_inicial2 = pop_inicial2 +[[x2,y2]]
        

        
  
    populacao_corrente = cp(inicial)
    
  
    for i in range(geracoes):
        
        fit = []
        for c in range(len(populacao_corrente)):
            x = bit2float(populacao_corrente[c][0:16],-4,4)
            y = bit2float(populacao_corrente[c][16:],-4,4)
            fit_f = quatro_g(x,y)
            fit.append(fit_f)
        m_indice = fit.index(max(fit))
        p_indice = fit.index(min(fit))
        elite = populacao_corrente[m_indice]
        populacao_corrente.pop(p_indice)
    
        
        for k in range(len(populacao_corrente)):
            
            predecessor1 = inicial[roleta(pop_inicial)].tolist()
            print("p1",predecessor1)
            predecessor2 = inicial2[roleta(pop_inicial2)].tolist()
            nova_solucao = cruzamento(predecessor1,predecessor2,cortes)
            if np.random.random(1)[0] > mutacao_percent/100:
                nova_solucao = mutacao(nova_solucao, 90, quant_muta)
            populacao_corrente[k] = nova_solucao
            
            
        populacao_corrente.append(elite)
        
        

    fit_final = []
    for f in range(len(populacao_corrente)):
        x = bit2float(populacao_corrente[f][0:16],-4,4)
        y = bit2float(populacao_corrente[f][16:],-4,4)
        fit_f = quatro_g(x,y)
        fit_final.append(fit_f)
    melhor_indice = fit_final.index(max(fit_final))
    

    resultado = populacao_corrente[melhor_indice]
    r_x = bit2float(resultado[0:16],-4,4)
    r_y = bit2float(resultado[16:],-4,4)
    return resultado, r_x, r_y, fit_final[melhor_indice]
 







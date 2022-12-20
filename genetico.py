#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Aug 28 12:50:51 2022

@author: fabianodicheti
"""

import random
import math
import sys
import time

teste = [('batata', 'bat'), ('arroz', 'arr'), ('carne', 'car'), ('feijao', 'fei')]

objetivo = 'prot'

combina = {('bat', 'prot'):[55, 10], ('arr', 'prot'):[44, 20], ('car', 'prot'):[33, 33], ('fei', 'prot'):[44, 11]}

def imprime_numero_combina (lista_numeros):
    combina_id = -1
    soma = 0
    for i in range(len(lista_numeros)//2):
        nome = combina[i][0]
        print(nome)
        primeiro = combina[i][1]
        print(primeiro)
        combina_id += 1
        

# HORAS

converte_tempo = time.strptime('3:39', '%H:%M')

converte_tempo #visualizar composicao da struct

def converte_minutos(horario):
    t = time.strptime(horario, '%H:%M')
    minutos = (t[3]*60) + t[4] # na struct strptime, a hora fica na posicao 3 e os minutos na 4
    return minutos


#FUNCAO FITNESS

def fitness_1(calendario):
    custo_total = 0
    ultimo_horario = 0
    primeiro_horario = 9999
    
    transito_id = -1
    for i in range(len(calendario)//2):
        origem = combina[i][1]
        destino = 'destino'
        transito_id +=1
        ida = combina[(origem, destino)][calendario[transito_id]]
        transito_id +=1
        volta = combina[(destino, origem)][calendario[transito_id]]
        
        custo_total += ida[2]
        custo_total += volta[2]
        
        if ultimo_horario < converte_minutos(ida[1]):
            ultimo_horario = converte_minutos(ida[1])
            
        if primeiro_horario > converte_minutos(volta[0]):
            primeiro_horario = converte_minutos(volta[0])
            
    tempo_total = 0
    transito_id = -1
    for i in range(len(calendario)//2):
        origem = combina[i][1]
        transito_id += 1
        ida = combina[(origem, destino)][calendario[transito_id]]
        transito_id +=1
        volta = combina[(destino, origem)][calendario[transito_id]]
        
        tempo_total += (ultimo_horario - converte_minutos(ida[1]))
        
            
    return [custo_total, tempo_total]




dominio = [(0, 11)]* (len(combina)*2) # VALORES MINIMOS E MAXIMOS P/ GERER NUMEROS ALEATORIOS

def mutacao(dominio, passo, novo_individuo, delta=0.2):
    gene = random.randint(0, len(dominio)-1)
    mutante = novo_individuo
    if random.random() < delta:
        if novo_individuo[gene] != dominio[gene][0]:
            mutante = novo_individuo[0:gene] + [novo_individuo[gene]-passo] + novo_individuo[gene+1:]
        else:
            if novo_individuo[gene] != dominio[gene][1]:
                muntante = novo_individuo[0:gene]+ [novo_individuo[gene]+ passo] +novo_individuo[gene+1:]
                
    return mutante
                
                
def crossover(dominio, individuo1, individuo2):
    gene = random.randint(1, len(dominio)-2)
    return individuo1[0:gene] + individuo2[gene:]
                
            

def genetico(dominio, fitness_fun, tamanho_populacao=100, passo=1, repeticao=500, elitismo=0.4, delta=0.2):
    #populacao inicial
    populacao = []
    for i in range(tamanho_populacao):
        individuo = [random.randint(dominio[i][0], dominio[i][1]) for i in range(len(dominio))]
        populacao.append(individuo)
    print(populacao)
    print(len(populacao))
    numero_elitismo = int(elitismo * tamanho_populacao)
    print('elitismo ', numero_elitismo, ' individuos')
    
    #selecao dos X% melhores // elite
    for i in range(repeticao):
        custo = [(fitness_fun(individuo), individuo) for individuo in populacao]
        print(custo)
        custo.sort()
        print(custo)
        individuo_ordenado = [individuo for (cust, individuo) in custo]
        print(individuo_ordenado)
        populacao = individuo_ordenado[0:numero_elitismo]
    
    #crossover e mutacao
    while len(populacao)< tamanho_populacao:
        ind1 = random.randint(0, numero_elitismo)
        ind2 = random.randint(0, numero_elitismo)
        ind_novo = crossover(dominio, ind1, ind2)
        ind_novo_mutacao = mutacao(dominio, passo, ind_novo, delta)
        populacao.append(ind_novo_mutacao)
        
    return custo[0][1]
    
    
    
    


#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Sep 13 14:23:26 2022

@author: fabianodicheti
"""

import random
import matplotlib.pyplot as plt

F = 0.8
CR = 0.5

def gera_prato():
  alimentos = []
  for i in range(5):
    quant = random.randint(0,199) + random.random()
    alimentos.append(quant)
  return alimentos

def populacao(num):
  pop = []
  for i in range(num):
    pop.append(gera_prato())
  return pop

#alimento1, #alimento2, #alimento3, alimento4, alimento5
def divergencia(prato,mostrar=False):
  carboidratos = prato[0]*0.05 + prato[1]*0.24 + prato[2]*0.26 + prato[3]*0.015 + prato[4]*0.29
  proteinas = prato[0]*0.23 + prato[1]*0.02 + prato[2]*0.026 + prato[3]*0.13 + prato[4]*0.095
  gordura = prato[0]*0.05 + prato[1]*0.00 + prato[2]*0.01 + prato[3]*0.089 + prato[4]*0.014
  total = carboidratos + proteinas + gordura
  soma = sum(prato)

  porcCarb = (carboidratos/total)*100
  porcProt = (proteinas/total)*100
  porcLip = (gordura/total)*100

  difCarb = abs(porcCarb-55)
  difProt = abs(porcProt-30)
  difLip = abs(porcLip-15)

  if mostrar:
    print(porcCarb)
    print(porcProt)
    print(porcLip)
    print(soma)


  difTotal = difCarb + difProt + difLip

  return difTotal

def seleciona3(parental,populacao):
  p2 = []
  tres_vetores = []
  for v in populacao:
    if parental != v:
      p2.append(v)
  for j in range(3):
    aleatorio = random.choice(p2)
    tres_vetores.append(aleatorio)
    p2.remove(aleatorio)
  return tres_vetores

def mutacao(vetorParental,tres):
  cont = 0
  A = tres[0]
  B = tres[1]
  C = tres[2]

  tentativa = []
  while cont < len(vetorParental):
    R = random.random()
    if R < CR:
      X = A[cont] + F*abs(B[cont]-C[cont])
      tentativa.append(X)
    else:
      tentativa.append(vetorParental[cont])
    cont += 1
  return tentativa


def melhorVetor(pop):
  notas = []
  for i in pop:
    notas.append(divergencia(i))
  indice = notas.index(min(notas))
  return pop[indice]


popula = populacao(5)
melhores = []

for i in range(150):
  for j in popula:
    tres = seleciona3(j,popula)
    trial = mutacao(j,tres)
    if divergencia(trial) < divergencia(j):
      popula.remove(j)
      popula.append(trial)

  melhores.append(divergencia(melhorVetor(popula)))
  print(f'Melhor prato: {melhorVetor(popula)}')
  print(f' fitness: {divergencia(melhorVetor(popula))}')
  melhores.append(divergencia(melhorVetor(popula)))
  print()

plt.plot(melhores)
plt.title('Divergências')
plt.xlabel('Iterações')
plt.ylabel('Valor de fitness (divergência)')
plt.show()
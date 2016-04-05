#!/usr/bin/env python
#encoding: utf-8

import sys
import copy


#e1 = [ [2,0], [4,0], [1,2] ]
#e2 = [ [2,0], [4,0], [1,2], [1,9] ]
#e3 = [ [6,0], [2,0], [4,0], [1,2], [1,9] ]


min_ataques = range(99)


def main(*args):
	"""
	Obtiene la lista de enemigos por stdin, corre el 
	backtracking para obtener la solución de la instancia
	del problema, y muestra la solución por stdout en el 
	formato pedido.
	"""

	enemigos = obtenerListaEnemigos()
	backtracking(enemigos, [[]], 0)
	mostrar_solucion()


def obtenerListaEnemigos():
	"""
	Obtiene la lista de enemigos por stdin.
	"""
	cant_enemigos = int(raw_input())
	enemigos = []
	while cant_enemigos > 0:
		line = raw_input().strip().split(' ')
		if len(line) != 2:
			print "El valor ingresado no corresponde a una posicion." \
			" Intente nuevamente."
			continue
		enemigo = map(int, line)
		enemigos.append(enemigo)
		cant_enemigos -= 1
	return enemigos


def backtracking(enemigos, ataques, nroAtaque):
	"""
	Realiza un backtracking sobre a lista de enemigos para determinar
	el menor número de ataques necesarios para derrotarlos a todos.
	"""
	# Si no hay mas enemigos, entonces los ataqué a todos
	# y tengo que evaluar qué tan buena es mi solución
	if len(enemigos) == 0:
#		reporte(enemigos, ataques, nroAtaque)
		global min_ataques
		if len(ataques) < len(min_ataques):
			min_ataques = copy.deepcopy(ataques)	# se guarda una copia de los ataques

	# Sino, quedan enemigos por atacar
	else:

		# Elijo un enemigo
		for enemigo in enemigos:
			idx = enemigos.index(enemigo)
			enemigos.remove(enemigo)
			atacarEnAtaqueActual(enemigo, enemigos, ataques, nroAtaque)
			atacarEnNuevoAtaque(enemigo, enemigos, ataques, nroAtaque)
			enemigos.insert(idx, enemigo)


def atacarEnAtaqueActual(enemigo, restoEnemigos, ataques, nroAtaque):
	"""
	Continúa la exploración del árbol de posibilidades, intentando 
	derrotar al enemigo con el ataque actual.
	"""

	# Tomo la lista de enemigos siendo atacados actualmente
	atacados = ataques[nroAtaque]

	if len(atacados) is 0:
		ataques[nroAtaque] = [enemigo]
		backtracking(restoEnemigos, ataques, nroAtaque)
		ataques[nroAtaque]= []
	

	# Si los atacados están en linea con el nuevo enemigo, 
	# entonces lo agrego en este ataque
	elif alineados(enemigo, atacados):
		ataques[nroAtaque].append(enemigo)
		backtracking(restoEnemigos, ataques, nroAtaque)
		ataques[nroAtaque].remove(enemigo)
	
	# Sino, el enemigo debe ser derrotado en un nuevo ataque
	# pero eso ya se lanza en el loop general
	else:
		pass


def atacarEnNuevoAtaque(enemigo, restoEnemigos, ataques, nroAtaque):
	"""
	Continúa la exploración del árbol de posibilidades, intentando 
	derrotar al enemigo con un nuevo ataque.
	"""

	# Corro un BT derrotando al enemigo con un nuevo ataque 
	if len(ataques[nroAtaque]) > 0:
		ataques.append([enemigo])
		nroAtaque += 1
		backtracking(restoEnemigos, ataques, nroAtaque)
		nroAtaque -= 1
		ataques.pop(-1)


def alineados(enemigo, enemigos):
	"""
	Dada una lista de enemigos, indica si estos se encuentran 
	alineados entre sí.
	"""
	if len(enemigos) == 0:
		# Es el unico atacado. Trivial.
		return True
	
	elif len(enemigos) == 1:
		# Dos posiciones cualesquiera forman
		# una recta.
		return True
	else:
		# Me fijo que enemigo esté alineado con 
		# dos otros enemigos cualesquiera distintos
		# entre si. 
		e1 = enemigos[0]
		e2 = enemigos[1]

		termino1 = e2[1] - e1[1]
		termino2 = enemigo[0] - e1[0]
		termino3 = enemigo[1] - e1[1]
		termino4 = e2[0] - e1[0]
		return termino1*termino2 == termino3*termino4


def reporte(enemigos, ataques, nroAtaque):
	"""
	Muestra por pantalla la lista de enemigos, qué enemigos son
	derrotados en cada ataque y la cantidad de ataques realizados.
	"""
	print 'enemigos:', enemigos
	print 'ataques:', len(ataques)
	for ataque in ataques:
		print 'ataque {0}: {1}'.format(ataques.index(ataque)+1, ataque)
	print 'sigAtaque:', nroAtaque+1
	print


def mostrar_solucion():
	"""
	Imprime la solución por stdout en el formato indicado.
	"""

	# global min_ataques
	# print min_ataques
	# print

	# print len(min_ataques)
	# for ataque in min_ataques:
	# 	print len(ataque),
	# 	for enemigo in ataque:
	# 		print enemigo, 
	# 	print


if __name__ == '__main__':
	main(sys.argv)

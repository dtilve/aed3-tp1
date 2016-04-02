import numpy as np
import matplotlib.pyplot as plt

top = 2**17
#x = np.arange(1, top, **2)

xdata = [pow(2,i) for i in range(0,17)]
ydata = [1e-06,
5e-06,
6e-06,
7e-06,
1.2e-05,
1.3e-05,
1.4e-05,
1.5e-05,
1.7e-05,
2.1e-05,
2.9e-05,
4.7e-05,
8.7e-05,
0.00017,
0.000346,
0.000733,
0.001519]

plt.plot(xdata,ydata)
plt.show()

#plt.plot(t, t, 'r--', t, t*np.log2(t), 'bs', t, t**2, 'g^')
#r-- representa r de red -- porque lo dibuja con lineas punteadas, - es linea sin puntear
#bs representa b de blue s de squares
#g^ representa g de green y ^ de que son triangulos
#plt.show()

#t2 = [8,20,22,25,32,34,42,55]
#plt.plot(t,t*10,'b-',t,t2,'g--')
#plt.show()

#en este grafico graficamos los puntos (1,8), (2,20), (3,22)... hasta el (8,55)
#junto con la curva que representa una complejidad lineal que pasa por encima de la curva

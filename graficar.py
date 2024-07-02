import matplotlib.pyplot as plt
import pandas as pd

# Leer el archivo .txt
data = pd.read_csv('regresion_lineal.txt')

# Separar los puntos según el criterio dado
above_1808 = data[data['Word count'] > 1808]
below_1808 = data[data['Word count'] <= 1808]

# Graficar los puntos
plt.figure(figsize=(10, 6))
plt.scatter(above_1808['Word count'], above_1808['Shares'], color='red', label='Word count > 1808')
plt.scatter(below_1808['Word count'], below_1808['Shares'], color='blue', label='Word count <= 1808')

# Graficar la regresión lineal
x = data['Word count']
y = data['Prediction']
plt.plot(x, y, color='green', label='Regresión Lineal')

plt.xlabel('Word count')
plt.ylabel('Shares')
plt.title('Regresión Lineal de Word count vs Shares')
plt.legend()
plt.grid(True)
plt.show()

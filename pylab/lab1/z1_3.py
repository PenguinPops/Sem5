import numpy as np
import matplotlib.pyplot as plt

# Definiowanie zakresu dla x
x = np.arange(-5, 5, 0.01)

# Definiowanie funkcji
def f1(x):
    return np.tanh(x)

def f2(x):
    return (np.exp(x) - np.exp(-x)) / (np.exp(x) + np.exp(-x))

def f3(x):
    return 1 / (1 + np.exp(-x))

def f4(x):
    return np.where(x > 0, x, 0)

def f5(x):
    return np.where(x > 0, x, np.exp(x) - 1)

# Tworzenie wykresów
plt.figure(figsize=(10, 8))

# Wykres dla tanh(x)
plt.subplot(2, 3, 1)
plt.plot(x, f1(x), label="tanh(x)", color='b')
plt.title('f(x) = tanh(x)')
plt.grid(True)

# Wykres dla (e^x - e^-x) / (e^x + e^-x)
plt.subplot(2, 3, 2)
plt.plot(x, f2(x), label="(e^x - e^-x) / (e^x + e^-x)", color='g')
plt.title('f(x) = (e^x - e^-x) / (e^x + e^-x)')
plt.grid(True)

# Wykres dla 1 / (1 + e^-x)
plt.subplot(2, 3, 3)
plt.plot(x, f3(x), label="1 / (1 + e^-x)", color='r')
plt.title('f(x) = 1 / (1 + e^-x)')
plt.grid(True)

# Wykres dla x (x > 0), 0 (x <= 0)
plt.subplot(2, 3, 4)
plt.plot(x, f4(x), label="x (x > 0), 0 (x <= 0)", color='m')
plt.title('f(x) = x (x > 0), 0 (x <= 0)')
plt.grid(True)

# Wykres dla x (x > 0), e^x - 1 (x <= 0)
plt.subplot(2, 3, 5)
plt.plot(x, f5(x), label="x (x > 0), e^x - 1 (x <= 0)", color='c')
plt.title('f(x) = x (x > 0), e^x - 1 (x <= 0)')
plt.grid(True)

plt.tight_layout()
plt.show()
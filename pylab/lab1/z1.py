# funkcje numpy:

import numpy as np

arr = np.array([[2,3,5,1],
                [5,1,2,8],
                [5,1,6,-1]])

pojedynczy_element = arr[0,3]
pojedynczy_element_od_konca = arr[-3,-1]
kolumna = arr[:,2]
wiersz = arr[2,:]
obszar = arr[0:2,1:4]
obszar_pomijajac_koncowe_indeksy = arr[:2,1:]
parzyste_kolumny = arr[:,::2]
nieparzyste_kolumny = arr[:,1::2]
odwrocone_kolumny = arr[:,::-1]

indeksy = [1, 1, -1]
wybrane_kolumny= arr[:, indeksy]
maska = arr>2
arr_maskowane = arr[maska]

# print(arr)
# print(wybrane_kolumny)
# print(maska)
# print(arr_maskowane)

# arr [ wiersze, kolumny]
# arr [ start:stop:step, start:stop:step] , uwaga bo 
# arr [ [lista indeksów] ]
# arr [ maska ]
# sumy_kolumn = arr.sum(axis=0)
# sumy_wierszy = arr.sum(axis=1)
# bardziej zaawansowany wzór arr1_0_1 = (arr1-arr1.min())/(arr1.max()-arr1.min())

# metody i atrybuty klasy ndarray:
# .ndim, .shape, .T
# .sum, .prod, .mean, .std, .reshape(nowe_rozmiary), .sort(oś, metoda, kolejność)

# funkcje pandas:

import pandas as pd
# data_excel = pd.read_excel("dane_excela.xlsx")
# data_csv = pd.read_csv("dane_oddzielone_sredniami.csv" , sep=";")

# nazwy_kolumn = list(data_csv.columns)
# wartosci_kolumn = data_csv.values

# funkcje matplotlib:

import matplotlib.pyplot as plt

x = np.arange(0, 10, 0.1)
y = np.sin(x**2 - 5*x + 3)
plt.scatter(x, y)
plt.plot(x, y)
plt.xlabel('x')
plt.ylabel('y')
plt.title('Wykres funkcji sin(x^2 - 5x + 3)')


fig, ax = plt.subplots(1,2, figsize = (10, 5))
ax[0].plot(x,y)
ax[0].set_xlabel("x")
ax[0].set_ylabel("y")
ax[1].scatter(x,y)
ax[1].set_xlabel("x")
ax[1].set_ylabel("y")
fig.tight_layout()

# plt.show()

# Zadanie 1
# wczytaj dane z pliku xlsx do zmiennej pandas DataFrame
# wyswietl wartosci jako tablice dwuwymiarowa numpy oraz nazwy kolumn jako liste 

DataFrame = pd.read_excel("dane.xlsx")
arr2 = np.array(DataFrame)
# print(arr2)

# Znajdź tablicę dwuwymiarową, która będzie wynikiem różnicy dwóch tablic: pierwsza
# będzie zawierała wszystkie kolumny oraz parzyste wiersze tablicy danych
# wejściowych, druga – wszystkie kolumny i nieparzyste wiersze tablicy danych
# wejściowych. Numeracja wierszy oraz kolumn zaczyna się od 0!

arr3 = arr2[::2, :]
arr4 = arr2[1::2, :]

arr5 = arr4 - arr3

print(arr5)
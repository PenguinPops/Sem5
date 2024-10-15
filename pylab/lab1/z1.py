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
print(arr2)

#[[1 'imie1' 'nazwisko1' 11 123456]
#  [2 'imie2' 'nazwisko2' 12 78910]
#  [3 'imie3' 'nazwisko3' 13 34364]
#  [4 'imie4' 'nazwisko4' 14 -10182]
#  [5 'imie5' 'nazwisko5' 15 -54728]
#  [6 'imie6' 'nazwisko6' 16 -99274]
#  [7 'imie7' 'nazwisko7' 17 -143820]
#  [8 'imie8' 'nazwisko8' 18 -188366]
#  [9 'imie9' 'nazwisko9' 19 -232912]
#  [10 'imie10' 'nazwisko10' 20 -277458]
#  [11 'imie11' 'nazwisko11' 21 -322004]
#  [12 'imie12' 'nazwisko12' 22 -366550]
#  [13 'imie13' 'nazwisko13' 23 -411096]
#  [14 'imie14' 'nazwisko14' 24 -455642]
#  [15 'imie15' 'nazwisko15' 25 -500188]
#  [16 'imie16' 'nazwisko16' 26 -544734]
#  [17 'imie17' 'nazwisko17' 27 -589280]
#  [18 'imie18' 'nazwisko18' 28 -633826]
#  [19 'imie19' 'nazwisko19' 29 -678372]]

# Znajdź tablicę dwuwymiarową, która będzie wynikiem różnicy dwóch tablic: pierwsza
# będzie zawierała wszystkie kolumny oraz parzyste wiersze tablicy danych
# wejściowych, druga – wszystkie kolumny i nieparzyste wiersze tablicy danych
# wejściowych. Numeracja wierszy oraz kolumn zaczyna się od 0!

# 1. Wydziel parzyste i nieparzyste wiersze
even_rows = arr2[::2]  # Parzyste wiersze
odd_rows = arr2[1::2]  # Nieparzyste wiersze

# 2. Aby obie tablice miały tę samą liczbę wierszy, ucinamy ostatni parzysty wiersz
even_rows = even_rows[:len(odd_rows)]

# 3. Odejmujemy tylko kolumny z wartościami liczbowymi: [0, 3, 4]
# Konwersja do liczb
even_values = even_rows[:, [0, 3, 4]].astype(np.int64)
odd_values = odd_rows[:, [0, 3, 4]].astype(np.int64)

# 4. Wykonujemy różnicę
result = even_values - odd_values

# 5. Wynik
print(result)

# Zadanie 2

# Przekształć dane w sposób następujący: od każdej wartości liczbowej odejmij średnią obliczoną
# dla całej tablicy oraz podziel przez odchylenie standardowe wyznaczone dla całej
# tablicy. Podpowiedź: skorzystaj z metod mean oraz std.

arr3 = arr2.copy()

# 1. Wydzielamy wszystkie wartości liczbowe z tablicy (kolumny 0, 3 i 4)
num_values = arr2[:, [0, 3, 4]].astype(np.float64)

# 2. Obliczamy średnią i odchylenie standardowe dla wszystkich wartości liczbowych
mean_value = np.mean(num_values)
std_value = np.std(num_values)

# 3. Standaryzujemy wartości (odjęcie średniej i podzielenie przez odchylenie standardowe)
standardized_values = (num_values - mean_value) / std_value

# 4. Wstawiamy z powrotem wystandaryzowane wartości do tablicy
arr3[:, [0, 3, 4]] = standardized_values

# 5. Wynik
print(arr3)

# Zadanie 3

# Wykonaj zadanie z podpunktu 2 dla oddzielnych kolumn pierwotnej tablicy, czyli
# wyznaczając średnią oraz odchylenie standardowe dla oddzielnych kolumn.
# Podpowiedź: aby uniknąć dzielenia przez zero, do wyniku wyrażenia arr.std(axis=0)
# dodaj wynik funkcji np.spacing(arr.std(axis=0)).

arr4 = arr2.copy()

# 1. Wydzielamy kolumny numeryczne (0, 3, 4)
num_values = arr2[:, [0, 3, 4]].astype(np.float64)

# 2. Obliczamy średnią oraz odchylenie standardowe dla każdej kolumny osobno
means = num_values.mean(axis=0)
stds = num_values.std(axis=0)

# 3. Dodajemy do odchylenia standardowego np.spacing(), aby uniknąć dzielenia przez 0
stds_adjusted = stds + np.spacing(stds)

# 4. Standaryzujemy wartości dla każdej kolumny osobno
standardized_values = (num_values - means) / stds_adjusted

# 5. Wstawiamy znormalizowane wartości z powrotem do tablicy
arr4[:, [0, 3, 4]] = standardized_values

# 6. Wynik
print(arr4)

# Zadanie 4

# Dla każdej kolumny pierwotnej tablicy policz współczynnik zmienności, definiowany
# jako stosunek średniej do odchylenia standardowego, zabezpiecz się przed dzieleniem
# przez 0 podobnie do poprzedniego punktu.

# 1. Wydzielamy kolumny numeryczne (0, 3, 4)
num_values = arr2[:, [0, 3, 4]].astype(np.float64)

# 2. Obliczamy średnią i odchylenie standardowe dla każdej kolumny
means = num_values.mean(axis=0)
stds = num_values.std(axis=0)

# 3. Dodajemy np.spacing() do średniej, aby uniknąć dzielenia przez 0
means_adjusted = means + np.spacing(means)

# 4. Obliczamy współczynnik zmienności (odchylenie standardowe / średnia)
coefficients_of_variation = stds / means_adjusted

# 5. Wynik
for i, cv in enumerate(coefficients_of_variation):
    print(f"Współczynnik zmienności dla kolumny {i}: {cv}")

# Zadanie 5
    
# Znajdź kolumnę o największym współczynniku zmienności.
    
for i, cv in enumerate(coefficients_of_variation):
    if cv == np.max(coefficients_of_variation):
        print(f"Kolumna o największym współczynniku zmienności: {i}")

# Zadanie 6
        
# Dla każdej kolumny pierwotnej tablicy policz liczbę elementów o wartości większej,
# niż średnia tej kolumny.
        
# 1. Wydzielamy kolumny numeryczne (0, 3, 4)
num_values = arr2[:, [0, 3, 4]].astype(np.float64)

# 2. Obliczamy średnią dla każdej kolumny
means = num_values.mean(axis=0)

# 3. Obliczamy liczbę elementów większych od średniej dla każdej kolumny
counts = [np.sum(col > mean) for col, mean in zip(num_values.T, means)]

# 4. Wynik
for i, count in enumerate(counts):
    print(f"Liczba elementów większych od średniej w kolumnie {i}: {count}")

# Zadanie 7

# Znajdź nazwy kolumn w których znajduje się wartość maksymalna. Podpowiedź: listę
# stringów można również przekształcić na tablicę numpy, po czym można będzie dla niej
# zastosować maskę.
    
# 1. Wydzielamy kolumny numeryczne (0, 3, 4)
num_values = arr2[:, [3, 4]].astype(np.float64)

# 2. Przekształcamy kolumny stringów na tablicę numpy
str_values = arr2[:, [1, 2]]

# 3. Znajdujemy indeksy maksymalnych wartości dla każdej kolumny
max_indices = np.argmax(num_values, axis=0)

# 4. Wybieramy nazwy kolumn dla maksymalnych wartości
max_names = str_values[max_indices]

# 5. Wynik
print(max_names) # ???????

# Zadanie 8

# Znajdź nazwy kolumn w których jest najwięcej elementów o wartości 0. Podpowiedź:
# wartości w tablicy wartości logicznych można sumować, zakładając, że zawiera ona
# liczby całkowite, rzutowanie będzie wykonane automatycznie.

# 1. Wydzielamy kolumny numeryczne (0, 3, 4)
num_values = arr2[:, [0, 3, 4]].astype(np.float64)

# 2. Obliczamy maskę dla wartości 0
zero_mask = num_values == 0

# 3. Obliczamy liczbę zer dla każdej kolumny
zero_counts = zero_mask.sum(axis=0)

# 4. Wynik
for i, count in enumerate(zero_counts):
    print(f"Liczba zer w kolumnie {i}: {count}")

# Zadanie 9

# 1. Wydzielamy kolumny liczbowe
num_values = arr2[:, [0, 3, 4]].astype(np.float64)

# 2. Sumujemy wartości na pozycjach parzystych (wiersze 0, 2, 4, ...)
even_sum = num_values[::2, :].sum(axis=0)

# 3. Sumujemy wartości na pozycjach nieparzystych (wiersze 1, 3, 5, ...)
odd_sum = num_values[1::2, :].sum(axis=0)

# 4. Sprawdzamy, które kolumny spełniają warunek (suma parzysta > suma nieparzysta)
condition = even_sum > odd_sum

# 5. Nazwy kolumn
column_names = ["kolumna 1", "kolumna 4", "kolumna 5"]

# 6. Wyświetlamy nazwy kolumn, które spełniają warunek
result = np.array(column_names)[condition]

print("Kolumny, w których suma elementów na pozycjach parzystych jest większa niż na nieparzystych:", result)


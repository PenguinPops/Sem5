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

print(arr)
print(wybrane_kolumny)
print(maska)
print(arr_maskowane)

# arr [ wiersze, kolumny]
# arr [ start:stop:step, start:stop:step]
# arr [ [lista indeksów] ]
# arr [ maska ]
# 
import pandas as pd
import numpy as np

# Load the Excel file
DataFrame = pd.read_excel("dane.xlsx")

# Display the DataFrame to understand its structure
print(DataFrame)

# Select only numeric columns
numeric_columns = DataFrame.select_dtypes(include=[np.number])

# Check if there are numeric columns to calculate correlation
if not numeric_columns.empty:
    # Generate the correlation matrix
    DataFrame_corr = numeric_columns.corr()
    
    # Display the correlation matrix
    print("Correlation matrix:")
    print(DataFrame_corr)
else:
    print("No numeric columns found for correlation.")

# a pomocą modułu pyplot wygeneruj dwuwymiarową macierz wykresów punktowych
# (scatter). Możesz skorzystać z pętli for. Zaobserwuj, jak wyglądają wykresy skorelowanych
# oraz nieskorelowanych danych. Jak na podstawie wykresu można wyznaczyć znak
# współczynnika korelacji?
    
import matplotlib.pyplot as plt

# Get the number of columns in the DataFrame
n_columns = DataFrame.shape[1]

# Create a 2D matrix of scatter plots
fig, ax = plt.subplots(n_columns, n_columns, figsize=(10, 10))

# Loop through the columns to create scatter plots
for i in range(n_columns):
    for j in range(n_columns):
        if i == j:
            ax[i, j].hist(DataFrame.iloc[:, i])
            ax[i, j].set_title("Histogram of column " + str(i))
        else:
            ax[i, j].scatter(DataFrame.iloc[:, i], DataFrame.iloc[:, j])
            ax[i, j].set_xlabel("Column " + str(i))
            ax[i, j].set_ylabel("Column " + str(j))
            ax[i, j].set_title("Scatter plot of columns " + str(i) + " and " + str(j))

# Adjust the layout of the subplots
plt.tight_layout()
plt.show()
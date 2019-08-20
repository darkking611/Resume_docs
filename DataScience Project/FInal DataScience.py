import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.axes as axes
import matplotlib.scale as scl

########################      Data-Preprocessing      ##################################
df = pd.read_excel (r'C:\Users\Asus\Downloads\Telegram Desktop\INDIA.xlsx')
#print (df)
sheet_1 = pd.read_excel(r'C:\Users\Asus\Downloads\Telegram Desktop\INDIA.xlsx',sheet_name = 1)
sheet_2 = pd.read_excel(r'C:\Users\Asus\Downloads\Telegram Desktop\INDIA.xlsx',sheet_name = 2)
A = sheet_1["Active eonline population"]
C = sheet_2["distance"]
arr1 = sheet_2["Number"]
#sheet_2
#arr1


#######################
M1M2 = []
counter=0
for i in range(len(A)):
    for j in range(len(A)):
        if(i!=j):
            M1M2.append(A[i]*A[j])
            k=i+j-1
            print(M1M2[k])
            counter=counter+1
#print(counter)
            
arr2 = []
for i in range(len(M1M2)):
    arr2.append(M1M2[i]/C[i])
    print(arr2[i])
    
print(np.corrcoef(arr1, arr2)[0,1])

from pydoc import help
from scipy.stats.stats import pearsonr
#help(pearsonr)
pearsonr(arr1,arr2)

plt.scatter(arr1,arr2)
plt.xlabel("Number_of_transition")
plt.ylabel("(M1*M2)/R")
#axes.Axes.set_yscale('log')
#axes.Axes.set_xscale('log')
scl.LogScale(x)
plt.show()
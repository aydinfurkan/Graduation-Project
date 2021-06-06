from kohonen import kohonen
import numpy as np
import matplotlib.pyplot as plt
from random import randint

def test(X, weights): # test

    winner_weight = np.argmin((weights - X)**2) # kazanan ağırlık

    return winner_weight

weights_number = 15

weights = []
for w in range(weights_number):
    weights.append(np.loadtxt('weights%s.csv' %(w), delimiter =','))
weights = np.array(weights)


test_dataset = np.loadtxt('test_data3.csv', delimiter =',')


scol = 1200
srow = 400
col0 = 2**8
row0 = 2**6
test_dataset = test_dataset[srow:srow+row0-1,scol:scol+col0-1]

l = np.shape(test_dataset)[1]

result = []
for i in range(weights_number):
    result.append([])

test_dataset_flat = test_dataset.flatten()
for i in range(len(test_dataset_flat)):
    winner_weight = test(test_dataset_flat[i], weights) # her veri için kazanan ağırlık bulunması

    result[winner_weight].append((i%l,int(i/l))) # sınıf bilgisine göre verilerin ayrılması

print("Test bitti.")

fig, (ax1, ax2) = plt.subplots(1, 2)

minvalue = 8e-6
maxvalue = 2e-4

# sonucun çizdirilmesi
ax1.imshow(test_dataset, interpolation='nearest', cmap='gray', vmin=minvalue, vmax=maxvalue, aspect='auto')
ax2.imshow(test_dataset, interpolation='nearest', aspect='auto')

colors = ["darkblue","blue","blue","mediumblue","cyan","green","forestgreen","lightcoral","indianred","brown","firebrick","maroon", "darkred", "yellowgreen", "greenyellow"]

for f in range(weights_number):
    ax2.scatter([i[0] for i in result[f]],[i[1] for i in result[f]], color = colors[f])

water_count = len(result[0])+len(result[1])+len(result[2])+len(result[3])
fig.suptitle("Su oranı : %s" %((water_count/len(test_dataset_flat))*100), fontsize=20)
plt.show()
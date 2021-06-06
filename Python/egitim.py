from kohonen import kohonen
import numpy as np
import matplotlib.pyplot as plt

def plot_weight_plane(w): # Ağırlık yoğunluk düzlemi çizdirme (1 boyutlu ağırlıklar için)
        
    fig, ax = plt.subplots()
    ax.imshow(w.reshape(1,len(w)))

    for i in range(len(w)):
        ax.text(i, 0, w[i],ha="center", va="center", color="k")
            
    fig.tight_layout()
    plt.show()

train_dataset = []
# eğitim seti okuma
for i in range(1,5):
    X = np.loadtxt('train_data%s.csv'%i, delimiter =',')
    train_dataset.extend(X.flatten())


neuron_list = (12,1,1) # ağ nöron yapısı
x_size = 1 # giriş boyutu

neuron_number =  np.prod(neuron_list)
weights = np.random.rand(neuron_number, x_size)*1e-5 # başlangıç ağırlıkları

K = kohonen(neuron_list, x_size, weights) # ağın oluşturulması

K.learn(train_dataset, 0.1, 0.8, 1000, 5000) # eğitim (X , öğrenme hızı, sigma)

plot_weight_plane(K.weights)
plot_weight_plane(K.weight_density)

for w in range(len(K.weights)):
    np.savetxt('weights%s.csv' %(w), K.weights[w], delimiter=',')

import numpy as np
import math
import random
import matplotlib.pyplot as plt

class kohonen(object):

    def __init__(self, neuron_list, x_size, weights): # neuron list = noron dizisi 3 boyutlu olmalıdır kullanılmayan boyutlar 1 yapılmalıdır.

        self.neuron_list = neuron_list
        neuron_number =  np.prod(neuron_list)
        self.weights = weights
        
        # ağırlıkların arasındaki komşuluk bağını kurma, öklid uzaklığı kullanılmıştır.

        self.weights_range = []
        for i in range(neuron_number):
            current_weight_range = []
            x0 = int(i/(neuron_list[1]*neuron_list[2]))
            y0 = int(i/neuron_list[2])%neuron_list[1]
            z0 = i%neuron_list[2]
            for f in range(neuron_number):
                x = int(f/(neuron_list[1]*neuron_list[2]))
                y = int(f/neuron_list[2])%neuron_list[1]
                z = f%neuron_list[2]
                
                current_weight_range.append(self.euclid(x0-x, y0-y, z0-z))

            self.weights_range.append(current_weight_range)

    def euclid(self, x, y, z):
        return math.sqrt(x**2 + y**2 + z**2)
    
    def gaussian(self, x, sigma):
        x = np.array(x)
        return np.exp(-( x**2 / ( 2.0 * sigma**2 ) ) )

    def shuffle_two(self, a, b):
        a = np.array(a)
        b = np.array(b)
        p = np.random.permutation(len(a))
        return (a[p], b[p])

    def plot_weights(self, X):
        #colors = ["darkblue", "blue", "mediumblue", "cyan", "lime", "green","magenta","purple", "red", "maroon" ,"gray" ,"white"]
        #colors = ["darkblue", "blue", "mediumblue", "cyan", "lime"]
        plt.scatter(X, len(X)*[1])
        plt.scatter(self.weights, len(self.weights)*[1])#, c=colors)

        plt.show(block=False)
        plt.pause(0.1)
        plt.cla()

    def learn(self, X, n=0.1, sigma=0.5, acc_n=10000, acc_sigma=5000): # acc_sigma - sigma azalma katsayısı , acc_n - öğrenme hızı azalma katsayısı

        pre_winner_weights = []
       
        i = 0
        count = 0 # yerleştirme aşaması sayıcısı
        
        # Yerleştirme aşaması
        while (count < 5):
            self.plot_weights(X)
            new_n = n* np.exp(-(i/acc_n)) # yeni öğrenme hızı belirleme
            new_sigma = sigma * np.exp(-(i/acc_sigma)) # yeni sigma belirleme
            
            winner_weights = self.train(X, new_n, new_sigma) # kazanan ağırlıklar

            count = count+1 if(pre_winner_weights == winner_weights) else 0
            
            pre_winner_weights = winner_weights

            
            (pre_winner_weights, X) = self.shuffle_two(pre_winner_weights, X)
            pre_winner_weights = pre_winner_weights.tolist()
            X = X.tolist()
            
            i += 1

            
            print(count, i)

        print("Yerleştirme bitti. (",i,")")

        # Öğrenme aşaması
        for f in range(i,i+100):
            new_n = n* np.exp(-(f/acc_n)) # yeni öğrenme hızı belirleme
            new_sigma = sigma * np.exp(-(f/acc_sigma)) # yeni sigma belirleme
            
            winner_weights = self.train(X, new_n, new_sigma)

            random.shuffle(X)

        print("Öğrenme bitti. (",f,")")

        plt.close("all")

        # Ağırlık yoğunluk belirleme
        self.weight_density = np.zeros(len(self.weights))
        for i in range(len(winner_weights)):
            self.weight_density[int(winner_weights[i])] += 1
        
        return self
    
    def train(self, X, n, sigma): # kazanan ağırlığı hesaplama

        winner_weights = []

        for current_x in X:

            winner_weight = np.argmin(np.sum((self.weights - current_x)**2, axis=1)) # kazanan ağırlık
        
            g_winner = self.gaussian(self.weights_range[winner_weight], sigma)[np.newaxis].T # kazanan ağırlığın sigma kullanılarak komşularına olan gauss uzaklığını belirleme

            self.weights += g_winner * n * (current_x - self.weights) # ağırlıkları gauss uzaklığına göre değiştirme

            winner_weights.append(winner_weight) 

        return winner_weights # kazanan ağırlıklar

    def test(self, X): # test

        winner_weight = np.argmin(np.sum((self.weights - X)**2, axis=1)) # kazanan ağırlık

        return winner_weight




import matplotlib.pyplot as plt

x=[]

for i in range(1000,5001,500):
    x.append(i)
    
bubble=[38.87,56.06,65.39,104.12,150.83,202.79,265.94,338.96,419.88]
selection=[9.33,12.87,19.18,29.76,42.78,58.27,75.45,95.66,118.07]
insertion=[8.67,7.43,12.94,20.58,28.63,39.25,50.78,64.53,79.20]
quick=[0.486,0.493,0.611,0.832,0.989,1.179,1.363,1.679,1.707]
merge=[0.86,0.623,0.85,1.073,1.306,1.553,1.803,2.062,2.370]

plt.plot(x,bubble,color='purple',marker='o',label='Bubble Sort')
plt.plot(x,selection,color='red',marker='^',label='Selection Sort')
plt.plot(x,insertion,color='blue',marker='s',label='Insertion Sort')
plt.plot(x,merge,color='green',marker='D',label='Merge Sort')
plt.plot(x,quick,color='orange',marker='X',label='Quick Sort')

plt.xlabel('No. of Elements')
plt.ylabel('Time in milliseconds')
plt.legend()
plt.show()
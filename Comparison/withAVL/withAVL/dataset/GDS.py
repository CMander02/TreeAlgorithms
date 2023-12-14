import numpy as np

sizes = [10, 100, 1000, 10000, 100000, 1000000, 10000000]

for size in sizes:
    random_integers = np.random.randint(1, 10000, size=size)
    file_path = 'data_'+str(size)+'.txt'
    with open(file_path, 'w') as file:
        for number in random_integers:
            file.write(str(number) + '\n')

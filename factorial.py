from time import time, sleep
import sys

def factorial(num, res):
    if num == 1:
        return res
    else:
        res *= num
        return factorial(num - 1, res)

sleep(4)
start = time()
fact = factorial(int(sys.argv[1]), 1)
end = time()

print(f'Resultado: {fact}\nTiempo: {end - start}')



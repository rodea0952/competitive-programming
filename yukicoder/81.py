from decimal import Decimal

n = int(input())
a = [Decimal(input()) for i in range(n)]

print('{:.10f}'.format(sum(a)))
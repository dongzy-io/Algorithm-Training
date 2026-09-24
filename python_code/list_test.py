a=[x*x for x in range(5)]
for x in a:
    print(x)
a.append(101)
a.sort(key=lambda x: -x)
for i,x in enumerate(a):
    print(f"The {i}th element is {x}")
for x in range(1,3):
    print(x)
print(min(a))
冒泡排序
---

没啥好说的，注意添加判断，而不是单纯地套两层循环

代码:
```python

import random

def bubble_sort(alist):
    n = len(alist)
    for j in range(n - 1):
        count = 0
        for i in range(0, n - 1 - j):
            if alist[i] > alist[i + 1]:
                alist[i], alist[i + 1] = alist[i + 1], alist[i]
                count += 1
        if 0 == count:
            break

A = []
s = random.randint(5, 100)
for i in range(0, s):
    A.append(random.randint(0, 1000))

print A
bubble_sort(A)
print A
```

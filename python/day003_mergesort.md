分治
---
分治的核心是把一个大问题(比如计算量大，复杂度高)的问题，按照规则拆分为规模更小的同类问题。这样就可以继续拆分，知道规模达到可以处理的地步。所以分治的核心在于如何提取问题的特征，判建立合适的模型，然后找到“分治”条件。最后把答案统一起来（这里就是归并的含义了）。

总而言之，这种思想就是把大规模问题拆分为小规模问题。然后逐一解决，再逐步合并答案

以排序来说，对于一个长度任意的输入数组，我们可以认为它是非常长的数组(规模大)。按照分治的思想
1. 找到合适的模型：把数组拆分为左右两端，问题就变为如何对左端排序，和如何对右端排序。这样规模就降低一把
2. 找到合适的“分治条件”，合适就是在这个问题规模我们可以很简单地进行处理。对于排序来说最简单无外乎就一个数(或两个数)的规模，对于一个数，那么没啥好排序的直接返回。若是两个数也简单，a>b交换位置返回，否者直接返回。
3. 最后问题变为两个有序列表如何排序的问题

以分治排序为例：
```python
import random


def m_sort(a, b):
    i = j = 0
    res = []
    while i < len(a) and j < len(b):
        if a[i] > b[j]:
            res.append(b[j])
            j += 1
        else:
            res.append(a[i])
            i += 1
    if i < len(a):
        res += a[i:]
    else:
        res += b[j:]
    return res


def merage(A):
    mid = len(A)/2
    if mid > 0:
        a = A[:mid]
        b = A[mid:]
        na = merage(a)
        nb = merage(b)
        assert set(a) | set(b) == set(na + nb)
        return m_sort(na, nb)
    elif mid == 0:
        return [A[0], ]
    else:
        return [A[0], A[1]] if A[0] <= A[1] else [A[1], A[0]]


if __name__ == '__main__':
    A = []
    s = random.randint(5, 10)
    for i in range(0, s):
        A.append(random.randint(0, 100))
    print A
    print merage(A)
    assert merage(A) == sorted(A)
```

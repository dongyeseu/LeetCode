问题： 给定一个数列，例如【−2, 1, −3, 4, −1, 2, 1, −5, 4】， 求一个连续的数列使得数列内的元素和最大， 示例中最大子数列应该是【4, −1, 2, 1】, 求和值为6。

这个问题是可以衍生到一些变种问题， 如寻找数列中最大乘积序列，且要求序列中，相邻元素间隔不超过限定值等



算法描述：

- 遍历该数组， 在遍历过程中， 将遍历到的元素依次累加起来， 当累加结果小于或等于0时， 从下一个元素开始，重新开始累加。
- 累加过程中， 要用一个变量(max_so_far)记录所获得过的最大值
- 一次遍历之后， 变量 max_so_far 中存储的即为最大子片段的和值。

```python
def max_subarray(A):
    max_ending_here = max_so_far = 0
    for x in A:
        max_ending_here = max(0, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)

    return max_so_far
```




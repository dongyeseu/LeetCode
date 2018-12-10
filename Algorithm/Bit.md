## 位操作的常用技巧

### 判断奇偶

```c++
if (a & 1 == 0)
  为偶数
else
  为奇数  
```



### 交换两数

```c++
if (a != b)  
        {  
            a ^= b;  
            b ^= a;  
            a ^= b;  
        } 
```

**一个数和自己异或肯定是0**



### 变换符号

```c++
int SignReversal(int a)  
{  
    return ~a + 1;  
} 
```



### 求绝对值

```c++
int my_abs(int a)  
{  
    int i = a >> 31;  
    return i == 0 ? a : (~a + 1);  
}
```



```c++
//对于任何数，与0异或都会保持不变，与-1即0xFFFFFFFF异或就相当于取反
int my_abs(int a)  
{  
    int i = a >> 31;  
    return ((a ^ i) - i);  
} 
```



### 高低位交换

```c++
printf("交换前:    ");
unsigned short a = 3344520;
PrintfBinary(a);

printf("交换后:    ");
a = (a >> 8) | (a << 8);
PrintfBinary(a);

```





[位操作基础篇之全面总结](https://blog.csdn.net/morewindows/article/details/7354571)
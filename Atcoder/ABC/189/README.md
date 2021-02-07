﻿# Atcoder Beginner Contest 189

比赛链接：https://atcoder.jp/contests/abc189

比赛情况：A、B 300分

C - Mandarin Orange

找一个连续区间，使得该区间内的最小值与区间长度乘积最小，暴力即可

D - Logical Expression

Y(i)的结果只与X(i)和Y(i-1)有关，线性dp，dp[i][0]表示Y(i)为false的方案数，dp[i][1]表示Y(i)为true的方案数

E - Rotate and Flip

考虑四种变换的矩阵表达，如果使用2x2矩阵，那么将点关于x=p或y=p对称的矩阵表达将和点的坐标有关

于是使用3x3矩阵，将点的坐标写为（x, y, 1）,采用左乘，矩阵表达如下

  0  1  0    
 
 -1  0  0    

  0  0  1      


  0 -1  0   

  1  0  0    

  0  0  1    


 -1  0  2p   

  0  1  0    

  0  0  1    
  

  1  0  0

  0 -1 2p

  0  0  1


F - Sugoroku2

期望dp

状态：f[i]表示从i走到终点的期望步数

入口：f[n]=0

转移：如果当前点i是一个危险点，那么f[i]=f[0]，反之f[i]=(f[i+1]+f[i+2]+...+f[i+m])/m+1

出口：f[0]

发现这是一个产生了环形依赖的表达式，考虑做一个解方程的操作:设f[0]=x

从后往前维护一个长度为m的区间，这个区间维护两个值，一个是里面处在危险点的个数，一个是常数部分

因为从后往前递推最后推到0这个位置的时候，形式上来说f[0]=Ax+B，这里的A就是后面危险点产生的，常数部分是后面除来的

这个等式最后可以写成f[0]=B/(1−A)，那么当A=1的时候无解

区间维护的就是f[i+1]+f[i+2]+...+f[i+m]这部分的A，B系数

注意精度问题
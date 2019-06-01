## An IIR filter designed with MATLAB and implemented in C

The transfer function of a biquad filter can be written as: H(z)=(b₀+b₁z⁻¹+b₂z⁻²)/(a₀+a₁z⁻¹+a₂z⁻²).   
 
Use Filter Designer in MATLAB to design a 400 Hz bandpass IIR filter:  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190601212647210.png)  
  
Analysis->Filter Coeffients ：  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190601213027484.png)  
Numerator，from top to bottom: b₀，b₁ and b₂.  
Denominator, from top to bottom: a₀，a₁ and a₂，a₀ is always 1.  
  
Use arrays to store filter coeffients：
```c
//8-order IIR filter with 4 sections
const int sections = 4;

//nominator
const float b[4][3] = {
	{ 1, -1.984454421, 1 },
	{ 1, -1.999405318, 1 },
	{ 1, -1.993167556, 1 },
	{ 1, -1.998644244, 1 }
};

//denominator
const float a[4][3] = {
	{ 1, -1.984532740, 0.9884094716 },
	{ 1, -1.988571923, 0.9909378613 },
	{ 1, -1.991214225, 0.9962624248 },
	{ 1, -1.995917854, 0.9977478940 }
};

const float gain[4] = { 0.583805364, 0.583805364, 0.170388576, 0.170388576 };
```

Store filter states：
```c
float w[sections][2]; //filter states
```
  
Initialize filter：
```c
for (int i = 0; i < sections; i++) {
		w[i][0] = 0; //w[n-1]
		w[i][1] = 0; //w[n-2]
}
```
  
Calculate filter output:
```c
y[0] = pcmIn[i];
		for (j = 0; j < sections; j++) {
			tmp[j] = y[j] - a[j][1] * w[j][0] - a[j][2] * w[j][1]; //calculate w[n]
			y[j+1] = tmp[j] + b[j][1] * w[j][0] + b[j][2] * w[j][1]; //calculate the j-th section filter output y[n]
			w[j][1] = w[j][0]; //move w[n-1] -> w[n-2]
			w[j][0] = tmp[j]; //move w[n] -> w[n-1]
			y[j+1] = gain[j] * y[j+1]; //multiply with gain
		}
			
out = y[j];
```

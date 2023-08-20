&emsp;
# Extra

## Quartic CDF
$$p(x)=ax^4 + bx^3 + cx^2 + dx +e$$

>Quartic function

$$f(u) = \frac{15}{16}u(1-\frac{2}{3}u^2+\frac{1}{5}u^4) + \frac{1}{2}，u=x\cdot inv\_radius$$

>CDF of Quartic
$$F(u)=max(0, min(1, \frac{15}{16}u(1-\frac{2}{3}u^2+\frac{1}{5}u^4) + \frac{1}{2}))$$

>Implement
```c++
float quartic(const float x, const float inv_radius) {
	const float u = x * inv_radius;
	const float tmp = fmaxf(1 - u*u, 0.0f);
	return ((float)15 / 16) * tmp * tmp;
}

float quartic_cdf_deriv(const float x, const float inv_radius) {
	return quartic(x, inv_radius) * inv_radius;
}

float quartic_cdf(const float x, const float inv_radius) {
	const float u = x * inv_radius;
	const float u2 = u * u;
	const float u4 = u2 * u2;
	return fmaxf(0.0f, fminf(1.0f, ((float)15 / 16) * u * (1 - ((float)2 / 3) * u2 + ((float)1 / 5) * u4) + 0.5f));
}
```


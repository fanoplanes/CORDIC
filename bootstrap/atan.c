double power(double n, int m)
{
	double i = 1;
	for (int j = 0; j < m; j++) {
		i *= n;
	}
	return i;
}

double factorial(int n)
{
	if (n == 0) {
		return 1;
	} else {
		return n * factorial(n - 1);
	}
}

double product_term(double x, int k)
{
	return (2. * k / (2. * k + 1.)) * (x * x / (1 + x * x));
}

double series_term(double x, int n)
{
	double result = 1;
	for (int i = 1; i <= n; i++) {
		result *= product_term(x, i);
	}
	return result;
}

double my_atan(double x)
{
	double res = 0;
	double res_prev = 1;
	int i = 0;
	while (res_prev != res) {
		res_prev = res;
		res += series_term(x, i);
		i++;
	}
	return res * x / (1 + x * x);
}

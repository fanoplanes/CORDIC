double my_sqrt(double x)
{
	double k = 1;
	double k_old = 0;
	while (k != k_old) {
		k_old = k;
		k = (k + x / k) / 2;
	}
	return k;
}

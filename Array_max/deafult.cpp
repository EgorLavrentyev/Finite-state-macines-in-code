int main()
{
	enum { n = 8 };
	int a[n] = { 44, 55, 12, 42, 94, 18, 6, 67 };
	int max = a[0];
	int i;
	for (i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	
	return 0;
}













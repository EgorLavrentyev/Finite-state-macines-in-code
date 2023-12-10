int main()
{
	int y = 0;
	enum { n = 8 };
	int a[n] = { 44, 55, 12, 42, 94, 18, 6, 67 };
	int max;
	int i;
	do
		switch (y)
		{
		case 0:
			max = a[0]; i = 1; y = 1;
			break;
		case 1:
			if (i >= n) y = 0;
			else
				if (a[i] > max)
				{
					max = a[i]; i++;
				}
				else
					i++;
			break;
		}
	while (y != 0);

	return 0;
}


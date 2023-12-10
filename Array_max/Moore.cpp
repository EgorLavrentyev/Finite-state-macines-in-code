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
			y = 1;
			break;
		case 1:
			max = a[0]; i = 1;
			if (i >= n) y = 0;
			else
				if (a[i] > max) y = 2;
				else y = 3;
			break;
		case 2:
			max = a[i]; y = 3;
			break;
		case 3:
			i++;
			if (i >= n) y = 0;
			else
				if (a[i] > max) y = 2;
			break;
		}
	while (y != 0);

	return 0;
}


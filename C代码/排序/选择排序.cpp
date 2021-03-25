void select(int a[])   //选择排序     
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (a[i] > a[j])
				swap(&a[i], &a[j]);
		}
	}
}
// Prototypes for the functions in the
// reports.cpp file
void repListing();
void repWholesale();
void repRetail();
void repQty();
void repCost();
void repAge();
void reports();

template <class T>
void sort(T arr[])
{
	for (int i = 0; i < NUM_BOOKS; i++)
	{
		int min = i;
		for (int j = i + 1; j < NUM_BOOKS; i++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		T temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}


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
void sort(T arr[], int maxIndex, int* maxValue, int startScan, int* tempId, int idPtr[])
{
	for (startScan = 0; startScan < NUM_BOOKS - 1; startScan++)
	{
		maxIndex = startScan;
		maxValue = arr[startScan];
		tempId = idPtr[startScan];
		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (*(arr[index]) > *maxValue)
			{
				maxValue = arr[index];
				tempId = idPtr[index];
				maxIndex = index;
			}
		}
		arr[maxIndex] = arr[startScan];
		idPtr[maxIndex] = idPtr[startScan];
		arr[startScan] = maxValue;
		idPtr[startScan] = tempId;
	}

}


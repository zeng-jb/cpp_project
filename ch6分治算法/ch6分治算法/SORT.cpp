#include<iostream>
using namespace std;
/*
//QUICKSORT
//划分算法，先序遍历
int w=0;
int low = 0, high;
void SPLIT(int a[], int &w) {
	int i = low;
	int x = a[low];
	int item;
	for (int j = low; j < high; j++) {
		if (a[j] <= x) {
			i = i + 1;
			if (i != j) {
				item = a[i]; a[i] = a[j]; a[j] = item;
			}
		}
	}
	item = a[i]; a[i] = a[low]; a[low] = item;
	w = i;
	
}

void QUICKSORT(int a[], int low, int high) {
	if (low < high) {
		SPLIT(a, w);
		QUICKSORT(a, low, w - 1);
		QUICKSORT(a, w + 1, high);
	}
}
*/
//void main() {
//	int n;
//	cin >> n;
//	int a[10000];
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	//low = 0; high = n - 1;
//	//QUICKSORT(a, low, high);
//
//	for (int i = 0; i < n; i++) {
//		cout << a[i]<<" ";
//	}
//}



bool merge(int a[], int start1, int start2, int m_size)
{
	int m_temp = m_size - start1;
	int* temp_start = new int[m_temp];
	int* m_ptemp = temp_start;
	int m_tempstart1 = start2;
	int tempstart = start1;


	while (start1 < m_tempstart1 && start2 < m_size)
	{
		*temp_start++ = (a[start1] > a[start2]) ? a[start2++] : a[start1++];
	}

	while (start1 < m_tempstart1)
	{
		*temp_start++ = a[start1++];
	}
	while (start2 < (m_size))
	{
		*temp_start++ = a[start2++];
	}
	//将合并后的有序数组, 复制到

		int i = 0;
	while (i < m_temp)
	{
		a[tempstart] = m_ptemp[i];
		i++;
		tempstart++;
	}
	delete m_ptemp;

	return true;
}

bool bottomsort(int a[], int m_size)
{
	int length = 1;//size表示合并的数组的大小
	while (length < m_size)//length表示合并后数组的长度
	{
		int size = length;
		length = 2 * size;
		int i = 0;
		while (i + length <= m_size)
		{
			merge(a, i, i + size, i + length);
			i = i + length;
		}
		if (i + size < m_size)
			merge(a, i, i + size, m_size);
	}
	return true;
}
//
//int main()
//{
//	//int m_array[] = { 14,2,58,24,95,17,979879,45,477,255,15,2587,4877,987 };
//	
//	int n;
//	cin >> n;
//	int* m_array = new int[n];
//	for (int i = 0; i < n; i++){
//		cin>>m_array[i];
//	}
//	//int m_size = (sizeof(m_array)) / sizeof(m_array[0]);
//	int m_size = n;
//	bottomsort(m_array, m_size);
//	int index = 1;
//	for (int i = 0; i < m_size; i++)
//	{
//		if (index == 1)index = 2;
//		else cout << " ";
//		cout << m_array[i];
//	}
//	cout << endl;
//	return 0;
//}

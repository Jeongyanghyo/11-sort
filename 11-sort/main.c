#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y) = (t))

void print_list(int list[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%02d ", list[i]);
	}
	printf("\n");
}

void generateRandomData(int data[]) {
	srand(time(0));
	for (int i = 0; i < SIZE; i++) {
		data[i] = rand() % 1000;
	}
}

//�������� ���� �Լ�
void doSelectionSort(int data[]) {
	int i, j, least, temp;
	printf("Selection Sort: \n");
	for (i = 0; i < SIZE - 1; i++) {  // ���� �ε����� 0���� ����
		least = i;
		for (j = i + 1; j < SIZE; j++) {
			if (data[least] > data[j]) least = j;
		}
		SWAP(data[i], data[least], temp);  // SWAP ��ġ ����
		if ((i + 1) == 10 || (i + 1) == 30 || (i + 1) == 50 || (i + 1) == 70 || (i + 1) == 90 || (i + 1) == 99) {  //10 ���� 20������ ��� �� ������ ��° ���
			printf("Step %d: ", i + 1);
			print_list(data, SIZE);
			printf("\n");
		}
	}
}

//���� ���� ���� �Լ�
void doInsertionSort(int originalData[]) {
	int totalComparisons = 0;
	int insert_sortedData[SIZE];
	srand(time(NULL));

	for (int k = 0; k < 20; k++) {
		int tempData[SIZE];
		generateRandomData(tempData);
		int comparisons = 0;
		for (int i = 1; i < SIZE; i++) {
			int key = tempData[i];
			int j = i - 1;
			while (j >= 0 && tempData[j] > key) {
				tempData[j + 1] = tempData[j];
				j--;
				comparisons++;
			}
			tempData[j + 1] = key;
			comparisons++;
		}
		totalComparisons += comparisons; //20ȸ �õ� �̵�Ƚ�� ������
	}
	for (int i = 0; i < SIZE; i++) {
		insert_sortedData[i] = originalData[i];
	}
	for (int i = 1; i < SIZE; i++) {
		int key = insert_sortedData[i];
		int j = i - 1;
		while (j >= 0 && insert_sortedData[j] > key) {
			insert_sortedData[j + 1] = insert_sortedData[j];
			j--;
		}
		insert_sortedData[j + 1] = key;
	}

	printf("Insertion Sort Compare Average: %d\n", totalComparisons / 20); // 20ȸ �õ� �̵�Ƚ���� ����� ����
	printf("Insertion Sort Result:\n");
	print_list(insert_sortedData, SIZE);
	printf("\n");
}

//���� ���� ���� �Լ�
void doBubbleSort(int originalData[]) {
	int totalSwaps = 0;
	int bubble_sortedData[SIZE];
	srand(time(NULL));

	for (int k = 0; k < 20; k++) {
		int tempData[SIZE];
		generateRandomData(tempData);
		int swaps = 0;
		for (int i = SIZE - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (tempData[j] > tempData[j + 1]) {
					int temp;
					SWAP(tempData[j], tempData[j + 1], temp);
					swaps += 3;  // �� SWAP���� 3ȸ �̵����� ���
				}
			}
		}
		totalSwaps += swaps; //20 ȸ �õ��� �̵�Ƚ���� ������
	}
	for (int i = 0; i < SIZE; i++) {
		bubble_sortedData[i] = originalData[i];
	}
	for (int i = SIZE - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (bubble_sortedData[j] > bubble_sortedData[j + 1]) {
				int temp;
				SWAP(bubble_sortedData[j], bubble_sortedData[j + 1], temp);
			}
		}
	}

	printf("Bubble Sort Swap Average: %d\n", totalSwaps / 20); // 20ȸ �õ��� ��� �̵�Ƚ�� ����
	printf("Bubble Sort Result:\n");
	print_list(bubble_sortedData, SIZE);
}

int main() {
	int randomData[SIZE];
	generateRandomData(randomData);

	doSelectionSort(randomData);
	doInsertionSort(randomData);
	doBubbleSort(randomData);

	return 0;
}

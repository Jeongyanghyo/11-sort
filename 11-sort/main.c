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

//선택정렬 구현 함수
void doSelectionSort(int data[]) {
	int i, j, least, temp;
	printf("Selection Sort: \n");
	for (i = 0; i < SIZE - 1; i++) {  // 시작 인덱스를 0으로 변경
		least = i;
		for (j = i + 1; j < SIZE; j++) {
			if (data[least] > data[j]) least = j;
		}
		SWAP(data[i], data[least], temp);  // SWAP 위치 수정
		if ((i + 1) == 10 || (i + 1) == 30 || (i + 1) == 50 || (i + 1) == 70 || (i + 1) == 90 || (i + 1) == 99) {  //10 부터 20단위로 출력 후 마지막 번째 출력
			printf("Step %d: ", i + 1);
			print_list(data, SIZE);
			printf("\n");
		}
	}
}

//삽입 정렬 구현 함수
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
		totalComparisons += comparisons; //20회 시도 이동횟수 더해줌
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

	printf("Insertion Sort Compare Average: %d\n", totalComparisons / 20); // 20회 시도 이동횟수의 평균을 구함
	printf("Insertion Sort Result:\n");
	print_list(insert_sortedData, SIZE);
	printf("\n");
}

//버블 정렬 구현 함수
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
					swaps += 3;  // 각 SWAP마다 3회 이동으로 계산
				}
			}
		}
		totalSwaps += swaps; //20 회 시도한 이동횟수를 더해줌
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

	printf("Bubble Sort Swap Average: %d\n", totalSwaps / 20); // 20회 시도한 평균 이동횟수 구함
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

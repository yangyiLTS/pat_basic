#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

struct Student {
	int id;
	int de;
	int cai;
	int total;
	int feature;
};

void featureSort(Student *S, int n);
void totalSort(Student *S, int n);
void deSort(Student *S, int n);
void idSort(Student *S, int n);

int main()
{
	int N, L, H;
	cin >> N >> L >> H;
	Student *rawData = new Student[N];
	int count = 0;
	for (int i = 0; i < N; i++) {
		cin >> rawData[i].id >> rawData[i].de >> rawData[i].cai;
		if (rawData[i].de < L || rawData[i].cai < L) {
			i--;
			N--;
			continue;
		}
		rawData[i].total = rawData[i].de + rawData[i].cai;
		if (rawData[i].de >= H && rawData[i].cai >= H) rawData[i].feature = 4;
		else if (rawData[i].de >= H && rawData[i].cai < H) rawData[i].feature = 3;
		else if (rawData[i].de < H && rawData[i].cai < H && rawData[i].de >= rawData[i].cai) rawData[i].feature = 2;
		else rawData[i].feature = 1;
		count++;
	}
	featureSort(rawData, count);
	totalSort(rawData, count);

	for (int i = 0, f = 4; i < count; i++) {
		while (rawData[i].feature == f) {
			int totalcount = 1;
			while (rawData[i].total == rawData[i + 1].total) {
				totalcount++;
				i++;
				if (i >= count || rawData[i].feature != f) break;
			}
			if (totalcount > 1) {
				deSort(rawData + i - totalcount + 1, totalcount);
				int j = i - totalcount + 1;
				int decount = 1;
				while (rawData[j].de == rawData[j + 1].de) {
					decount++;
					j++;
					if (decount >= totalcount|| rawData[j].feature != f) break;
				}
				if (decount > 1) {
					idSort(rawData + j - decount + 1, decount);
				}
				decount = 1;
			}
			totalcount = 1;
			i++;
			if (i > count|| rawData[i].feature != f) break;
		}
		f--;
		if (i >= count) break;

	}

	for (int i = 0; i < count; i++) {
		cout << rawData[i].id << ' ' << rawData[i].de << ' ' << rawData[i].cai << ' ';
		cout << rawData[i].total << ' ' << rawData[i].feature << endl;
	}

	cout << endl;
	cout << count << endl;

	for (int i = 0; i < count; i++) {
		cout << rawData[i].id << ' ' << rawData[i].de << ' ' << rawData[i].cai << endl;
	}
	system("pause");
	return 0;
}

void featureSort(Student *S, int n) {
	int i, j;
	Student tmp;
	for (i = 0; i < n - 1; i++) {
		tmp = S[i];
		for (j = n - 1; j > i; j--) {
			if (S[j].feature > tmp.feature) {
				S[i] = S[j];
				S[j] = tmp;
				tmp = S[i];
			}
		}
	}
}


void idSort(Student *S, int n) {
	int i, j;
	Student tmp;
	for (i = 0; i < n - 1; i++) {
		tmp = S[i];
		for (j = n - 1; j > i; j--) {
			if (S[j].id < tmp.id) {
				S[i] = S[j];
				S[j] = tmp;
				tmp = S[i];
			}
		}
	}
}

void deSort(Student *S, int n) {
	int i, j;
	Student tmp;
	for (i = 0; i < n - 1; i++) {
		tmp = S[i];
		for (j = n - 1; j > i; j--) {
			if (S[j].de > tmp.de) {
				S[i] = S[j];
				S[j] = tmp;
				tmp = S[i];
			}
		}
	}
}

void totalSort(Student *S, int n) {
	int i, j, f = 4;
	Student tmp;

	for (i = 0; i < n - 1; i++) {
		tmp = S[i];
		if (S[i].feature != f) {
			i--;
			f--;
			break;
		}
		for (j = n - 1; j > i; j--) {
			if (S[j].feature != f) break;
			if (S[j].total > tmp.total) {
				S[i] = S[j];
				S[j] = tmp;
				tmp = S[i];
			}
		}
	}

}

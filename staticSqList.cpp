#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#define MAX_SIZE 10
#define ElemType int
template <typename T>
struct staticSqList {
	/* data */
	ElemType data[MAX_SIZE];
	int length;
};

template <typename T>
void initList(staticSqList<T>* L) {
	L->length = 0;
}

template <typename T>
bool insertList(staticSqList<T>& L, int pos, T value) {
	if (L.length != 0) {
		if (pos < 1 | pos >= L.length + 1 | L.length == MAX_SIZE) {
			cout << "insert error" << endl;
			return false;
		}
		for (int i = L.length; i >= pos; i--) {
			L.data[i] = L.data[i - 1];
		}
		L.data[pos - 1] = value;
		L.length++;
		cout << "insert succuessfully" << endl;
		return true;
	} else {
		if (pos == 1) {
			L.data[0] = value;
			L.length++;
			cout << "insert succuessfully" << endl;
			return true;
		}
		cout << "insert error" << endl;
		return false;
	}
}
template <typename T>
void showList(staticSqList<T>& L) {
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << " ";
	}
	cout << endl;
}
int main() {
	staticSqList<int> L;
	initList(&L);
	printf("%d\n", L.length);
	insertList(L, 1, 2);
	showList(L);
	return 0;
}
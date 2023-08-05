#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct dynamicList {
	int max_size;
	int length;
	T* data;
};

template <typename T>
void initList(dynamicList<T>& L, int max_size) {
	L.length = 0;
	L.max_size = max_size;
	L.data = new int[max_size];
}

template <typename T>
void distoryList(dynamicList<T>& L) {
	free(L->data);
	L->data = NULL;
	L->length = 0;
	L->max_size = 0;
}

template <typename T>
bool insertList(dynamicList<T>& L, int pos, T value) {
	if (L.length != 0) {
		if (pos<1 | pos> L.length + 1 | L.length == L.max_size) {
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
bool deleteNode(dynamicList<T>& L, int pos)

{
	if (L.length == 0 | pos<1 | pos> L.length) {
		cout << "delete error " << endl;
		return false;
	}

	for (int i = pos - 1; i < L.length; i++) {
		/* code */
		L.data[i] = L.data[i + 1];
	}
	L.length--;
	cout << "delete successfully" << endl;
	return true;
}

template <typename T>
T getElem(dynamicList<T>& l, int i) {
	if (i < 1 || i > l.length) {
		cout << "get element error" << endl;
		return 0;
	}
	return l.data[i - 1];
}

template <typename T>
int locateElem(dynamicList<T>& L, T value) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == value) {
			cout << "locate successfully" << endl;
			return i + 1; // 返回位序
		}
	}
	cout << "locate error,no such value" << endl;
	return 0;
}

template <typename T>
void showList(dynamicList<T>& L) {
	for (int i = 0; i < L.length; i++) {
		cout << L.data[i] << " ";
	}
	cout << endl;
}

int main() {
	dynamicList<int> L;
	initList(L, 10);
	for (int i = 1; i <= 10; i++) {
		insertList(L, i, i * i);
	}
	showList(L);

	return 0;
}
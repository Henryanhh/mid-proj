#include <iostream>
using namespace std;

int n;

template <typename T>
class Vector {
public:
	Vector(int initCapa = 16) {
		size = 0;
		capa = initCapa;
		arr = new T[capa];
	}

	void ins(int pos, T elem) { //chen phan tu vao giua vector
		if (size == capa) expand(2 * size);
		for (int i = size; i > pos; i--) {
			arr[i] = arr[i - 1];
		}
		arr[pos] = elem;
		size++;
	}

	void pushBack(T elem) { //chen phan tu vao cuoi vector
		if (size == capa) expand(2 * size);
		arr[size] = elem;
		size++;
	}

	void delElem(int pos) { //xoa phan tu
		for (int i = pos; i < size; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
	}

	void inp() {
		cout << "Nhap so luong gia tri cua ham = "; cin >> n;

		cout << "Nhap gia tri cua ham = ";
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			size++;
		}
	}
	
	void outp() { //xuat ra man hinh mang xuoi
		for (int i = 0; i < size; i++) cout << arr[i] << " ";
	}

	void revOut() { //xuat ra man hinh mang nguoc
		for (int i = size - 1; i >= 0; i--) cout << arr[i] << " ";
	}

private:
	int size;
	int capa;
	T* arr;

	void expand(int newCapa) {
		T* old = arr;
		arr = new T[newCapa];
		for (int i = 0; i < size; i++) {
			arr[i] = old[i];
		}
		capa = newCapa;
		delete[] old;
	}
};

int main() {
	Vector<int> vec;

	vec.inp();

	int val, pos;
	cout << "\nNhap gia tri can them = "; cin >> val;
	cout << "Nhap vi tri can them = "; cin >> pos;
	
	if (pos > n) vec.pushBack(val);
	else vec.ins(pos, val);
	cout << "Mang sau khi them phan tu: "; vec.outp(); 

	cout << "\n\nNhap vi tri can xoa = "; cin >> pos;

	vec.delElem(pos);
	cout << "\nMang sau khi xoa: "; vec.outp();

	cout << "\n\nHien thi vector theo chieu thuan: "; vec.outp();
	cout << "\nHien thi vector theo chieu nguoc: "; vec.revOut();
}
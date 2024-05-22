#include <iostream>

using namespace std;

template <typename T>
class Vector {
public:
    Vector(int initCapa = 16) {
        size = 0;
        capa = initCapa;
        arr = new T[capa];
    }

    void ins() {
        int x, k;
        expand(2*size);
        cout << "\nNhap phan tu muon chen: "; cin >> x;
        cout << "Nhap vi tri muon chen: "; cin >> k;
        if(k >= size) arr[size] = x;
        else {
            for(int i = size - 1; i > k; i--) {
                arr[i] = arr[i - 1];
            }
            arr[k] = x;
        }
        size++;
        for(int i = 0; i < size; i ++) {
            cout << arr[i] << " ";
        }
    }

    void inp(int n) {
        expand(2*size);
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            size++;
        }
    }

private:
    int size;
    int capa;
    T * arr;
    void expand(int newCapa) {
        if(size < capa) return;
        T * old = arr;
        arr = new T[newCapa];
        for(int i = 0; i < size; i++) {
            arr[i] = old[i];
        }
        capa = newCapa;
        delete[] old;
    }
};

int main() {
    Vector<int> v;
    int n;
    cout << "Nhap so phan tu can nhap: "; cin >> n;
    v.inp(n);
    v.ins();
}
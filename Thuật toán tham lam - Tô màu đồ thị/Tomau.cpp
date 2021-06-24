#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;

#define MAX 20 //số đỉnh tối đa

//Một số hàm xử lí
//1.Đọc ma trận kề của đồ thị từ file
void readFile(int a[][MAX], int &n);
//2. Hàm in ra ma trận
void printMatrix(int a[][MAX], int d, int c);
//3. Hàm dùng 1 màu tô cho tất cả các đỉnh có thể tô
int to1mau(int a[][MAX], int n, int v[], int color);
//4. Hàm tô màu tất cả các đỉnh của đồ thị
//hàm trả về số lượng màu được sủ dụng
int tomau(int a[][MAX], int n, int v[] );
//Hàm bổ trợ: Kiểm tra đỉnh i có tô được màu c hay không
int toduoc(int a[][MAX], int n, int v[], int i, int c);

int main(){
    int a[MAX][MAX];
    int n;
    readFile(a, n);
    printMatrix(a, n, n);
    int kq;
    int v[MAX];
    kq = tomau(a, n, v);
    cout << "So mau su dung: " << kq << endl;
    cout << "Ket qua to mau:\n";
    for(int i = 0; i < n; i++){
        cout.width(4);
        cout << v[i];
    }
    cout << endl;
    return 0;
}
void readFile(int a[][MAX], int &n){
    //B1. Mở file
    ifstream file ("dothi.txt");
    /*fstream file;
    string filePath;
    cout << "Hay nhap ten file:  ";   
    cin >> filePath;
    file.open(filePath, ios::in);*/
    if(! file.is_open()){
        cout<<"Khong the mo file.\n";
        return;
    }else {
        //B2. Đọc dữ liệu từ file
        file>>n;
        //cout << n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                file>>a[i][j];
                cout << " ";
            }
            cout << "\n";
        }
    //B3. Đóng tập tin
    file.close();
    }
}
void printMatrix(int a[][MAX], int d, int c){
    for(int i = 0; i < d; i++){
        for(int j = 0; j < c; j++){
            cout.width(4);
            cout << a[i][j];
        }
        cout << endl;
    }
}
int to1mau(int a[][MAX], int n, int v[], int color){
    int count = 0;
    for(int i = 0; i < n; i++)
        if(!v[i] && toduoc(a, n, v, i, color)){
            v[i] = color;
            count++;
        }
    return count;//trả về số đỉnh đã đc tô màu color
}
int tomau(int a[][MAX], int n, int v[]){
    for(int i = 0; i < n; i++) v[i] = 0;
    int somau = 0;
    int count = 0;
    while(count < n){
        somau++;
        count += to1mau(a, n, v, somau);
    }
    return somau;
}
int toduoc(int a[][MAX], int n, int v[], int i, int c){
    for(int j = 0; j < n; j++)
        if(a[i][j] && v[j] == c ) return 0;
    return 1;
}

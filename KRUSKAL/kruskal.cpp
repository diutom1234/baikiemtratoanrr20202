#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Cấu triucs dữ liệu Disjoint Sets
int fathers[100];
//mảng fathers lưu trữ cha của x
//hàm tìm xem x thuộc tập nào
int find(int x){
	if(fathers[x] == x){
		return x;
	}
	return find(fathers[x]);
}
//hàm hợp hai tập chưa x và y
void unionn(int x, int y){
	int fx = find(x);
	int fy = find(y);
	fathers[fx] = fy;
}

int main(){
	//Khởi tạo cha
	for(int i=0;i<100;i++){
		fathers[i]=i;
	}
	//	Khai báo biến và nhập dữ liệu vào
	int n,m;
	int a,b,w;
	vector < pair < int , pair < int , int > > > edges;
	//	nhập đầu vào
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b>>w;
		edges.push_back(make_pair( w,make_pair(a,b) ) );
	}
	cout<<endl;
	//	Thuật toán Kruskal
	//Khai báo biến cho MST
	int mst_weight = 0, mst_edges = 0;
	int	mst_ni = 0;
	//	BƯỚC 1: sắp xếp danh sách các cạnh 
	sort(edges.begin(),edges.end());
	//	BƯỚC 2-3:
	while( ( mst_edges < n-1) || (mst_ni < m) ){
		a = edges[mst_ni].second.first;
		b = edges[mst_ni].second.second;
		w = edges[mst_ni].first;
		// kiểm tra xem cạnh có ổn không để được đưa vào MST 
		//	nếu a và b ở các cây khác nhau (nếu chúng như nhau, chúng ta sẽ tạo ra một chu trình) 
		if( find(a) != find(b) ) {
			//	hợp nhất hai cây mà cạnh kết nối 
			unionn(a,b);
			//	thêm trọng lượng của cạnh 
			mst_weight += w;
			// in ra cạnh và đếm nó 
			cout<<a<<" "<<b<<" "<<w<<endl;
			mst_edges++;
		}
		//	tăng chỉ số của cạnh mà chúng ta sẽ theo dõi 
		mst_ni++;
	}
	//	Trình bày trọng lượng
	cout<<"\nWeight of the MST is "<<mst_weight<<endl;
}


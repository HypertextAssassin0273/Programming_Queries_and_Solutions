#include<iostream>
using namespace std;

int main(){
	int n,m;
	cout<<"Input Data:\n";
	cin>>n>>m;
	int arr[n][m];
	
	for(int i=0,j;i<n;++i)
		for(j=0;j<m;++j)
			cin>>arr[i][j];
	
	int col_index=0;
	{//i.e. destructs highest_col_sum & col_sum
		int highest_col_sum=0,col_sum;
		for(int i,j=0;j<m;++j){
			for(i=0,col_sum=0;i<n;++i)
				col_sum+=arr[i][j];
			if(col_sum>highest_col_sum){
				highest_col_sum=col_sum;
				col_index=j;
			}
		}
	}
	cout<<"Output Data:\n";
	for(int i=0;i<n;++i)
		cout<<arr[i][col_index]<<' ';	
	return 0;
}

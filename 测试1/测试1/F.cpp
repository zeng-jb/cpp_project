//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int main(){
//	int i,j,n,m;
//	cin>>n>>m;
//	int **p;
//	p = new int *[n+1];
//	for(i = 0; i <= n; i++)
//    	p[i]= new int[m+1];
//    for(i=0;i<n+1;i++)
//    	p[i][0]=0;
//    for(i=0;i<n+1;i++)
//    	p[0][i]=0;
//	for(i=1;i<n+1;i++)
//		for(j=1;j<m+1;j++)
//			cin>>p[i][j];
//		
//	for(i=1;i<n+1;i++){
//		for(j=1;j<m+1;j++){
//			p[i][j]=p[i][j]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
//			cout<<p[i][j]<<" ";
//		}
//		cout<<endl;
//	}
//	
//	
//	
//	return 0;
//} 
////3 3 1 2 3 4 5 6 7 8 9

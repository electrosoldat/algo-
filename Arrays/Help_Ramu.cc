#include<iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for(int i=0;i<T;i++)
	{
		int c1,c2,c3,c4;
		cin >> c1 >> c2 >> c3 >> c4;
		int Nr,Mc;
		cin >> Nr >> Mc;
		int* n = new int[Nr];
		int* m = new int[Mc];
		for(int j=0;j<Nr;j++)
		{
			cin >> n[j];
		//	cout << n[j] << " ";
		}
	//	cout << "\n$$$$$$$$$$$$" << endl;
		
		for(int j=0;j<Mc;j++)
		{
			cin >> m[j];
		//	cout << m[j] << " ";
		}
	//	cout << "\n$$$$$$$$$$$$" << endl;
		
		int p11 = 0;
		for(int k=0;k<Nr;k++)
		{
			int pni = min(n[k]*c1,c2);
		//	cout << "pni = " << pni << " ; p11 = ";
			p11 += pni;
		//	cout << p11 << " **** " ;
		}
	//	cout << "\n$$$$$$$$$$$$" << endl;


		//int p21 = Nr * c2;
		//int p31 = min(p11,p21);
		int p21 = min(p11,c3);

		int p12 = 0;
		for(int k=0;k<Mc;k++)
		{
			int pmi = min(m[k]*c1,c2);
		//	cout << "pmi = " << pmi << " ; p12 = ";
			p12 += pmi;
		//	cout << p12 << " **** " ;
		}
	//	cout << "\n$$$$$$$$$$$$" << endl;

		int p22 = min(p12,c3);

		int p3 = p21 + p22;

		int pans = min(p3,c4);

		cout << pans << "\n";	
		
	}

	return 0;
}

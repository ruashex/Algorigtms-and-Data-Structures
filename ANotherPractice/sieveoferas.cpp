//In the name of God
//Sieve of erasthonesis

#include<bits/stdc++.h>
using namespace std;
typedef long long u_64;
const u_64 N = 1e7;
vector<bool> primes(N+1);

void sieveOfEr(){
	
	fill(primes.begin(), primes.end(), 1);
	primes[1] = 1;
	primes[2] = 1;
	for(u_64 i=2;i<=N;i++ )
	{
		if(primes[i] && i*i<=N)
		{
			for(u_64 j=i*i;j<=N;j += i)
				primes[j] = 0;

		}
	}
}

int main(int argc, char** argv){
	sieveOfEr();
	ofstream of(argv[1]);

	for(int i=1;i<=N;i++)
	{
		if(primes[i])
			of<<i<<", ";
	}
}
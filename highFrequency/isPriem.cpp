#include <iostream>
#include <vector>

bool isPrime(int n)
{
		for(int i = 2; i * i <= n;i++)
		{
				if(n % i == 0)
						return false;
		}
		return true;
}


int countPrimes(int n)
{
		vector<bool> isPrim(n,true);
		for(int i = 2;i * i < n; i++)
		{
				if(isPrim[i])
						for(int j = i * i; j < n; j+=i)
								isPrim[j] = false;
		}

		int count = 0;
		for(int i = 2; i < n; i++)
			if(isPrim[i])
					count++;
		return count;
}



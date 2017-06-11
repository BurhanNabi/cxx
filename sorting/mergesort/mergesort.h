#include <iostream>
#include <vector>
#include <limits.h>

#define DEBUG 0
#define DEBUG_ONLY if(DEBUG)

namespace MergeSort
{
	template<class T>
	void mergeSort(std::vector<T> &A, int s, int e);
	
	template<class T>
	void merge(std::vector<T> &A, int s, int m, int e);
};

/*
	merge function arguments are indices which are end exclusive
	which means that:
	First subarray is [s-m) while the second is [m-e)
*/
template<class T>
void MergeSort::merge(std::vector<T> &A, int s, int m, int e)
{
	
	DEBUG_ONLY
	{
		std::cout << "s:" << s << "\t"<< "m:" << m << "\t"<< "e:" << e << std::endl;
	}

	std::vector<T> F(m-s), S(e-m);
	int nF=m-s, nS=e-m;
	
	for(int i=0; i<nF; i++)
		F[i] = A[s+i];
	for(int i=0; i<nS; i++)
		S[i] = A[m+i];

	DEBUG_ONLY
	{
		std::cout << "First Half: ";
		for(int i=0; i<nF; i++)
			std::cout << F[i] << " ";
		std::cout << std::endl;

		std::cout << "Second Half: ";
		for(int i=0; i<nS; i++)
			std::cout << S[i] << " ";
		std::cout << std::endl;
	}

	int i=0, j=0, k=s;
	while(i<nF && j<nS)
	{
		if( F[i] < S[j] ) A[k++]=F[i++];
		else A[k++]=S[j++];
	}
	while(i<nF)A[k++]=F[i++];
	while(j<nS)A[k++]=S[j++];
	
	DEBUG_ONLY
	{
		std::cout << "Final: ";
		for(int ii=s; ii<e; ii++)
			std::cout << A[ii] << " ";
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

template<class T>
void MergeSort::mergeSort(std::vector<T> &A, int s, int e)
{
	if(e-s > 1)
	{
		int m =(s+e)/2;
		mergeSort(A,s,m);
		mergeSort(A,m,e);
		merge(A,s,m,e);
	}
}


template<class T>
void MergeSort::parallelMergeSort(std::vector<T> &A, int s, int e)
{
	if(e-s > 1)
	{
		int m =(s+e)/2;
		mergeSort(A,s,m);
		mergeSort(A,m,e);
		merge(A,s,m,e);
	}	
}
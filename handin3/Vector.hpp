#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF
#include <cassert>
#include <vector>

template <class T>
class Vector
{
private:
	std::vector<T> mData; // data stored in vector
	int mSize; // size of vector
public:

	Vector (const Vector <T> & otherVector)
	{
		mSize = otherVector.size();
		mData = otherVector.mData;
	}

	Vector (int size)
	{
		assert(size > 0);
		mSize = size;
		mData.resize(size);
	}

	int size() const
	{
		return mSize;
	}

	T& operator[](int i) 
	// zero-based indexing
	{
		assert(i >= 0);
		assert(i < mSize);
		return mData[i];
	}
	
	T const& operator[] (int i)const // zero-based indexing
	{
		assert(i >= 0);
		assert(i < mSize);
		return mData[i];
	}
	
	// assignment
	Vector& operator=(const Vector& otherVector)
	{
		assert(mSize == otherVector.mSize);
		mData = otherVector.mData;
		return *this;
	}

	Vector operator-() const // unary -
	{
		Vector<T> v(mSize);
		for (int n: mData)
		{
			v[i] = -mData[i];
		}
		return v;
	}

	Vector operator+(const Vector& v1) const // binary +
	{
		assert(mSize == v1.mSize);
		Vector v(mSize);
		for (int i=0; i<mSize; i++)
		{
			v[i] = mData[i] + v1.mData[i];
		}
		return v;
	}

	Vector operator-(const Vector& v1) const // binary -
	{
		assert(mSize == v1.mSize);
		Vector v(mSize);
		for (int i=0; i<mSize; i++)
		{
			v[i] = mData[i] - v1.mData[i];
		}
		return v;
	}

	// scalar multiplication
	Vector operator*(double a) const
	{
		Vector v(mSize);
		for (int i=0; i<mSize; i++)
		{
			v[i] = a*mData[i];
		}
		return v;
	}
	
	// p-norm method
	double CalculateNorm(int p=2) const
	{
		double norm_val, sum = 0.0;
		for (int i=0; i<mSize; i++)
		{
			sum += pow(fabs(mData[i]), p);
		}
		norm_val = pow(sum, 1.0/((double)(p)));
		return norm_val;
	}

	void Print() const
	{
		for (int i=0; i<mSize; i++)
		{
			std::cout << mData[i] << ",";
		}
		std::cout << "\n";
	}
};

#endif
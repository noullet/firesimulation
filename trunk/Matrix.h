#include <iostream>
#include <vector>
using namespace std;

template<class T> class Matrix
{
	protected:
		vector <vector<T>*> row;

	public:
		Matrix(int r = 1, int c = 1) : row(r)
		{
			for(int i = 0 ; i < r ; i++)
			{
				row[i] = new vector<T>(c);
			}
		}

		~Matrix()
		{
			for(int i = 0 ; i < row.size() ; i++)
			{
				delete row[i];
			}
		}

		vector<T>&operator[](int i) const
		{
			return *row[i];
		}

		int rows()
		{
			return row.size();
		}

		int columns()
		{
			return row[0]->size();
		}
};

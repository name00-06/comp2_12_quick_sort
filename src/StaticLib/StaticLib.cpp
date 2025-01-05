#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

void swap(item* a,item* b)
{
	item t = *a;
	*a = *b;
	*b = t;
}

item* partition(item* L, item* R)
{
	item* pivot = L + (R - L) / 2;
	swap(pivot, R);
	item* pivot = R;
	item* i = (L - 1);

	for (item* j = L; j <= R - 1; j++)
	{
		if (j->key <= pivot->key)
		{
			i++;
			swap(i, j);
		}
	}

	swap(i + 1, R);
	return (i + 1);
}

void quick_sort(item* L, item* R)
{
	if (L < R)
	{
		item* pivot = partition(L,R);
		quick_sort(L, pivot - 1);
		quick_sort(pivot + 1, R);
	}
}

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (begin == NULL || end == NULL)
	{
		return false;
	}
	if (end < begin)
	{
		return false;
	}

	quick_sort(begin, const_cast<item*>(end - 1));

	return true;
}

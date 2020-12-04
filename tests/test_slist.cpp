#include <../gtest/gtest.h>
#include "SList.h"

TEST(slist, can_create_list)
{
	ASSERT_NO_THROW(SList<int> a);
}

TEST(slist, can_copy)
{
	SList<int> a;
	ASSERT_NO_THROW(SList<int> b(a));
}

TEST(slist, can_push_back)
{
	SList<int> a;
	ASSERT_NO_THROW(a.push_back(1));
}

TEST(slist, can_pop_back)
{
	SList<int> a;
	a.push_back(1);
	ASSERT_NO_THROW(a.pop_back());
}

TEST(slist, cant_pop_in_empty_list)
{
	SList<int> a;
	ASSERT_ANY_THROW(a.pop_back());
}

TEST(slist, can_push_front)
{
	SList<int> a;
	a.push_back(2);
	ASSERT_NO_THROW(a.push_front(1));
}

TEST(slist, can_pop_front)
{
	SList<int> a;
	a.push_back(1);
	ASSERT_NO_THROW(a.pop_front());
}

TEST(slist, can_insert)
{
	SList<int> a;
	a.push_back(1);
	a.push_back(3);
	ASSERT_NO_THROW(a.insert(2, 1));
}

TEST(slist, can_remove)
{
	SList<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	ASSERT_NO_THROW(a.remove(1));
}

TEST(slist, can_insert_at_end)
{
	SList<int> a;
	a.push_back(1);
	a.push_back(2);
	ASSERT_NO_THROW(a.insert(3, 2));
}

TEST(slist, cant_insert_beyond_border)
{
	SList<int> a;
	ASSERT_ANY_THROW(a.insert(1, 1));
}

TEST(slist, cant_remove_beyond_border)
{
	SList<int> a;
	ASSERT_ANY_THROW(a.remove(1));
}
#include <../gtest/gtest.h>
#include "SList.h"

TEST(slist, can_create_list)
{
	ASSERT_NO_THROW(SList<int> a);
}

TEST(slist, can_copy)
{
	SList<int> a;
	a.push_back(123);

	SList<int> b(a);

	EXPECT_EQ(123, b[0]);
}

TEST(slist, can_push_back)
{
	SList<int> lst;

	lst.push_back(5);
	lst.push_back(100);

	EXPECT_EQ(100, lst[1]);
}

TEST(slist, can_pop_back)
{
	SList<int> lst;

	lst.push_back(5);
	lst.push_back(100);

	lst.pop_back();

	lst.push_back(17);

	EXPECT_EQ(17, lst[1]);
}

TEST(slist, cant_pop_in_empty_list)
{
	SList<int> a;
	ASSERT_ANY_THROW(a.pop_back());
}

TEST(slist, can_push_front)
{
	SList<int> lst;

	lst.push_back(5);
	lst.push_back(100);

	lst.push_front(17);

	EXPECT_EQ(17, lst[0]);
}

TEST(slist, can_pop_front)
{
	SList<int> lst;

	lst.push_back(5);
	lst.push_back(100);

	lst.pop_front();

	EXPECT_EQ(100, lst[0]);
}

TEST(slist, can_insert)
{
	SList<int> lst;

	lst.push_back(5);
	lst.push_back(100);

	lst.insert(99, 1);
	lst.insert(2, 1);
	lst.insert(33, 2);

	EXPECT_EQ(99, lst[3]);
}

TEST(slist, can_remove)
{
	SList<int> lst;

	lst.push_back(5);
	lst.push_back(100);
	lst.push_back(21);

	lst.remove(1);

	EXPECT_EQ(21, lst[1]);
}

TEST(slist, can_insert_at_end)
{
	SList<int> a;
	a.push_back(1);
	a.push_back(2);

	a.insert(3, a.GetSize());

	EXPECT_EQ(3, a[a.GetSize() - 1]);
}

TEST(slist, can_remove_at_end)
{
	SList<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	a.remove(a.GetSize() - 1);

	EXPECT_EQ(2, a[a.GetSize() - 1]);
}

TEST(slist, cant_insert_out_of_bounds)
{
	SList<int> a;
	ASSERT_ANY_THROW(a.insert(1, 1));
}

TEST(slist, cant_remove_out_of_bounds)
{
	SList<int> a;
	ASSERT_ANY_THROW(a.remove(1));
}

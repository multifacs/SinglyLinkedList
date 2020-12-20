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

	SList<int>::Iterator k = b.begin();
	EXPECT_EQ(123, *k);
}

TEST(slist, can_push_back)
{
	SList<int> lst;

	lst.push_back(5);
	lst.push_back(100);

	SList<int>::Iterator k = lst.begin();
	k++;
	EXPECT_EQ(100, *k);
}

TEST(slist, can_pop_back)
{
	SList<int> lst;

	lst.push_back(5);
	lst.push_back(100);

	lst.pop_back();

	lst.push_back(17);

	SList<int>::Iterator k = lst.begin();
	k++;
	EXPECT_EQ(17, *k);
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

	SList<int>::Iterator k = lst.begin();
	EXPECT_EQ(17, *k);
}

TEST(slist, can_pop_front)
{
	SList<int> lst;

	lst.push_back(5);
	lst.push_back(100);

	lst.pop_front();

	SList<int>::Iterator k = lst.begin();
	EXPECT_EQ(100, *k);
}

TEST(slist, can_insert)
{
	SList<int> lst;

	lst.push_back(5);
	lst.push_back(100);

	lst.insert(99, 1);
	lst.insert(2, 1);
	lst.insert(33, 2);

	SList<int>::Iterator k = lst.begin();
	k++; k++; k++;
	EXPECT_EQ(99, *k);
}

TEST(slist, can_remove)
{
	SList<int> lst;

	lst.push_back(5);
	lst.push_back(100);
	lst.push_back(21);

	lst.remove(1);

	SList<int>::Iterator k = lst.begin();
	k++;
	EXPECT_EQ(21, *k);
}

TEST(slist, can_insert_at_end)
{
	SList<int> a;
	a.push_back(1);
	a.push_back(2);

	a.insert(3, a.GetSize());

	SList<int>::Iterator k = a.begin();
	k++; k++;
	EXPECT_EQ(3, *k);
}

TEST(slist, can_remove_at_end)
{
	SList<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	a.remove(a.GetSize() - 1);

	SList<int>::Iterator k = a.begin();
	k++;
	EXPECT_EQ(2, *k);
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

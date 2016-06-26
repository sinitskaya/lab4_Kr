#include "tabl.hpp"
#include <gtest.h>
typedef float type;

TEST(TabRecord, can_create_tabrecord)
{
	Node<type> *n = new Node<type>(1);
	ASSERT_NO_THROW(TabRecord<type> t(0,n));
}

TEST(TabRecord, can_GetKey)
{
	Node<type> *n = new Node<type>(1);
	TabRecord<type> *t = new TabRecord<type>(0,n);
	ASSERT_NO_THROW(t->GetKey());
}

TEST(TabRecord, can_GetKey_correct)
{
	Node<type> *n = new Node<type>(1);
	TabRecord<type> *t = new TabRecord<type>(0,n);
	EXPECT_EQ(0,t->GetKey());
}

TEST(TabRecord, can_GetData)
{
	Node<type> *n = new Node<type>(1);
	TabRecord<type> *t = new TabRecord<type>(0,n);
	ASSERT_NO_THROW(t->GetData());
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(ScanTable, can_create_scan_table)
{
	ASSERT_NO_THROW(ScanTable<type> *t = new ScanTable<type>());
}

TEST(ScanTable, cant_create_scan_table_with_negative_size)
{
	ASSERT_ANY_THROW(ScanTable<type> t(-3));
}

TEST(ScanTable, can_GetSize)
{
	Table<type> *t = new ScanTable<type>(12);
	ASSERT_NO_THROW(t->GetSize());
}

TEST(ScanTable, can_GetSize_correct)
{
	Table<type> *t = new ScanTable<type>(12);
	EXPECT_EQ(12,t->GetSize());
}

TEST(ScanTable, can_IsEmpty)
{
	Table<type> *t = new ScanTable<type>(12);
	ASSERT_NO_THROW(t->IsEmpty());
}

TEST(ScanTable, IsEmpty_return_false_when_table_is_not_empty)
{
	Table<type> *t = new ScanTable<type>(12);
	Node<type>* n = new Node<type>(5);
	t->Insert(0,n);
	EXPECT_EQ(0,t->IsEmpty());
}

TEST(ScanTable, IsEmpty_return_true_when_table_is_empty)
{
	Table<type> *t = new ScanTable<type>(1);
	EXPECT_EQ(1,t->IsEmpty());
}

TEST(ScanTable, can_IsFull)
{
	Table<type> *t = new ScanTable<type>(12);
	ASSERT_NO_THROW(t->IsFull());
}

TEST(ScanTable, IsFull_return_false_when_table_is_not_full)
{
	Table<type> *t = new ScanTable<type>(12);
	Node<type>* n = new Node<type>(8);
	t->Insert(0,n);
	EXPECT_EQ(0,t->IsFull());
}

TEST(ScanTable, IsFull_return_true_when_table_is_full)
{
	Table<type> *t = new ScanTable<type>(1);
	Node<type>* n = new Node<type>(8);
	t->Insert(0,n);
	EXPECT_EQ(1,t->IsFull());
}

TEST(ScanTable, can_GetCount)
{
	Table<type> *t = new ScanTable<type>(12);
	ASSERT_NO_THROW(t->GetCount());
}

TEST(ScanTable, can_GetCount_correct)
{
	Table<type> *t = new ScanTable<type>(12);
	Node<type>* n = new Node<type>(8);
	Node<type>* n1 = new Node<type>(81);
	t->Insert(0,n);
	t->Insert(1,n1);
	EXPECT_EQ(2,t->GetCount());
}

TEST(ScanTable, can_Reset)
{
	Table<type> *t = new ScanTable<type>(12);
	ASSERT_NO_THROW(t->Reset());
}

TEST(ScanTable, can_GetNext)
{
	Table<type> *t = new ScanTable<type>(12);
	ASSERT_NO_THROW(t->GetNext());
}

TEST(ScanTable, GetNext_return_null_when_is_end_of_table)
{
	Table<type> *t = new ScanTable<type>(12);
	EXPECT_EQ(0,t->GetNext());
}

TEST(ScanTable, can_IsTablEnded)
{
	Table<type> *t = new ScanTable<type>(12);
	ASSERT_NO_THROW(t->IsTablEnded());
}

TEST(ScanTable, can_Search_key)
{
	Table<type> *t = new ScanTable<type>(12);
	Node<type>*n = new Node<type>(3);
	t->Insert(0,n);
	ASSERT_NO_THROW(t->Search(0));
}

TEST(ScanTable, can_Search_key_correct)
{
	Table<type> *t = new ScanTable<type>(12);
	Node<type>*n = new Node<type>(3);
	TabRecord<type>*n2 = new TabRecord<type>(0,n);
	Node<type>*n1 = new Node<type>(8);
	t->Insert(1,n1);
	t->Insert(0,n);
	TabRecord<type>*n3 = t->Search(0);
	EXPECT_EQ(n2->key, n3->key);
}

TEST(ScanTable, can_Delete_with_key)
{
	Table<type> *t = new ScanTable<type>(12);
	Node<type>*n = new Node<type>(3);
	t->Insert(0,n);
	ASSERT_NO_THROW(t->Delete(0));
}

TEST(ScanTable, can_Delete_with_key_correct)
{
	Table<type> *t = new ScanTable<type>(12);
	Node<type>*n = new Node<type>(3);
	TabRecord<type>*n2 = new TabRecord<type>(0,n);
	Node<type>*n1 = new Node<type>(8);
	t->Insert(1,n1);
	t->Insert(0,n);
	t->Delete(0);
	EXPECT_EQ(0, t->Search(0));
}

TEST(ScanTable, can_Insert_key)
{
	Table<type> *t = new ScanTable<type>(12);
	Node<type>*n1 = new Node<type>(8);
	ASSERT_NO_THROW(t->Insert(1,n1));	
}

TEST(ScanTable, in_Insert_key_cout_is_more)
{
	Table<type> *t = new ScanTable<type>(12);
	Node<type>*n1 = new Node<type>(8);
	t->Insert(1,n1);
	EXPECT_EQ(1,t->GetCount());	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
TEST(SortTable, can_create_sort_table)
{
	ASSERT_NO_THROW(SortTable<type> *t = new SortTable<type>);
}

TEST(SortTable, cant_create_sort_table_with_negative_size)
{
	ASSERT_ANY_THROW(SortTable<type> t(-3));
}

TEST(SortTable, can_GetSize)
{
	Table<type> *t = new SortTable<type>(12);
	ASSERT_NO_THROW(t->GetSize());
}

TEST(SortTable, can_GetSize_correct)
{
	Table<type> *t = new SortTable<type>(12);
	EXPECT_EQ(12,t->GetSize());
}

TEST(SortTable, can_IsEmpty)
{
	Table<type> *t = new SortTable<type>(12);
	ASSERT_NO_THROW(t->IsEmpty());
}

TEST(SortTable, IsEmpty_return_false_when_table_is_not_empty)
{
	Table<type> *t = new SortTable<type>(12);
	Node<type>* n = new Node<type>(5);
	t->Insert(0,n);
	EXPECT_EQ(0,t->IsEmpty());
}

TEST(SortTable, IsEmpty_return_true_when_table_is_empty)
{
	Table<type> *t = new SortTable<type>(1);
	EXPECT_EQ(1,t->IsEmpty());
}

TEST(SortTable, can_IsFull)
{
	Table<type> *t = new SortTable<type>(12);
	ASSERT_NO_THROW(t->IsFull());
}

TEST(SortTable, IsFull_return_false_when_table_is_not_full)
{
	Table<type> *t = new SortTable<type>(12);
	Node<type>* n = new Node<type>(8);
	t->Insert(0,n);
	EXPECT_EQ(0,t->IsFull());
}

TEST(SortTable, IsFull_return_true_when_table_is_full)
{
	Table<type> *t = new SortTable<type>(1);
	Node<type>* n = new Node<type>(8);
	t->Insert(0,n);
	EXPECT_EQ(1,t->IsFull());
}

TEST(SortTable, can_GetCount)
{
	Table<type> *t = new SortTable<type>(12);
	ASSERT_NO_THROW(t->GetCount());
}

TEST(SortTable, can_GetCount_correct)
{
	Table<type> *t = new SortTable<type>(12);
	Node<type>* n = new Node<type>(8);
	Node<type>* n1 = new Node<type>(81);
	t->Insert(0,n);
	t->Insert(1,n1);
	EXPECT_EQ(2,t->GetCount());
}

TEST(SortTable, can_Reset)
{
	Table<type> *t = new SortTable<type>(12);
	ASSERT_NO_THROW(t->Reset());
}

TEST(SortTable, can_GetNext)
{
	Table<type> *t = new SortTable<type>(12);
	ASSERT_NO_THROW(t->GetNext());
}

TEST(SortTable, GetNext_return_null_when_is_end_of_table)
{
	Table<type> *t = new SortTable<type>(12);
	EXPECT_EQ(0,t->GetNext());
}

TEST(SortTable, can_IsTablEnded)
{
	Table<type> *t = new SortTable<type>(12);
	ASSERT_NO_THROW(t->IsTablEnded());
}

TEST(SortTable, can_Search_key)
{
	Table<type> *t = new SortTable<type>(12);
	Node<type>*n = new Node<type>(3);
	t->Insert(0,n);
	ASSERT_NO_THROW(t->Search(0));
}

TEST(SortTable, can_Search_key_correct)
{
	Table<type> *t = new SortTable<type>(12);
	Node<type>*n = new Node<type>(3);
	TabRecord<type>*n2 = new TabRecord<type>(0,n);
	Node<type>*n1 = new Node<type>(8);
	t->Insert(1,n1);
	t->Insert(0,n);
	TabRecord<type>*n3 = t->Search(0);
	EXPECT_EQ(n2->key, n3->key);
}

TEST(SortTable, can_Insert_key)
{
	Table<type> *t = new SortTable<type>(12);
	Node<type>*n1 = new Node<type>(8);
	ASSERT_NO_THROW(t->Insert(1,n1));	
}

TEST(SortTable, in_Insert_key_cout_is_more)
{
	Table<type> *t = new SortTable<type>(12);
	Node<type>*n1 = new Node<type>(8);
	t->Insert(1,n1);
	EXPECT_EQ(1,t->GetCount());	
}

TEST(SortTable, can_Delete_with_key)
{
	Table<type> *t = new SortTable<type>(12);
	Node<type>*n = new Node<type>(3);
	t->Insert(0,n);
	ASSERT_NO_THROW(t->Delete(0));
}

TEST(SortTable, can_Delete_with_key_correct)
{
	Table<type> *t = new SortTable<type>(12);
	Node<type>*n = new Node<type>(3);
	TabRecord<type>*n2 = new TabRecord<type>(0,n);
	Node<type>*n1 = new Node<type>(8);
	t->Insert(1,n1);
	t->Insert(0,n);
	t->Delete(0);
	EXPECT_EQ(0, t->Search(0));
}
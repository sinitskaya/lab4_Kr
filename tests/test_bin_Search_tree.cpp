#include "bin_Search_tree.hpp"
#include <gtest.h>
typedef int type;
TEST(BSearchTree, can_create_bin_search_tree)
{
	ASSERT_NO_THROW(BSearchTree<type>(4));
}

TEST(BSearchTree, can_create_bin_search_tree_with_node)
{
	Node<type> *t4 = new Node<type>(10);
	ASSERT_NO_THROW(BSearchTree<type> *h = new BSearchTree<type>(t4));
}

/////////////////////////////////FindKey
TEST(BSearchTree, can_FindKey_in_bin_search_tree)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t3 = new Node<type>(34);
	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	tr->Insert(t1);
	tr->Insert(t3);
	ASSERT_NO_THROW(tr->FindKey(t4,1));
}

TEST(BSearchTree, can_FindKey_in_bin_search_tree_correct)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t3 = new Node<type>(34);
	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	tr->Insert(t1);
	tr->Insert(t3);
	Node<type> *t = tr->FindKey(t4,1);
	EXPECT_EQ(1,t->e.key);
}

TEST(BSearchTree, cannt_Find_not_exist_Key_in_bin_search)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t3 = new Node<type>(34);
	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	tr->Insert(t1);
	tr->Insert(t3);
	Node<type> *t = tr->FindKey(t4,9);
	EXPECT_EQ(0,t);
}
/////////////////////////////////////////////FindMin
TEST(BSearchTree, can_FindMin_in_bin_search_tree)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t3 = new Node<type>(34);
	Node<type> *t5 = new Node<type>(14);
	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	tr->Insert(t1);
	tr->Insert(t3);
	tr->Insert(t5);
	ASSERT_NO_THROW(tr->FindMin(t4));
}

TEST(BSearchTree, can_FindMin_in_bin_search_tree_correct)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t3 = new Node<type>(34);
	Node<type> *t5 = new Node<type>(14);
	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	tr->Insert(t1);
	tr->Insert(t3);
	tr->Insert(t5);
	Node<type> *t = tr->FindMin(t4);
	EXPECT_EQ(1,t->e.key);
}
/////////////////////////////////////////////FindMax
TEST(BSearchTree, can_FindMax_in_bin_search_tree)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t3 = new Node<type>(34);
	Node<type> *t5 = new Node<type>(14);
	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	tr->Insert(t1);
	tr->Insert(t3);
	tr->Insert(t5);
	ASSERT_NO_THROW(tr->FindMax(t4));
}

TEST(BSearchTree, can_FindMax_in_bin_search_tree_correct)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t3 = new Node<type>(34);
	Node<type> *t5 = new Node<type>(14);
	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	tr->Insert(t1);
	tr->Insert(t3);
	tr->Insert(t5);
	Node<type> *t = tr->FindMax(t4);
	EXPECT_EQ(34,t->e.key);
}
/////////////////////////////////////////////////FindNext
TEST(BSearchTree, can_FindNext_in_bin_search_tree)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t3 = new Node<type>(34);
	Node<type> *t5 = new Node<type>(14);
	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	tr->Insert(t1);
	tr->Insert(t3);
	tr->Insert(t5);
	ASSERT_NO_THROW(tr->FindNext(t4));
}

TEST(BSearchTree, can_FindNext_in_bin_search_tree_correct)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t3 = new Node<type>(34);
	Node<type> *t5 = new Node<type>(14);
	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	tr->Insert(t1);
	tr->Insert(t3);
	tr->Insert(t5);
	Node<type> *t = tr->FindNext(t4);
	EXPECT_EQ(14,t->e.key);
}

TEST(BSearchTree, when_not_exsist_next_elem_in_bin_search_tree)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t3 = new Node<type>(34);
	Node<type> *t5 = new Node<type>(14);
	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	tr->Insert(t1);
	tr->Insert(t3);
	tr->Insert(t5);
	Node<type> *t = tr->FindNext(t3);
	EXPECT_EQ(0,t);
}
//////////////////////////////////////////////////FindPred
TEST(BSearchTree, can_FindPred_in_bin_search_tree)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t3 = new Node<type>(34);
	Node<type> *t5 = new Node<type>(14);
	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	tr->Insert(t1);
	tr->Insert(t3);
	tr->Insert(t5);
	ASSERT_NO_THROW(tr->FindPred(t4));
}

TEST(BSearchTree, can_FindPred_in_bin_search_tree_correct)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t3 = new Node<type>(34);
	Node<type> *t5 = new Node<type>(14);
	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	tr->Insert(t1);
	tr->Insert(t3);
	tr->Insert(t5);
	Node<type> *t = tr->FindPred(t4);
	EXPECT_EQ(1,t->e.key);
}

TEST(BSearchTree, not_exsist_Pred_in_bin_search_tree)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t3 = new Node<type>(34);
	Node<type> *t5 = new Node<type>(14);
	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	tr->Insert(t1);
	tr->Insert(t3);
	tr->Insert(t5);
	Node<type> *t = tr->FindPred(t1);
	EXPECT_EQ(NULL,t);
}
/////////////////////////////////////////////////////Insert
TEST(BSearchTree, can_Insert_in_bin_search_tree)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);

	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	ASSERT_NO_THROW(tr->Insert(t1));
}

TEST(BSearchTree, Insert_less_elem_in_left_in_bin_search_tree_correct)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);

	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	tr->Insert(t1);

	EXPECT_EQ(t1,t4->left);
}

TEST(BSearchTree, Insert_more_elem_in_right_in_bin_search_tree_correct)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(14);

	BSearchTree<type> *tr = new BSearchTree<type> (t4);
	tr->Insert(t1);

	EXPECT_EQ(t1,t4->right);
}
////////////////////////////////////////////////Delete
TEST(BSearchTree, can_delete_bin_search_tree)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t2 = new Node<type>(14);
	Node<type> *t3 = new Node<type>(18);
	
	BSearchTree<type> *tr = new BSearchTree<type>(t4);
	tr->Insert(t1);
	tr->Insert(t2);
	tr->Insert(t3);
	ASSERT_NO_THROW(tr->Delete(t4, 14));
}

TEST(BSearchTree, can_delete_first_bin_search_tree)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t2 = new Node<type>(14);
	Node<type> *t3 = new Node<type>(18);
	
	BSearchTree<type> *tr = new BSearchTree<type>(t4);
	tr->Insert(t1);
	tr->Insert(t2);
	tr->Insert(t3);
	ASSERT_NO_THROW(tr->Delete(t4, 10));
}

TEST(BSearchTree, cannt_delete_with_null_point_in_bin_search_tree)
{
	Node<type> *t3 = 0;
	Node<type> *t1 = new Node<type>(10);
	BSearchTree<type> *tr = new BSearchTree<type>(t1);
	ASSERT_ANY_THROW(tr->Delete(t3, 10));
}

TEST(BSearchTree, can_Delete_root_in_bin_search_tree)
{
	Node<type> *t5 = new Node<type>(90);
	Node<type> *t4 = new Node<type>(6);
	Node<type> *t3 = new Node<type>(5);
	Node<type> *t2 = new Node<type>(1);
	Node<type> *t1 = new Node<type>(10);
	BSearchTree<type> *tr = new BSearchTree<type>(t1);
	tr->Insert(t2);
	tr->Insert(t3);
	tr->Insert(t4);
	tr->Insert(t5);
	ASSERT_NO_THROW(tr->Delete(t1,10));
}

TEST(BSearchTree, can_delete_root_in_DeleteRoot)
{
	Node<type> *t1 = new Node<type>(10);
	BSearchTree<type> *tr = new BSearchTree<type>(t1);
	ASSERT_NO_THROW(tr->DeleteRoot());
}

//////////////////////////////////////////////////////////GetNodeKey
TEST(BSearchTree, can_GetNodeKey_in_bin_search_tree)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t2 = new Node<type>(14);
	Node<type> *t3 = new Node<type>(18);
	BSearchTree<type> *tr = new BSearchTree<type>(t4);

	ASSERT_NO_THROW(tr->GetNodeKey(t4));
}

TEST(BSearchTree, can_GetNodeKey_in_bin_search_tree_correct)
{
	Node<type> *t4 = new Node<type>(10);
	Node<type> *t1 = new Node<type>(1);
	Node<type> *t2 = new Node<type>(14);
	Node<type> *t3 = new Node<type>(18);
	BSearchTree<type> *tr = new BSearchTree<type>(t4);

	EXPECT_EQ(10,tr->GetNodeKey(t4));
}